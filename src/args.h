//
// Created by nam on 25.09.2025.
//

#ifndef UPM_ARGS_H
#define UPM_ARGS_H

#include <vector>
#include <unordered_map>
#include <string>
#include <format>
#include <iostream>
#include <ostream>
#include "control.h"

std::vector<std::string> parse_flag_chunks(std::unordered_map<std::string, int> args, const std::string &chunk);

enum Args {
    NONE,
    INSTALL,
    REMOVE,
    QUERY,
    SEARCH,
    UPDATE,
    UPGRADE,
    HELP
};

inline bool install = false;
inline bool rm = false;
inline bool query = false;
inline bool search = false;
inline bool update = false;
inline bool upgrade = false;

int parse_args(int argc, char **argv);

inline std::unordered_map<std::string, int> args;

#endif //UPM_ARGS_H