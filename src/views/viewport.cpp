#include "viewport.hpp"

bool Viewport::on_render(const Glib::RefPtr<Gdk::GLContext>& context){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}