#ifndef MODERNESP_H
#define MODERNESP_H

#include "Struct/Unity.h"
#include "ImGui/imgui.h"
#include <vector>
#include <string>

// IMPERIUM MODZ X Phantom Force
// Modern ESP System - Advanced Visualization

// ESP Feature Toggles
bool ESP_Box3D_Enabled = false;
bool ESP_Skeleton_Enabled = false;
bool ESP_HealthBar_Enabled = false;
bool ESP_Name_Enabled = false;
bool ESP_Weapon_Enabled = false;
bool ESP_Distance_Enabled = false;
bool ESP_Line_Enabled = false;
bool ESP_Glow_Enabled = false;
bool ESP_Snapline_Enabled = false;
bool ESP_FilledBox_Enabled = false;
bool ESP_CornerBox_Enabled = false;

// ESP Colors
ImVec4 ESP_EnemyColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // Red
ImVec4 ESP_TeamColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);  // Green
ImVec4 ESP_VisibleColor = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow
ImVec4 ESP_GlowColor = ImVec4(0.0f, 0.5f, 1.0f, 0.5f);  // Blue glow

// ESP Settings
float ESP_MaxDistance = 300.0f;
float ESP_BoxThickness = 2.0f;
float ESP_LineThickness = 1.5f;
float ESP_SkeletonThickness = 2.0f;
int ESP_FontSize = 14;

// Player Bone Structure for Skeleton ESP
enum BoneIndex {
    BONE_HEAD = 0,
    BONE_NECK = 1,
    BONE_SPINE = 2,
    BONE_PELVIS = 3,
    BONE_LEFT_SHOULDER = 4,
    BONE_LEFT_ELBOW = 5,
    BONE_LEFT_HAND = 6,
    BONE_RIGHT_SHOULDER = 7,
    BONE_RIGHT_ELBOW = 8,
    BONE_RIGHT_HAND = 9,
    BONE_LEFT_HIP = 10,
    BONE_LEFT_KNEE = 11,
    BONE_LEFT_FOOT = 12,
    BONE_RIGHT_HIP = 13,
    BONE_RIGHT_KNEE = 14,
    BONE_RIGHT_FOOT = 15
};

struct BoneConnection {
    BoneIndex from;
    BoneIndex to;
};

// Skeleton bone connections
static const BoneConnection g_SkeletonConnections[] = {
    // Head to body
    {BONE_HEAD, BONE_NECK},
    {BONE_NECK, BONE_SPINE},
    {BONE_SPINE, BONE_PELVIS},
    
    // Left arm
    {BONE_NECK, BONE_LEFT_SHOULDER},
    {BONE_LEFT_SHOULDER, BONE_LEFT_ELBOW},
    {BONE_LEFT_ELBOW, BONE_LEFT_HAND},
    
    // Right arm
    {BONE_NECK, BONE_RIGHT_SHOULDER},
    {BONE_RIGHT_SHOULDER, BONE_RIGHT_ELBOW},
    {BONE_RIGHT_ELBOW, BONE_RIGHT_HAND},
    
    // Left leg
    {BONE_PELVIS, BONE_LEFT_HIP},
    {BONE_LEFT_HIP, BONE_LEFT_KNEE},
    {BONE_LEFT_KNEE, BONE_LEFT_FOOT},
    
    // Right leg
    {BONE_PELVIS, BONE_RIGHT_HIP},
    {BONE_RIGHT_HIP, BONE_RIGHT_KNEE},
    {BONE_RIGHT_KNEE, BONE_RIGHT_FOOT}
};

struct ESPPlayerData {
    void* instance;
    
    // Position data
    Vector3 worldPosition;
    Vector3 headPosition;
    Vector3 screenPosition;
    Vector3 screenHeadPosition;
    Vector3 bonePositions[16]; // Screen positions of bones
    
    // Player info
    std::string playerName;
    std::string weaponName;
    int health;
    int maxHealth;
    float distance;
    
    // Status
    bool isVisible;
    bool isEnemy;
    bool isAlive;
    bool isBehindWall;
    
    // Box dimensions
    float boxWidth;
    float boxHeight;
    ImVec2 boxTopLeft;
    ImVec2 boxBottomRight;
};

std::vector<ESPPlayerData> g_ESPData;

