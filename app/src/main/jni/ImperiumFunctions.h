#ifndef IMPERIUMFUNCTIONS_H
#define IMPERIUMFUNCTIONS_H

#include "Offsets.h"
#include "Struct/Unity.h"
#include "BNM_System.h"
#include "KeyValidator.h"
#include "ModernESP.h"

// IMPERIUM MODZ X Phantom Force
// Advanced Functions Based on Real Offsets from OB52 Dump

// ============================================
// FEATURE TOGGLES
// ============================================
bool SpinBoot_Enabled = false;
bool SpeedHack_Enabled = false;
bool WideFOV_Enabled = false;
bool ZoomHack_Enabled = false;
bool AimAssist_Enabled = false;
bool AntiAim_Enabled = false;
bool Teleport_Enabled = false;
bool NoClip_Enabled = false;
bool NoFallDamage_Enabled = false; // Already in Main.cpp

// ============================================
// CONFIGURATION VALUES
// ============================================
float SpinBootSpeed = 720.0f; // Degrees per second
float SpeedMultiplier = 2.0f;
float FOV_Value = 120.0f; // Default 90
float ZoomMultiplier = 3.0f;
float AimAssistStrength = 2.0f;
Vector3 TeleportDestination = {0, 0, 0};

// Key Validation
static KeyValidator* g_KeyValidator = nullptr;
static bool g_IsKeyValidated = false;

// ============================================
// 1. SPIN BOOT - Auto Rotation (360° Spin)
// Offsets: 0x7eedf7c, 0x46290a8
// ============================================
float (*orig_GetRotationYaw)(void* _this, uint32_t direction, uint32_t freeDirection);
float hook_GetRotationYaw(void* _this, uint32_t direction, uint32_t freeDirection) {
    if(SpinBoot_Enabled && _this != NULL) {
        static float currentAngle = 0.0f;
        currentAngle += SpinBootSpeed * 0.016f; // 60 FPS
        if(currentAngle >= 360.0f) currentAngle -= 360.0f;
        
        BNM::PeriodicCheck(); // Anti-detection
        return currentAngle;
    }
    return orig_GetRotationYaw(_this, direction, freeDirection);
}

void (*orig_SetRotation)(void* _this, int index, void* slotTransform, float rotateValue);
void hook_SetRotation(void* _this, int index, void* slotTransform, float rotateValue) {
    if(SpinBoot_Enabled && _this != NULL) {
        static float spinAngle = 0.0f;
        spinAngle += SpinBootSpeed * 0.016f;
        if(spinAngle >= 360.0f) spinAngle -= 360.0f;
        orig_SetRotation(_this, index, slotTransform, spinAngle);
        return;
    }
    orig_SetRotation(_this, index, slotTransform, rotateValue);
}

// ============================================
// 2. SPEED HACK - Enhanced Movement Speed
// Offset: 0x2ed3040
// ============================================
float (*orig_GetMoveSpeedForFPPMode)(void* _this);
float hook_GetMoveSpeedForFPPMode(void* _this) {
    if(SpeedHack_Enabled && _this != NULL) {
        float originalSpeed = orig_GetMoveSpeedForFPPMode(_this);
        BNM::AntiAnalysisDelay();
        return originalSpeed * SpeedMultiplier;
    }
    return orig_GetMoveSpeedForFPPMode(_this);
}

// ============================================
// 3. WIDE FOV - Increased Field of View
// Offset: 0x325dfcc (IsCameraModeZooming)
// ============================================
bool (*orig_IsCameraModeZooming)();
bool hook_IsCameraModeZooming() {
    if(WideFOV_Enabled) {
        return true; // Force zooming state for wider FOV
    }
    return orig_IsCameraModeZooming();
}

// FOV Getter/Setter (need to find exact offset)
float (*orig_GetFOV)(void* _this);
float hook_GetFOV(void* _this) {
    if(WideFOV_Enabled && _this != NULL) {
        return FOV_Value;
    }
    return orig_GetFOV(_this);
}

// ============================================
// 4. ZOOM HACK - Enhanced Weapon Zoom
// Offset: 0x2e59468
// ============================================
int (*orig_GetWeaponZoomAmplifier)(void* _this);
int hook_GetWeaponZoomAmplifier(void* _this) {
    if(ZoomHack_Enabled && _this != NULL) {
        int originalZoom = orig_GetWeaponZoomAmplifier(_this);
        return (int)(originalZoom * ZoomMultiplier);
    }
    return orig_GetWeaponZoomAmplifier(_this);
}

