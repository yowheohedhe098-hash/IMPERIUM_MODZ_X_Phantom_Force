#ifndef OFFSETS_H
#define OFFSETS_H

// IMPERIUM MODZ X Phantom Force - Offsets OB52
// Extracted from Ob52ffmaxdump(1).cs

namespace Offsets {
    // Player Methods
    constexpr uintptr_t ShowWeaponSkin = 0x2deda90;
    constexpr uintptr_t UpdateBehavior = 0x2e1ac94;
    constexpr uintptr_t TakeDamage = 0x2e39c98;
    constexpr uintptr_t CanTakeDamage = 0x3716ddc;
    
    // Movement & Physics
    constexpr uintptr_t GetCurrentDashSpeed = 0x0; // Need to find in dump
    constexpr uintptr_t GetPhysXState = 0x0; // Already hooked in Main.cpp
    constexpr uintptr_t IsPoseFallingHigh = 0x0; // Already hooked in Main.cpp
    
    // Weapon Methods
    constexpr uintptr_t GetRecoil = 0x0; // Need to find
    constexpr uintptr_t GetReloadTime = 0x0; // Need to find
    constexpr uintptr_t GetFireRate = 0x0; // Need to find
    
    // Anti-Cheat
    constexpr uintptr_t IsEmulator = 0x0; // Already hooked in Main.cpp
    constexpr uintptr_t CheckIntegrity = 0x0; // Need to find
    constexpr uintptr_t IsRooted = 0x0; // Need to find
    
    // ESP & Rendering
    constexpr uintptr_t GetPlayerList = 0x0; // Need to find
    constexpr uintptr_t GetPlayerPosition = 0x0; // Need to find
    constexpr uintptr_t WorldToScreen = 0x0; // Need to find
    
    // Spin Boot (Rotation)
    constexpr uintptr_t GetRotation = 0x0; // Need to find
    constexpr uintptr_t SetRotation = 0x0; // Need to find
    
    // Speed Hack
    constexpr uintptr_t GetMoveSpeed = 0x0; // Need to find
    constexpr uintptr_t GetRunSpeed = 0x0; // Need to find
}

// Assembly Name and Namespace for Il2CppGetMethodOffset
#define ASSEMBLY "Assembly-CSharp.dll"
#define NS_COW "COW"
#define NS_GAMEPLAY "COW.GamePlay"
#define NS_UNITY "UnityEngine"

// Class Names
#define CLASS_PLAYER "Player"
#define CLASS_WEAPON "Weapon"
#define CLASS_GAMECONFIG "GameConfig"
#define CLASS_GAMEFACADE "GameFacade"
#define CLASS_INPUT "Input"

// Method Names (Obfuscated)
#define METHOD_SHOWWEAPONSKIN "ShowWeaponSkin"
#define METHOD_UPDATEBEHAVIOR "UpdateBehavior"
#define METHOD_TAKEDAMAGE "TakeDamage"
#define METHOD_ISEMULATOR "IsEmulator"
#define METHOD_RESETGUEST "get_ResetGuest"

#endif // OFFSETS_H
