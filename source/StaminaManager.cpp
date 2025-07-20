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
    
    // Method 2: Prevent stamina from decreasing while running
    // This is the critical part for unlimited running stamina
    
    // Directly modify the specific memory addresses for player stamina
    // This approach is more reliable and works across all platforms
    float* playerRunSpeedPtr = (float*)(0xB7CDB4); // Player run speed multiplier
    float* sprintEnergyPtr = (float*)(0xB7CDB0);   // Sprint energy level
    
    // Set sprint energy to maximum (prevents stamina from depleting)
    if (sprintEnergyPtr) {
        *sprintEnergyPtr = 100.0f;
    }
    
    // Set run speed multiplier to maximum
    if (playerRunSpeedPtr) {
        *playerRunSpeedPtr = 1.0f; // Full run speed
    }
}

CPlayerPed* StaminaManager::GetPlayerPed() const {
    // In Plugin SDK, FindPlayerPed() returns a pointer to CPlayerPed
    // Just return the result directly and let caller check for nullptr
    return FindPlayerPed();
}

void StaminaManager::DrawNotification() const {
    // Notifications are disabled as per user request
} 