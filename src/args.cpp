//
// Created by nam on 25.09.2025.
//

#include "args.h"

#include <format>
#include <iostream>
#include <ostream>

std::vector<std::string> parse_flag_chunks(
    std::unordered_map<std::string, int> args,
    const std::string &chunk
) {
    std::vector<std::string> found;
    char prefix = chunk[0];
    // if (chunk.size() > 1 && chunk[1] == prefix) {
    // WE DON'T NEED THIS. OUR PROGRAM DOES NOT USE -- FLAGS
    // AND EVEN IF IT WOULD IT DOESN'T NEED THIS BIG ASS CHUNK OF CODE
    //     // parse as long flag
    //     if (const auto s = args.find(chunk); s != args.end()) {
    //         found.push_back(chunk);
    //         return found;
    //     }
    //     return found;
    // }
    // filter out other elements
    erase_if(args, [&](const auto& item){
        return item.first[0] != prefix;
    });
    // compare chunk characters with hashmap key characters
    for (int i=1; i<chunk.size(); i++) {
        std::string key = std::string(1, prefix) + chunk[i];
        if (auto s = args.find(chunk); s != args.end()) { // so here we match EXACT arguments (positional)
            found.push_back(chunk);
            break;
        }
        if (auto s_key = args.find(key); s_key != args.end() && s_key->first[1] != prefix) {
            found.push_back(key);
        } else {
            found.push_back(chunk); // package argument
            break; // fixes a silly bug
        }
        // but here we use the short flags
    }

    return found;
}

void initialize_args() {
    args["-S"]      =           INSTALL;
    args["-i"]      =           INSTALL;
    args["install"] =           INSTALL;
    args["in"]      =           INSTALL;
    args["add"]     =           INSTALL;

    args["-R"]      =           REMOVE;
    args["-d"]      =           REMOVE;
    args["remove"]  =           REMOVE;
    args["delete"]  =           REMOVE;
    args["del"]     =           REMOVE;
    args["rm"]      =           REMOVE;
    args["rem"]     =           REMOVE;

    args["-y"]      =           UPDATE;
    args["update"]  =           UPDATE;
    args["upd"]     =           UPDATE;

    args["-u"]      =           UPGRADE;
    args["upgrade"] =           UPGRADE;
    args["upg"]     =           UPGRADE;

    args["-Q"]      =           QUERY;
    args["query"]   =           QUERY;

    args["-s"]      =           SEARCH;

    args["-h"]      =           HELP;
    args["help"]    =           HELP;
    args["--help"]  =           HELP;
}

void print_usage() {
    std::cerr << "\x1b[36;1mUsage:\x1b[0m" << std::endl;
    std::cerr << "\x1b[1mupm [install/remove/query] [options] <packages>\n" << std::endl;
}

void print_unknown_error() {
    std::cerr << "\x1b[31;1mUnknown error has occurred." << std::endl;
}

void print_help() {
    print_usage();
    std::cerr <<
        "\x1b[1m"
        "\t-S/-i/install/add\t\x1b[36mInstall a package\x1b[39m\n"
        "\t-R/-d/remove/delete\t\x1b[36mUninstall a package\x1b[39m\n"
        "\t-y/update\t\t\x1b[36mUpdate local repository\x1b[39m\n"
        "\t-u/upgrade\t\t\x1b[36mPerform a system upgrade\x1b[39m\n"
        "\t-Q/query\t\t\x1b[36mQuery a package installed\x1b[39m\n"
        "\t-s\t\t\t\x1b[36mOnly used with -Q; Query the repository instead\x1b[39m\n"
        "\t-h/help\t\t\t\x1b[36mPrint this help message.\x1b[0m" << std::endl;
}

void parse_args(const int argc, char **argv) {
    initialize_args();
    std::vector<std::string> parsed_arguments;
    // we parse chunks as different flags, thus making parsing process easier
    // taking some extra resources, but I don't care really - namnam1105 25.09.25
    if (argc < 2) {
        print_help();
        return;
    }
    for (int i=1; i<argc; i++) {
        std::string arg = argv[i];
        auto parsedVec = parse_flag_chunks(args, arg);
        parsed_arguments.insert(
            parsed_arguments.end(),
            parsedVec.begin(),
            parsedVec.end()
        );
    }
    std::vector<std::string> packages;
    for (const auto & parsed_argument : parsed_arguments) {
        switch (args[parsed_argument]) {
            case INSTALL:
                install = true;
                break;
            case REMOVE:
                rm = true;
                break;
            case UPDATE:
                update = true;
                break;
            case QUERY:
                query = true;
                break;
            case UPGRADE:
                upgrade = true;
                break;
            case SEARCH:
                search = true;
                break;
            case HELP:
                print_help();
                return;
            default:
                // assuming it's an argument for packages.
                if (install || rm || query) {
                    packages.push_back(parsed_argument);
                }
                break;
        }
    }
    std::cout << packages.size() << std::endl;
    if ((install && query) || (install && search) || (query && rm) || (rm && search) || (query && upgrade)) {
        std::cerr << "\x1b[1;31mError: \x1b[39;1mbad arguments\n" << std::endl;
        std::cerr << "Prohibited combinations:" << std::endl;
        std::cerr << "\x1b[31minstall + query\ninstall + search\nquery + remove\nremove + search\nquery + upgrade\x1b[0m" << std::endl;
        std::cerr << "\x1b[1mUse help or -h to find more information";
    }
}