// ============================================
// WORLD TO SCREEN CONVERSION
// ============================================
bool WorldToScreen(Vector3 worldPos, Vector3& screenPos, int screenWidth, int screenHeight) {
    // This needs to be implemented based on game's camera system
    // Placeholder implementation
    
    // Get view and projection matrices from game
    // Matrix4x4 viewMatrix = GetViewMatrix();
    // Matrix4x4 projMatrix = GetProjectionMatrix();
    
    // Transform world to clip space
    // Vector4 clipPos = projMatrix * viewMatrix * Vector4(worldPos, 1.0f);
    
    // Perspective divide
    // if(clipPos.w < 0.1f) return false;
    
    // clipPos.x /= clipPos.w;
    // clipPos.y /= clipPos.w;
    // clipPos.z /= clipPos.w;
    
    // Convert to screen space
    // screenPos.X = (clipPos.x + 1.0f) * 0.5f * screenWidth;
    // screenPos.Y = (1.0f - clipPos.y) * 0.5f * screenHeight;
    // screenPos.Z = clipPos.z;
    
    // return (screenPos.Z > 0.0f && screenPos.Z < 1.0f);
    
    return true; // Placeholder
}

// ============================================
// ESP BOX 3D - Full 3D Bounding Box
// ============================================
void DrawBox3D(ESPPlayerData& player) {
    if(!ESP_Box3D_Enabled) return;
    
    ImDrawList* draw = ImGui::GetForegroundDrawList();
    ImU32 color = player.isEnemy ? 
        ImGui::ColorConvertFloat4ToU32(ESP_EnemyColor) : 
        ImGui::ColorConvertFloat4ToU32(ESP_TeamColor);
    
    draw->AddRect(
        player.boxTopLeft,
        player.boxBottomRight,
        color,
        0.0f,
        0,
        ESP_BoxThickness
    );
}

// ============================================
// ESP CORNER BOX - Corners only
// ============================================
void DrawCornerBox(ESPPlayerData& player) {
    if(!ESP_CornerBox_Enabled) return;
    
    ImDrawList* draw = ImGui::GetForegroundDrawList();
    ImU32 color = ImGui::ColorConvertFloat4ToU32(ESP_EnemyColor);
    
    float cornerSize = player.boxWidth * 0.25f;
    ImVec2 tl = player.boxTopLeft;
    ImVec2 br = player.boxBottomRight;
    
    // Top-left corner
    draw->AddLine(ImVec2(tl.x, tl.y), ImVec2(tl.x + cornerSize, tl.y), color, ESP_BoxThickness);
    draw->AddLine(ImVec2(tl.x, tl.y), ImVec2(tl.x, tl.y + cornerSize), color, ESP_BoxThickness);
    
    // Top-right corner
    draw->AddLine(ImVec2(br.x, tl.y), ImVec2(br.x - cornerSize, tl.y), color, ESP_BoxThickness);
    draw->AddLine(ImVec2(br.x, tl.y), ImVec2(br.x, tl.y + cornerSize), color, ESP_BoxThickness);
    
    // Bottom-left corner
    draw->AddLine(ImVec2(tl.x, br.y), ImVec2(tl.x + cornerSize, br.y), color, ESP_BoxThickness);
    draw->AddLine(ImVec2(tl.x, br.y), ImVec2(tl.x, br.y - cornerSize), color, ESP_BoxThickness);
    
    // Bottom-right corner
    draw->AddLine(ImVec2(br.x, br.y), ImVec2(br.x - cornerSize, br.y), color, ESP_BoxThickness);
    draw->AddLine(ImVec2(br.x, br.y), ImVec2(br.x, br.y - cornerSize), color, ESP_BoxThickness);
}

// ============================================
// ESP FILLED BOX - Semi-transparent fill
// ============================================
void DrawFilledBox(ESPPlayerData& player) {
    if(!ESP_FilledBox_Enabled) return;
    
    ImDrawList* draw = ImGui::GetForegroundDrawList();
    ImVec4 fillColor = player.isEnemy ? ESP_EnemyColor : ESP_TeamColor;
    fillColor.w = 0.2f; // Semi-transparent
    
    draw->AddRectFilled(
        player.boxTopLeft,
        player.boxBottomRight,
        ImGui::ColorConvertFloat4ToU32(fillColor)
    );
}

// ============================================
// ESP SKELETON - Bone structure
// ============================================
void DrawSkeleton(ESPPlayerData& player) {
    if(!ESP_Skeleton_Enabled) return;
    
    ImDrawList* draw = ImGui::GetForegroundDrawList();
    ImU32 color = ImGui::ColorConvertFloat4ToU32(ESP_EnemyColor);
    
    for(const auto& connection : g_SkeletonConnections) {
        Vector3 from = player.bonePositions[connection.from];
        Vector3 to = player.bonePositions[connection.to];
        
        draw->AddLine(
            ImVec2(from.X, from.Y),
            ImVec2(to.X, to.Y),
            color,
            ESP_SkeletonThickness
        );
    }
}

