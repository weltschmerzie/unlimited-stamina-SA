/**
 * StaminaManager.cpp
 * 
 * Implementation of the StaminaManager class for handling unlimited stamina.
 */

#include "StaminaManager.h"
#include <CMessages.h>
#include <CHud.h>
#include <CText.h>
#include <CPad.h>
#include <CStats.h>

StaminaManager::StaminaManager() :
    m_enableUnlimitedStamina(true),
    m_staminaRestoreRate(DEFAULT_RESTORE_RATE)
{
}

void StaminaManager::Initialize() {
    // Reset to default values
    m_enableUnlimitedStamina = true;
    m_staminaRestoreRate = DEFAULT_RESTORE_RATE;
    
    // Log initialization message
    CMessages::AddMessageJumpQ("Unlimited Stamina Mod: Initialized", 3000, 0, false);
}

void StaminaManager::Process() {
    if (m_enableUnlimitedStamina) {
        UpdatePlayerStamina();
    }
}

void StaminaManager::UpdatePlayerStamina() {
    // Get player ped
    CPlayerPed* playerPed = GetPlayerPed();
    if (!playerPed) {
        return;
    }

    // Method 1: Set player's stamina stat to maximum
    // This will increase the overall stamina capacity
    CStats::SetStatValue(STAT_STAMINA, MAX_STAMINA);
    
    // Method 2: Prevent stamina from decreasing
    // We do this by continuously setting the stat value
    // This is the most reliable method across all SDK versions
    
    // Method 3: Modify fatigue directly if possible in the future
    // This would require access to internal game structures
    // For now, method 1 is reliable enough to ensure unlimited stamina
}

CPlayerPed* StaminaManager::GetPlayerPed() const {
    // In Plugin SDK, FindPlayerPed() returns a pointer to CPlayerPed
    // Just return the result directly and let caller check for nullptr
    return FindPlayerPed();
}

void StaminaManager::DrawNotification() const {
    // Simply use CMessages to show the notification
    // This is more compatible with all SDK versions
    CMessages::AddMessageJumpQ("~g~Unlimited Stamina Activated", 3000, 0, false);
} 