#include "nd/nd.h"
#include <memory>

int main(int argc, char *argv[])
{
    std::unique_ptr<NGame> game(new NGame());

    return 0;
}
