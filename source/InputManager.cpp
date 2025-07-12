/**
 * InputManager.cpp
 * 
 * Implementation of the InputManager class for the Unlimited Stamina plugin.
 */

#include "InputManager.h"
#include <CMessages.h>
#include <common.h>

InputManager::InputManager() : m_lastPressTime(0) {
    // Initialize key states
    memset(m_keyStates, 0, sizeof(m_keyStates));
}

bool InputManager::IsKeyPressed(int keyCode) const {
    return (GetAsyncKeyState(keyCode) & 0x8000) != 0;
}

bool InputManager::IsKeyJustPressed(int keyCode) {
    bool currentState = IsKeyPressed(keyCode);
    bool result = currentState && !m_keyStates[keyCode];
    m_keyStates[keyCode] = currentState;
    
    // Check cooldown
    if (result) {
        int currentTime = CTimer::m_snTimeInMilliseconds;
        if (currentTime - m_lastPressTime < KEY_COOLDOWN_MS) {
            return false;
        }
        m_lastPressTime = currentTime;
    }
    
    return result;
}

void InputManager::Process() {
    // Get the config instance
    Config& config = Config::GetInstance();
    
    // Toggle unlimited stamina (F7)
    if (IsKeyJustPressed(KEY_TOGGLE_MOD)) {
        bool enabled = !config.IsUnlimitedStaminaEnabled();
        config.SetUnlimitedStamina(enabled);
        config.Save();
        
        // Show notification message
        if (config.ShowNotifications()) {
            CMessages::AddMessageJumpQ(
                enabled ? "~g~Unlimited Stamina: ~w~Enabled" : "~r~Unlimited Stamina: ~w~Disabled", 
                3000, 0, false
            );
        }
    }
    
    // Toggle notifications (F8)
    if (IsKeyJustPressed(KEY_TOGGLE_NOTIFY)) {
        bool enabled = !config.ShowNotifications();
        config.SetShowNotifications(enabled);
        config.Save();
        
        // Always show this notification regardless of setting
        CMessages::AddMessageJumpQ(
            enabled ? "~g~Notifications: ~w~Enabled" : "~r~Notifications: ~w~Disabled", 
            3000, 0, false
        );
    }
}

void InputManager::Reset() {
    // Reset all key states
    memset(m_keyStates, 0, sizeof(m_keyStates));
    m_lastPressTime = 0;
} 