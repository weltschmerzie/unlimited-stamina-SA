#pragma once

/**
 * InputManager.h
 * 
 * Manages user input for the Unlimited Stamina plugin.
 * Handles keyboard controls for toggling features.
 */

#include <plugin.h>
#include <CTimer.h>
#include <CMessages.h>
#include "Config.h"

class InputManager {
private:
    // Key status tracking
    bool m_keyStates[256];
    int m_lastPressTime;
    
    // Toggle key codes
    static constexpr int KEY_TOGGLE_MOD = VK_F7;      // F7 to toggle unlimited stamina
    static constexpr int KEY_TOGGLE_NOTIFY = VK_F8;   // F8 to toggle notifications
    
    // Key press cooldown in milliseconds
    static constexpr int KEY_COOLDOWN_MS = 300;
    
    // Helper methods
    bool IsKeyPressed(int keyCode) const;
    bool IsKeyJustPressed(int keyCode);

public:
    InputManager();
    ~InputManager() = default;
    
    /**
     * Process keyboard input
     * Checks for key presses and executes corresponding actions
     */
    void Process();
    
    /**
     * Reset key states
     */
    void Reset();
}; 