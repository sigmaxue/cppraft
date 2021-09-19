//
// Copyright (c) 2021 Sigmaxue. All rights reserved.
//

#include <unistd.h>
#include <iostream>
#include <string>

#include <ananas/net/Application.h>
#include <ananas/util/Logger.h>
#include <fmt/include/fmt/core.h>
#include <yaml-cpp/yaml.h>

#include "global_var.h"

void OnNewConnection(ananas::Connection* conn) {
    std::cout << "OnNewConnection " << conn << std::endl;
}

bool Init(int argc, char* argv[]) {
    auto& app = ananas::Application::Instance();
    app.Listen("loopback", g_cmd.get<int>("port"), OnNewConnection);
    return true;
}

void BeforeStart() {
    try {
        YAML::Node config = YAML::LoadFile("config.yaml");
        std::cout << "name:" << config["name"].as<std::string>() << std::endl;
        std::cout << "sex:" << config["sex"].as<std::string>() << std::endl;
        std::cout << "age:" << config["age"].as<int>() << std::endl;
        for (YAML::const_iterator it = config["skills"].begin();
             it != config["skills"].end(); ++it) {
            fmt::print("{}:{}\n", it->first.as<std::string>(),
                       it->second.as<int>());
        }
        if (!config["no"].IsDefined()) {
            fmt::print("config key not exist!\n");
        }
    } catch (...) {
        fmt::print("config error!\n");
    }
}

void AppStart(int argc, char* argv[]) {
    ananas::LogManager::Instance().Start();
    std::shared_ptr<ananas::Logger> logger;
    logger = ananas::LogManager::Instance().CreateLog(logALL, logALL,
                                                      "logger_server_test");
    auto& app = ananas::Application::Instance();
    app.SetOnInit(Init);

    app.Run(argc, argv);
}

int main(int argc, char* argv[]) {
    g_cmd.add<int>("port", 'p', "port number", false, 6379,
                   cmdline::range(1, 65535));
    g_cmd.parse_check(argc, argv);

    BeforeStart();

    AppStart(argc, argv);

    return 0;
}
