#pragma once

#include "layer.hpp"

namespace Flugel {
  class AppLayer : public Layer {
  public:
    AppLayer(const Time* time)
      : Layer{"App Layer"}, time_{time} {}
  private:
    const Time* time_;
    glm::vec2 windowDragOffset_; // cursor position at time of clicking to drag window
    bool draggingWindowDecor_{false};
    bool closingWindowDecor_{false};
      
    virtual void render() override;
    
    virtual bool onWindowEvent(WindowEvent& e) override;
    virtual bool onKeyboardEvent(KeyboardEvent& e) override;
    virtual bool onMouseEvent(MouseEvent& e) override;
    virtual bool onCursorEvent(CursorEvent& e) override;
    virtual bool onScrollEvent(ScrollEvent& e) override;

    void pollCustomDecor(MouseEvent& e);
  };
}