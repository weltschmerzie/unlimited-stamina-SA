#pragma once

/**
 * InputManager.h
 * 
 * Simplified class for managing input.
 * No longer handles keyboard controls for toggling features.
 */

class InputManager {
private:
    // Empty class as we no longer need input handling
    
public:
    InputManager() = default;
    ~InputManager() = default;
    
    /**
     * Process function (now empty as we don't need input handling)
     */
    void Process() {}
    
    /**
     * Reset function (now empty as we don't need input handling)
     */
    void Reset() {}
}; 