// ============================================
// ESP HEALTH BAR
// ============================================
void DrawHealthBar(ESPPlayerData& player) {
    if(!ESP_HealthBar_Enabled) return;
    
    ImDrawList* draw = ImGui::GetForegroundDrawList();
    
    float barWidth = player.boxWidth;
    float barHeight = 4.0f;
    ImVec2 barPos(player.boxTopLeft.x, player.boxTopLeft.y - 8.0f);
    
    // Background
    draw->AddRectFilled(
        barPos,
        ImVec2(barPos.x + barWidth, barPos.y + barHeight),
        IM_COL32(0, 0, 0, 150)
    );
    
    // Health bar
    float healthPercent = (float)player.health / (float)player.maxHealth;
    ImU32 healthColor = IM_COL32(
        (1.0f - healthPercent) * 255,
        healthPercent * 255,
        0,
        255
    );
    
    draw->AddRectFilled(
        barPos,
        ImVec2(barPos.x + barWidth * healthPercent, barPos.y + barHeight),
        healthColor
    );
}

// ============================================
// ESP NAME & INFO
// ============================================
void DrawPlayerInfo(ESPPlayerData& player) {
    ImDrawList* draw = ImGui::GetForegroundDrawList();
    ImVec2 textPos(player.boxTopLeft.x, player.boxTopLeft.y - 25.0f);
    
    if(ESP_Name_Enabled && !player.playerName.empty()) {
        draw->AddText(textPos, IM_COL32(255, 255, 255, 255), player.playerName.c_str());
        textPos.y += 15.0f;
    }
    
    if(ESP_Weapon_Enabled && !player.weaponName.empty()) {
        draw->AddText(textPos, IM_COL32(200, 200, 200, 255), player.weaponName.c_str());
        textPos.y += 15.0f;
    }
    
    if(ESP_Distance_Enabled) {
        char distText[32];
        snprintf(distText, sizeof(distText), "%.0fm", player.distance);
        draw->AddText(
            ImVec2(player.boxBottomRight.x - 40, player.boxBottomRight.y + 5),
            IM_COL32(255, 255, 0, 255),
            distText
        );
    }
}

// ============================================
// ESP SNAPLINE - Line from screen edge
// ============================================
void DrawSnapline(ESPPlayerData& player, int screenWidth, int screenHeight) {
    if(!ESP_Line_Enabled && !ESP_Snapline_Enabled) return;
    
    ImDrawList* draw = ImGui::GetForegroundDrawList();
    ImU32 color = ImGui::ColorConvertFloat4ToU32(ESP_VisibleColor);
    
    ImVec2 start(screenWidth / 2, screenHeight); // Bottom center
    ImVec2 end(player.screenPosition.X, player.screenPosition.Y);
    
    draw->AddLine(start, end, color, ESP_LineThickness);
}

// ============================================
// ESP GLOW - Outline glow effect
// ============================================
void DrawGlow(ESPPlayerData& player) {
    if(!ESP_Glow_Enabled) return;
    
    ImDrawList* draw = ImGui::GetForegroundDrawList();
    ImU32 glowColor = ImGui::ColorConvertFloat4ToU32(ESP_GlowColor);
    
    // Draw multiple expanding rectangles for glow effect
    for(int i = 0; i < 3; i++) {
        float offset = (i + 1) * 2.0f;
        ImVec2 tl(player.boxTopLeft.x - offset, player.boxTopLeft.y - offset);
        ImVec2 br(player.boxBottomRight.x + offset, player.boxBottomRight.y + offset);
        
        draw->AddRect(tl, br, glowColor, 0.0f, 0, 1.0f);
    }
}

// ============================================
// MAIN ESP RENDER FUNCTION
// ============================================
void RenderModernESP(int screenWidth, int screenHeight) {
    for(auto& player : g_ESPData) {
        if(!player.isAlive) continue;
        if(player.distance > ESP_MaxDistance) continue;
        
        // Draw filled box first (background)
        DrawFilledBox(player);
        
        // Draw glow effect
        DrawGlow(player);
        
        // Draw boxes
        if(ESP_CornerBox_Enabled) {
            DrawCornerBox(player);
        } else {
            DrawBox3D(player);
        }
        
        // Draw skeleton
        DrawSkeleton(player);
        
        // Draw health bar
        DrawHealthBar(player);
        
        // Draw player info
        DrawPlayerInfo(player);
        
        // Draw snapline
        DrawSnapline(player, screenWidth, screenHeight);
    }
}

// ============================================
// UPDATE ESP DATA
// ============================================
void UpdateESPData() {
    g_ESPData.clear();
    
    // This needs to be implemented based on game's player list
    // Iterate through all players and populate g_ESPData
    
    // Placeholder:
    // for(auto* player : GetAllPlayers()) {
    //     ESPPlayerData data;
    //     data.instance = player;
    //     data.worldPosition = GetPlayerPosition(player);
    //     data.playerName = GetPlayerName(player);
    //     data.health = GetPlayerHealth(player);
    //     // ... etc
    //     g_ESPData.push_back(data);
    // }
}

#endif // MODERNESP_H
