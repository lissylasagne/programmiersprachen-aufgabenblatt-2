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

    auto t = win.get_time();
    const float pi = M_PI;

    float x1{400 + 380 * std::sin(-t/9.55f + pi)};
    float y1{400 + 380 * std::cos(-t/9.55f + pi)};

    float x2{400 + 380 * std::sin(-t/573.0f + pi)};
    float y2{400 + 380 * std::cos(-t/573.0f + pi)};

    float x3{400 + 380 * std::sin(-t/34380.0f + pi)};
    float y3{400 + 380 * std::cos(-t/34380.0f + pi)};


    std::string text = "Time since start: " + std::to_string(t);
    win.draw_text(10, 5, 35.0f, text);
    
    Circle cir(390.0, Vec2(400.0, 400.0), Color(0.2, 0.8, 0.2));
    cir.draw(win);
    win.draw_line(400.0, 400.0, x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_line(400.0, 400.0, x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_line(400.0, 400.0, x3, y3, 0.0f, 0.0f, 1.0f);

    win.update();
  }

  return 0;
}
