#include "config.h"
#include <fstream>
#include <sstream>
#include <iostream>

Config* Config::instance = nullptr;

Config::Config() {}

Config& Config::getInstance() {
    if (!instance) {
        instance = new Config();
    }
    return *instance;
}

bool Config::loadConfig(const std::string& filename) {
    return parseConfigFile(filename);
}

bool Config::saveConfig(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return false;
    }

    for (const auto& pair : configMap) {
        outFile << pair.first << " = " << pair.second << std::endl;
    }

    outFile.close();
    return true;
}

std::string Config::getValue(const std::string& key) const {
    auto it = configMap.find(key);
    if (it != configMap.end()) {
        return it->second; // Key found, return the corresponding value
    }
    else {
        return ""; // Key not found, return an empty string (you can handle this case differently if needed)
    }
}

void Config::setValue(const std::string& key, const std::string& value) {
    configMap[key] = value;
}

bool Config::parseConfigFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            configMap[trim(key)] = trim(value);
        }
    }

    inFile.close();
    return true;
}

std::string Config::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    if (first == std::string::npos || last == std::string::npos) {
        return "";
    }
    return str.substr(first, last - first + 1);
}

void Config::generateDefaultConfig() {
    configMap["login_outlook"] = "ctdrtest@outlook.com";
    configMap["password_outlook"] = "Zxcadmin1";
    configMap["emailReceiveScheduleMilis"] = "45000";
    configMap["emailSendScheduleMilis"] = "15000";
}