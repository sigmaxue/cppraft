//
// Copyright (c) 2021 Sigmaxue. All rights reserved.
//

#include <yaml-cpp/yaml.h>

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    try {
        YAML::Node config = YAML::LoadFile("config.yaml");
        std::cout << "name:" << config["name"].as<std::string>() << std::endl;
        std::cout << "sex:" << config["sex"].as<std::string>() << std::endl;
        std::cout << "age:" << config["age"].as<int>() << std::endl;
        for (YAML::const_iterator it = config["skills"].begin();
             it != config["skills"].end(); ++it) {
            std::cout << it->first.as<std::string>() << ":"
                      << it->second.as<int>() << std::endl;
        }
        if (!config["no"].IsDefined()) {
            std::cout << "config key not exist" << std::endl;
        }
    } catch (...) {
        std::cout << "catch" << std::endl;
    }

    return 0;
}
