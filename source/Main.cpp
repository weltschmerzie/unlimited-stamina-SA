/**
 * Unlimited Stamina Plugin for GTA San Andreas
 * 
 * This plugin provides infinite stamina for the player character (CJ).
 * It uses Plugin SDK to hook into the game's systems and modify player stats.
 */

#include "StaminaManager.h"
#include "InputManager.h"
#include "Config.h"
#include <plugin.h>
#include <common.h>
#include <CTimer.h>
#include <CText.h>
#include <CFont.h>
#include <CSprite.h>
#include <CHud.h>

using namespace plugin;

// Forward declaration
class Main;
extern Main gInstance;

class Main {
private:
    StaminaManager m_staminaManager;
    InputManager m_inputManager;
    bool m_showStartupNotification;
    float m_notificationTime;
    
public:
    Main() : m_showStartupNotification(true), m_notificationTime(0.0f) {
        // Register event callbacks
        Events::initGameEvent += []() { gInstance.OnInitGame(); };
        Events::gameProcessEvent += []() { gInstance.OnGameProcess(); };
        Events::drawHudEvent += []() { gInstance.OnDrawHud(); };
        Events::initScriptsEvent += []() { gInstance.OnInitScripts(); };
        
        // Note: gameResetEvent is not available in this version of Plugin SDK
        // We handle reset functionality in initGameEvent instead
    }
    
    void OnInitGame() {
        // Load configuration
        Config::GetInstance().Load();
        
        // Initialize managers
        m_staminaManager.Initialize();
        m_inputManager.Reset();
        
        // Setup notification
        m_showStartupNotification = Config::GetInstance().ShowNotifications();
        m_notificationTime = 0.0f;
    }
    
    void OnInitScripts() {
        // Additional initialization if needed
        // We can also do reset handling here if needed
        ResetState();
    }
    
    // Helper method to reset state (replaces OnGameReset)
    void ResetState() {
        m_staminaManager.Initialize();
        m_inputManager.Reset();
    }

    void OnGameProcess() {
        // Process input
        m_inputManager.Process();
        
        // Apply unlimited stamina if enabled
        if (Config::GetInstance().IsUnlimitedStaminaEnabled()) {
            m_staminaManager.Process();
        }
        
        // Timer for notification display
        if (m_showStartupNotification) {
            m_notificationTime += CTimer::ms_fTimeStep;
            if (m_notificationTime > 5.0f) {
                m_showStartupNotification = false;
            }
        }
    }
    
    void OnDrawHud() {
        // Show startup notification
        if (m_showStartupNotification) {
            m_staminaManager.DrawNotification();
        }
    }
} gInstance;
