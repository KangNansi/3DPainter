#pragma once

#include <gtkmm/glarea.h>
#include <GL/gl.h>

class Viewport : public Gtk::GLArea
{
protected:
    virtual bool on_render(const Glib::RefPtr<Gdk::GLContext>& context) override;
};
