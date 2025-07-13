/**
 * Unlimited Stamina Plugin for GTA San Andreas
 * 
 * This plugin provides infinite stamina for the player character (CJ).
 * It uses Plugin SDK to hook into the game's systems and modify player stats.
 * Configuration is handled through the unlimited-stamina.ini file.
 */

#include "StaminaManager.h"
#include "InputManager.h"
#include "Config.h"
#include <plugin.h>
#include <common.h>
#include <CTimer.h>

using namespace plugin;

// Forward declaration
class Main;
extern Main gInstance;

class Main {
private:
    StaminaManager m_staminaManager;
    InputManager m_inputManager;
    
public:
    Main() {
        // Register event callbacks
        Events::initGameEvent += []() { gInstance.OnInitGame(); };
        Events::gameProcessEvent += []() { gInstance.OnGameProcess(); };
        Events::initScriptsEvent += []() { gInstance.OnInitScripts(); };
    }
    
    void OnInitGame() {
        // Load configuration
        Config::GetInstance().Load();
        
        // Initialize managers
        m_staminaManager.Initialize();
        m_inputManager.Reset();
    }
    
    void OnInitScripts() {
        // Additional initialization if needed
        ResetState();
    }
    
    // Helper method to reset state
    void ResetState() {
        m_staminaManager.Initialize();
        m_inputManager.Reset();
    }

    void OnGameProcess() {
        // Process input (empty but kept for structure)
        m_inputManager.Process();
        
        // Apply unlimited stamina if enabled in INI
        if (Config::GetInstance().IsUnlimitedStaminaEnabled()) {
            m_staminaManager.Process();
        }
    }
} gInstance;
