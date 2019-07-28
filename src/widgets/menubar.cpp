#include "menubar.hpp"
#include <vector>
#include <iostream>


void MenuBar::add(std::string path){
    int last = -1;
    int next = -1;

    int length = path.length();

    for(int i = 0; i <= length; i++){
        if(path[i] == '/' || path[i] == '\\' || i == length){
            last = next;
            next = i;

            std::string key = path.substr(0, next);
            std::string label = path.substr(last+1, next);

            std::cout << "Creating key " << key << " with label " << label << std::endl;

            // Check if already exists
            auto item_iterator = m_menu_items.find(key);
            if(item_iterator == m_menu_items.end()){
                Gtk::MenuItem& item = m_menu_items[key];

                item.set_label(label);

                if(last == -1){
                    append(item);
                }
                else{
                    std::string parent_key = path.substr(0, last);
                    std::cout << "Append to parent " << parent_key << std::endl;
                    m_menus[parent_key].append(item);
                }

                // Key is a submenu
                if(i != length){
                    auto& submenu = m_menus[key];
                    item.set_submenu(submenu);
                }
            }
        }
    }
}