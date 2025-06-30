#include "App.hpp"

int main(int argc, char const *argv[])
{
    App app("SDL3 Test", 640, 480, SDL_INIT_VIDEO);

    app.run();

    return 0;
}
