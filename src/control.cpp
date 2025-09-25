//
// Created by nam on 25.09.2025.
//

#include "control.h"

int execute_command(
    std::vector<std::string> packages
) {
    std::string operation;

    if (update) {
        // update_func()
        // TODO: insert actual update function (update repository)
    }
    if (upgrade) {
        // upgrade_func()
        // TODO: insert actual upgrade function
        // TODO: (push packages that need updates for to the list of packages)
    }
    if (install) {
        // install_func()
        // TODO: insert the actual install function (self-explanatory)
    }
    if (rm) {
        // remove_func()
        // TODO: insert the actual remove function
    }
    if (query) {
        // query_func()
        // okay you get it
    }
    if (install && rm) {
        // install_func()
        // remove_func()
        // So okay, amapekibert asked for this. I do not really know why
        // fine
    }



    return 0;
}
