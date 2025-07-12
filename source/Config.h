#pragma once

/**
 * Config.h
 * 
 * Configuration management for the Unlimited Stamina plugin.
 * Handles loading and saving of configuration settings.
 */

#include <string>
#include <fstream>
#include <map>

class Config {
private:
    // Config file path
    static const std::string CONFIG_FILE_NAME;
    
    // Settings map
    std::map<std::string, std::string> m_settings;
    
    // Settings
    bool m_enableUnlimitedStamina;
    bool m_showNotifications;
    
    // Singleton instance
    static Config* s_instance;
    
    // Private constructor for singleton
    Config();
    
    // Helper methods for parsing
    void ParseLine(const std::string& line);
    std::string ToString(bool value) const;
    bool ToBool(const std::string& value) const;

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
    
    bool ShowNotifications() const { return m_showNotifications; }
    void SetShowNotifications(bool show) { m_showNotifications = show; }
}; 