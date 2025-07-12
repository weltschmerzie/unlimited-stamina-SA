#pragma once

/**
 * StaminaManager.h
 * 
 * Manages the player's stamina and provides functionality
 * for maintaining infinite stamina regardless of game conditions.
 */

#include <plugin.h>
#include <CPlayerPed.h>
#include <CStats.h>
#include <CFont.h>

class StaminaManager {
private:
    // Constants
    static constexpr float MAX_STAMINA = 1000.0f;
    static constexpr float DEFAULT_RESTORE_RATE = 5.0f;
    
    // Configuration
    bool m_enableUnlimitedStamina;
    float m_staminaRestoreRate;
    
    // Helper methods
    CPlayerPed* GetPlayerPed() const;
    void UpdatePlayerStamina();
    
public:
    StaminaManager();
    ~StaminaManager() = default;
    
    /**
     * Initialize the StaminaManager
     * Sets up initial values and configuration
     */
    void Initialize();
    
    /**
     * Process function called every game frame
     * Handles the main stamina logic
     */
    void Process();
    
    /**
     * Draws the notification text on screen
     * Shows that the unlimited stamina mod is active
     */
    void DrawNotification() const;
    
    // Getters and setters
    bool IsUnlimitedStaminaEnabled() const { return m_enableUnlimitedStamina; }
    void SetUnlimitedStamina(bool enable) { m_enableUnlimitedStamina = enable; }
    void SetStaminaRestoreRate(float rate) { m_staminaRestoreRate = rate; }
}; 