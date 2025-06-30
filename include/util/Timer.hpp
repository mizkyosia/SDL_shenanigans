#pragma once
#include <SDL3/SDL.h>

struct Timer
{
    float length, current;
    bool paused, autoReset;

    Timer(float length, bool autoReset = true) : length(length), current(0.0f), paused(false), autoReset(autoReset) {}

    bool update(float delta)
    {
        if (!paused)
            current += delta;
        if (current >= length)
        {
            if (autoReset)
                current = 0;
            return true;
        }
        return false;
    }

    void reset()
    {
        paused = false;
        current = 0;
    }
};
