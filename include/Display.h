#pragma once

#include <cstdint>

class Window;

class Display
{
private:
    uint32_t _width { 0 };
    uint32_t _height { 0 };

public:
    Display() = default;
    Display(uint32_t width, uint32_t height);

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