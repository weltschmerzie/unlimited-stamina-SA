/**
 * StaminaManager.cpp
 * 
 * Implementation of the StaminaManager class for handling unlimited stamina.
 */

#include "StaminaManager.h"
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
    // This is the most reliable method across all platforms
}

CPlayerPed* StaminaManager::GetPlayerPed() const {
    // In Plugin SDK, FindPlayerPed() returns a pointer to CPlayerPed
    // Just return the result directly and let caller check for nullptr
    return FindPlayerPed();
}

void StaminaManager::DrawNotification() const {
    // Notifications are disabled as per user request
} 