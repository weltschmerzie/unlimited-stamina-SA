#pragma once

/**
 * Config.h
 * 
 * Configuration management for the Unlimited Stamina plugin.
 * Handles loading and saving of configuration settings.
 * Uses mINI library for INI file handling.
 */

#include "../external/mINI/src/mini/ini.h"
#include <string>

class Config {
private:
    // Config file path
    static const std::string CONFIG_FILE_NAME;
    
    // Settings
    bool m_enableUnlimitedStamina;
    
    // mINI objects
    mutable mINI::INIFile m_iniFile;
    mINI::INIStructure m_ini;
    
    // Singleton instance
    static Config* s_instance;
    
    // Private constructor for singleton
    Config();

public:
    /**
     * Get the singleton instance
     */
    static Config& GetInstance();
    
    /**
     * Load configuration from INI file
     */
    void Load();
    
    /**
     * Save configuration to INI file
     */
    void Save() const;
    
    // Getters and setters
    bool IsUnlimitedStaminaEnabled() const { return m_enableUnlimitedStamina; }
    void SetUnlimitedStamina(bool enable) { m_enableUnlimitedStamina = enable; }
}; 