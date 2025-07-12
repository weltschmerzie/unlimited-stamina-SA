/**
 * Config.cpp
 * 
 * Implementation of the Config class for the Unlimited Stamina plugin.
 */

#include "Config.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <CFileMgr.h>

// Initialize static members
Config* Config::s_instance = nullptr;
const std::string Config::CONFIG_FILE_NAME = "unlimited-stamina.ini";

Config::Config() :
    m_enableUnlimitedStamina(true),
    m_showNotifications(true)
{
    // Constructor initializes with default values
    // Actual values will be loaded from ini file if available
}

Config& Config::GetInstance() {
    if (!s_instance) {
        s_instance = new Config();
        s_instance->Load();
    }
    return *s_instance;
}

void Config::Load() {
    // Clear settings map
    m_settings.clear();
    
    // Set defaults
    m_enableUnlimitedStamina = true;
    m_showNotifications = true;
    
    // Open file for reading
    std::ifstream file(CONFIG_FILE_NAME);
    if (!file.is_open()) {
        // File doesn't exist, create with default values
        Save();
        return;
    }

    // Read file line by line
    std::string line;
    while (std::getline(file, line)) {
        ParseLine(line);
    }
    file.close();
    
    // Apply settings from map
    auto it = m_settings.find("EnableUnlimitedStamina");
    if (it != m_settings.end()) {
        m_enableUnlimitedStamina = ToBool(it->second);
    }
    
    it = m_settings.find("ShowNotifications");
    if (it != m_settings.end()) {
        m_showNotifications = ToBool(it->second);
    }
}

void Config::Save() const {
    // Create or open ini file
    std::ofstream file(CONFIG_FILE_NAME);
    if (!file.is_open()) {
        return;
    }
    
    // Write header
    file << "# Unlimited Stamina Plugin Configuration" << std::endl;
    file << "[Settings]" << std::endl;
    
    // Write settings
    file << "EnableUnlimitedStamina=" << ToString(m_enableUnlimitedStamina) << std::endl;
    file << "ShowNotifications=" << ToString(m_showNotifications) << std::endl;
    
    // Close file
    file.close();
}

void Config::ParseLine(const std::string& line) {
    // Skip comments and empty lines
    if (line.empty() || line[0] == '#' || line[0] == '[') {
        return;
    }
    
    // Find key-value separator
    size_t pos = line.find('=');
    if (pos == std::string::npos) {
        return;
    }
    
    // Extract key and value
    std::string key = line.substr(0, pos);
    std::string value = line.substr(pos + 1);
    
    // Store in map
    m_settings[key] = value;
}

std::string Config::ToString(bool value) const {
    return value ? "true" : "false";
}

bool Config::ToBool(const std::string& value) const {
    return value == "true" || value == "1" || value == "yes";
} 