/**
 * Config.cpp
 * 
 * Implementation of the Config class for the Unlimited Stamina plugin.
 * Uses mINI library for INI file handling.
 */

#include "Config.h"

// Initialize static members
Config* Config::s_instance = nullptr;
const std::string Config::CONFIG_FILE_NAME = "unlimited-stamina.ini";

Config::Config() :
    m_enableUnlimitedStamina(true),
    m_iniFile(CONFIG_FILE_NAME)
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
    // Try to read from existing ini file
    bool fileExists = m_iniFile.read(m_ini);
    
    // If file doesn't exist or couldn't be read, use default values
    if (!fileExists) {
        m_enableUnlimitedStamina = true;
        Save();
        return;
    }
    
    // Read values from ini structure using get() method
    if (m_ini.has("Settings") && m_ini.get("Settings").has("EnableUnlimitedStamina")) {
        std::string enabledStr = m_ini.get("Settings").get("EnableUnlimitedStamina");
        m_enableUnlimitedStamina = (enabledStr == "true" || enabledStr == "1" || enabledStr == "yes");
    } else {
        // Key doesn't exist, use default
        m_enableUnlimitedStamina = true;
    }
}

void Config::Save() const {
    // Create a mutable copy of the INI structure for modification
    mINI::INIStructure iniCopy = m_ini;
    
    // Update values in the Settings section
    iniCopy["Settings"]["EnableUnlimitedStamina"] = m_enableUnlimitedStamina ? "true" : "false";
    
    // Add comments
    iniCopy["Settings"][";Unlimited Stamina Plugin Configuration"] = "";
    iniCopy["Settings"][";Set EnableUnlimitedStamina=true to enable unlimited stamina"] = "";
    iniCopy["Settings"][";Set EnableUnlimitedStamina=false to disable unlimited stamina"] = "";
    
    // Write to file using the copy
    m_iniFile.write(iniCopy, true);  // true for pretty formatting
} 