#include "nd/nd.h"

class GameState: public NState {
public:
    virtual void create();
    virtual void update(float dt);
};
