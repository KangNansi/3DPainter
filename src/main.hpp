#pragma once

#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include "views/viewport.hpp"
#include <gtkmm/headerbar.h>
#include "widgets/menubar.hpp"

class MainWindow : public Gtk::Window {
public:
    MainWindow();

protected:
    Gtk::Label m_label;
    Viewport m_viewport;

    Gtk::VBox m_main_layout;
    Gtk::HeaderBar m_title_bar;
    MenuBar m_menu;
};