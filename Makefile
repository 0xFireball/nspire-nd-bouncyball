PRG_NAME = bouncyball

DEBUG = FALSE
XPLAT_TARGET=nspire

$(info Building for xplat target [${XPLAT_TARGET}])

ifeq ($(XPLAT_TARGET), nspire)
GCC = nspire-gcc
AS  = nspire-as
GXX = nspire-g++
LD  = nspire-ld
GENZEHN = genzehn
else
GCC = gcc
AS = as
GXX = g++
LD = ld
endif

CFLAGS = -Wall -W --std=c++14
LDFLAGS =
ZEHNFLAGS = --name $(PRG_NAME)

ifeq ($(XPLAT_TARGET), nspire)
	CFLAGS += -marm -Dnspire
else ifeq ($(XPLAT_TARGET), desktop)
	CFLAGS += -Ddesktop -lSDL
endif

ifeq ($(DEBUG),FALSE)
	CFLAGS += -Os
else
	CFLAGS += -O0 -g
endif

OBJS = $(patsubst %.c, %.o, $(shell find . -name \*.c))
OBJS += $(patsubst %.cpp, %.o, $(shell find . -name \*.cpp))
OBJS += $(patsubst %.S, %.o, $(shell find . -name \*.S))
EXE = $(PRG_NAME)
DISTDIR = .
vpath %.tns $(DISTDIR)
vpath %.elf $(DISTDIR)
vpath %.bin $(DISTDIR)

desktop: $(EXE).bin
nspire: $(EXE).prg.tns

ifeq ($(XPLAT_TARGET), nspire)

$(EXE).tns: $(EXE).elf
	$(GENZEHN) --input $(DISTDIR)/$^ --output $(DISTDIR)/$@ $(ZEHNFLAGS)

$(EXE).prg.tns: $(EXE).tns
	make-prg $(DISTDIR)/$^ $(DISTDIR)/$@

%.o: %.c
	$(GCC) $(CFLAGS) -c $<

%.o: %.cpp
	$(GXX) $(CFLAGS) -c $<
	
%.o: %.S
	$(AS) -c $<

$(EXE).elf: $(OBJS)
	mkdir -p $(DISTDIR)
	$(LD) $^ -o $(DISTDIR)/$@ $(LDFLAGS)

else ifeq ($(XPLAT_TARGET), desktop)
CXXFILES = $(shell find . -name \*.cpp)
$(info Compile: [${GXX} ${CFLAGS}])
$(EXE).bin: $(CXXFILES)
	mkdir -p $(DISTDIR)
	$(GXX) $(CFLAGS) $(CXXFILES) -o $(DISTDIR)/$(EXE).bin

endif

clean:
	rm -f *.o $(DISTDIR)/$(EXE).tns $(DISTDIR)/$(EXE).elf $(DISTDIR)/$(EXE).bin $(DISTDIR)/$(EXE).prg.tns
