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

bool Config::loadConfig() {
    return parseConfigFile(this->configFileName);
}

bool Config::saveConfig() {
    std::ofstream outFile(this->configFileName);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << this->configFileName << std::endl;
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

std::map<std::string, std::string> Config::getConfigMap() const
{
    return this->configMap;
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
    configMap["emailReceiveScheduleMilis"] = "45000";
    configMap["emailSendScheduleMilis"] = "15000";
    configMap["recentlyReceivedMailsCount"] = "10";
}