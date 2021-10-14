#pragma once

#include "core/window/window.hpp"
#include "core/callbacks/events/event.hpp"
#include "util/color/color.hpp"

#include <SDL2/SDL.h>

namespace fge {
  class Sdl2Window : public Window {
  public:
    Sdl2Window(const WindowProperties& props);
    virtual ~Sdl2Window();
    
    virtual void pollEvents() override;
    virtual void render() override;
    
    virtual void* nativeWindow() override { return sdl2Window_; }
    virtual void dragWindow(vector2_t windowCursorOffset);

    virtual void setIcon(uint8_t* image, int32_t width, int32_t height) override;
    virtual void setPos(double xPos, double yPos) override;
    virtual void setVSync(bool enabled) override;
    virtual void setFullscreen(bool enabled) override;
    virtual void setContextCurrent(bool current) override;
    
  private:
    SDL_Window* sdl2Window_;
    SDL_GLContext sdl2Context_;
    const std::string dataPtrName_ = "data";
    SDL_Surface* icon_;
    uint8_t* iconPixels_;
    
    Color clearColor_{0x2D2A2AFF};
    
    void init();
    void setCallbacks();
    void shutdown();
  };
}