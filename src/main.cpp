#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/actiongroup.h>
#include <gtkmm/action.h>
#include <gtkmm/menubar.h>

#include "main.hpp"

MainWindow::MainWindow()  
{
    m_title_bar.set_title("3DPainter");
    m_title_bar.add(m_menu);
    m_title_bar.set_show_close_button();


    m_menu.add("File/New");
    m_menu.add("File/Open");
    m_menu.add("File/Quit");

    m_main_layout.pack_start(m_viewport);

    add(m_main_layout);
    set_titlebar(m_title_bar);
    show_all();
}

int main(int argc, char *argv[]){
    std::cout << "Launching 3D Painter..." << std::endl;

    auto app = Gtk::Application::create(argc, argv, "3DPainter");

    MainWindow window;
    window.set_default_size(200,200);


    return app->run(window);
}