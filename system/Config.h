#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>

class Config {
public:
    static Config& getInstance();  // Singleton instance getter

    bool loadConfig(const std::string& filename);  // Load configuration from file
    bool saveConfig(const std::string& filename);  // Save configuration to file

    std::string getValue(const std::string& key) const;  // Get value for a key
    void setValue(const std::string& key, const std::string& value);  // Set value for a key

    void generateDefaultConfig();  // Generate default configuration values

private:
    Config();  // Private constructor for singleton
    Config(const Config&) = delete;  // Disable copy constructor
    Config& operator=(const Config&) = delete;  // Disable assignment operator

    std::map<std::string, std::string> configMap;  // Key-value map for configuration

    bool parseConfigFile(const std::string& filename);  // Parse configuration file

    static std::string trim(const std::string& str);  // Trim leading and trailing whitespace

    static Config* instance;  // Singleton instance pointer
};

#endif // CONFIG_H