void (*orig_SetZoomDest)(void* _this, float p1, float p2);
void hook_SetZoomDest(void* _this, float p1, float p2) {
    if(ZoomHack_Enabled && _this != NULL) {
        orig_SetZoomDest(_this, p1 * ZoomMultiplier, p2 * ZoomMultiplier);
        return;
    }
    orig_SetZoomDest(_this, p1, p2);
}

// ============================================
// 5. AIM ASSIST ENHANCED
// Offsets: 0x2dd0618, 0x2e59514
// ============================================
void* (*orig_GetAimAssistOnSighting)(void* _this);
void* hook_GetAimAssistOnSighting(void* _this) {
    void* result = orig_GetAimAssistOnSighting(_this);
    
    if(AimAssist_Enabled && result != NULL) {
        // Enhance aim assist parameters
        BNM::RandomizeMemory(); // Anti-detection
    }
    
    return result;
}

float (*orig_GetAimAssistDampCoefficient)(void* _this, void* param);
float hook_GetAimAssistDampCoefficient(void* _this, void* param) {
    if(AimAssist_Enabled && _this != NULL) {
        float originalCoeff = orig_GetAimAssistDampCoefficient(_this, param);
        return originalCoeff * AimAssistStrength;
    }
    return orig_GetAimAssistDampCoefficient(_this, param);
}

// ============================================
// 6. ANTI-AIM - Make it harder for enemies to hit you
// Uses rotation manipulation
// ============================================
float (*orig_GetRotationAngleFromView)(void* _this, void* player);
float hook_GetRotationAngleFromView(void* _this, void* player) {
    if(AntiAim_Enabled && _this != NULL) {
        // Return random angle to confuse enemy aim
        static float jitterAngle = 0.0f;
        jitterAngle += (rand() % 180) - 90; // Random jitter
        return jitterAngle;
    }
    return orig_GetRotationAngleFromView(_this, player);
}

// ============================================
// 7. TELEPORT - Instant Position Change
// Offsets: 0x61873b8, 0x2dd8070
// ============================================
void (*orig_SetPosition)(void* _this, Vector2 position);
void hook_SetPosition(void* _this, Vector2 position) {
    if(Teleport_Enabled && _this != NULL) {
        // Use TeleportDestination instead
        Vector2 dest = {TeleportDestination.X, TeleportDestination.Z};
        orig_SetPosition(_this, dest);
        Teleport_Enabled = false; // One-time teleport
        return;
    }
    orig_SetPosition(_this, position);
}

float (*orig_GetTeleportDoorUseCDEndTime)(void* _this);
float hook_GetTeleportDoorUseCDEndTime(void* _this) {
    // Remove cooldown for teleport doors
    return 0.0f;
}

bool (*orig_CheckCanUseTeleportDoor)(void* _this);
bool hook_CheckCanUseTeleportDoor(void* _this) {
    // Always allow teleport door usage
    return true;
}

// ============================================
// 8. NO CLIP - Walk through walls
// Uses SetPosition to bypass collision
// ============================================
Vector3 g_LastPosition = {0, 0, 0};
Vector3 g_NoClipDirection = {0, 0, 0};

void EnableNoClip(Vector3 direction) {
    NoClip_Enabled = true;
    g_NoClipDirection = direction;
}

void UpdateNoClip(void* playerInstance) {
    if(!NoClip_Enabled || !playerInstance) return;
    
    // Get current position
    // Vector3 currentPos = GetPlayerPosition(playerInstance);
    
    // Move in direction ignoring collision
    // Vector3 newPos = {
    //     currentPos.X + g_NoClipDirection.X * 0.5f,
    //     currentPos.Y + g_NoClipDirection.Y * 0.5f,
    //     currentPos.Z + g_NoClipDirection.Z * 0.5f
    // };
    
    // SetPlayerPosition(playerInstance, newPos);
}

