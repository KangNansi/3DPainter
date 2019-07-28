#pragma once

#include <gtkmm/menubar.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/menu.h>
#include <unordered_map>
#include <string>

class MenuBar : public Gtk::MenuBar
{
public:

    void add(std::string path);

protected:
    std::unordered_map<std::string, Gtk::MenuItem> m_menu_items;
    std::unordered_map<std::string, Gtk::Menu> m_menus;
};