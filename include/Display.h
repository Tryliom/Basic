#pragma once

#include <cstdint>

class Window;

class Display
{

public:
    Display() = default;

    void Init(Window& window);
    /**
     * @brief Initialize the display, called once
     * @param window
     */
    virtual void OnStart(Window& window);
    virtual void Update(Window& window);
    virtual void Draw(Window& window);

    //TODO: Manage buttons and UI elements
};