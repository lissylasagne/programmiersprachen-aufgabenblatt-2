#include "window.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    //circle and rectangles for drawing
    Circle cirA(50.0, Vec2(250.0, 250.0), Color(1.0, 0.0, 0.0));
    Rectangle recA(Vec2(20.0, 20.0), Vec2(100.0, 200.0), Color(0.2, 0.8, 0.2));
    
    Circle cirB(150.0, Vec2(500.0, 500.0), Color(0.0, 0.0, 1.0));
    Rectangle recB(Vec2(200.0, 400.0), Vec2(500.0, 500.0), Color(0.2, 0.8, 0.2));

    win.draw_point(x1, y1,
        1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }
    //if mouse position is inside rectangle
    if(recA.is_inside(Vec2(m.first, m.second)) == true) {
        recA.setColor(Color(0.0, 0.0, 1.0));
    }

    if(recB.is_inside(Vec2(m.first, m.second)) == true) {
        recB.draw(win, Color(0.0, 0.0, 1.0));
    } else {
        recB.draw(win, Color(0.2, 0.8, 0.8));
    }

    //if mouse position is inside circle
    if(cirA.is_inside(Vec2(m.first, m.second)) == true) {
        cirA.setColor(Color(0.0, 0.0, 1.0));
    }

    if(cirB.is_inside(Vec2(m.first, m.second)) == true) {
        cirB.draw(win, Color(0.0, 0.0, 1.0));
    } else {
        cirB.draw(win, Color(0.5, 0.5, 0.5));
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);

    //drawing functions
    cirA.draw(win);
    recA.draw(win);
    

    win.update();
  }

  return 0;
}
