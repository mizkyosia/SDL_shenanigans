#include "App.hpp"
#include <iostream>

App::App(const char *title, int width, int height, Uint32 initFlags)
{
    SDL_Init(initFlags);

    _window = SDL_CreateWindow(title, width, height, 0);
    _renderer = SDL_CreateRenderer(_window, NULL);
}

App::~App()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);

    SDL_Quit();
}

void App::run()
{
    _scene.load(_renderer);

    loop();
}

void App::loop()
{
    bool quit = false;
    SDL_Event e;

    Uint64 previousTicks = SDL_GetTicks();

    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
                quit = true;

            // Apply event to scene
            _scene.onEvent(e);
        }

        // Calculate delta time
        Uint64 currentTicks = SDL_GetTicks();
        float deltaTime = (float)(currentTicks - previousTicks) / 1000.f;
        previousTicks = currentTicks;

        // Update scene
        _scene.update(deltaTime);

        SDL_RenderClear(_renderer);

        // Render scenes here !
        _scene.draw(_renderer);

        SDL_RenderPresent(_renderer);
    }
}