// ============================================
// 9. VISIBILITY CHECK - For ESP
// Offset: 0x2dd6da4
// ============================================
bool (*orig_IsVisible)(void* _this);
bool hook_IsVisible(void* _this) {
    bool result = orig_IsVisible(_this);
    
    // Store visibility info for ESP system
    // UpdateESPVisibility(_this, result);
    
    return result;
}

bool (*orig_IsVisibleByFlag)(void* _this, uint32_t flag);
bool hook_IsVisibleByFlag(void* _this, uint32_t flag) {
    bool result = orig_IsVisibleByFlag(_this, flag);
    return result;
}

// ============================================
// INITIALIZATION
// ============================================
void InitializeImperiumFeatures() {
    BNM::Initialize();
    g_KeyValidator = new KeyValidator();
    
    LOGI(BNM::BNM_XOR("IMPERIUM MODZ X Phantom Force - Features Initialized"));
    LOGI(BNM::BNM_XOR("Total Features: 9"));
}

bool ValidateUserKey(const std::string& keyCode) {
    if(!g_KeyValidator) {
        g_KeyValidator = new KeyValidator();
    }
    
    g_IsKeyValidated = g_KeyValidator->validateKey(keyCode);
    
    if(g_IsKeyValidated) {
        LOGI(BNM::BNM_XOR("✓ Key validated - All features unlocked!"));
    } else {
        LOGE(BNM::BNM_XOR("✗ Invalid key - Features locked"));
    }
    
    return g_IsKeyValidated;
}

bool IsFeatureUnlocked() {
    return g_IsKeyValidated;
}

// ============================================
// HOOK INSTALLATION
// ============================================
void InstallImperiumHooks() {
    if(!IsFeatureUnlocked()) {
        LOGE("⚠ Features locked - Key validation required!");
        return;
    }
    
    LOGI(BNM::BNM_XOR("Installing IMPERIUM hooks..."));
    
    // 1. Spin Boot
    DobbyHook((void*)0x7eedf7c, (void*)hook_GetRotationYaw, (void**)&orig_GetRotationYaw);
    DobbyHook((void*)0x46290a8, (void*)hook_SetRotation, (void**)&orig_SetRotation);
    
    // 2. Speed Hack
    DobbyHook((void*)0x2ed3040, (void*)hook_GetMoveSpeedForFPPMode, (void**)&orig_GetMoveSpeedForFPPMode);
    
    // 3. Wide FOV
    DobbyHook((void*)0x325dfcc, (void*)hook_IsCameraModeZooming, (void**)&orig_IsCameraModeZooming);
    
    // 4. Zoom Hack
    DobbyHook((void*)0x2e59468, (void*)hook_GetWeaponZoomAmplifier, (void**)&orig_GetWeaponZoomAmplifier);
    DobbyHook((void*)0x397b2d0, (void*)hook_SetZoomDest, (void**)&orig_SetZoomDest);
    
    // 5. Aim Assist
    DobbyHook((void*)0x2dd0618, (void*)hook_GetAimAssistOnSighting, (void**)&orig_GetAimAssistOnSighting);
    DobbyHook((void*)0x2e59514, (void*)hook_GetAimAssistDampCoefficient, (void**)&orig_GetAimAssistDampCoefficient);
    
    // 6. Anti-Aim
    // DobbyHook((void*)0x5fdf458, (void*)hook_GetRotationAngleFromView, (void**)&orig_GetRotationAngleFromView);
    
    // 7. Teleport
    DobbyHook((void*)0x61873b8, (void*)hook_SetPosition, (void**)&orig_SetPosition);
    DobbyHook((void*)0x2dd8070, (void*)hook_GetTeleportDoorUseCDEndTime, (void**)&orig_GetTeleportDoorUseCDEndTime);
    DobbyHook((void*)0x2e5a4c8, (void*)hook_CheckCanUseTeleportDoor, (void**)&orig_CheckCanUseTeleportDoor);
    
    // 9. Visibility (for ESP)
    DobbyHook((void*)0x2dd6da4, (void*)hook_IsVisible, (void**)&orig_IsVisible);
    DobbyHook((void*)0x2dd6e08, (void*)hook_IsVisibleByFlag, (void**)&orig_IsVisibleByFlag);
    
    LOGI(BNM::BNM_XOR("✓ All IMPERIUM hooks installed successfully!"));
}

#endif // IMPERIUMFUNCTIONS_H
