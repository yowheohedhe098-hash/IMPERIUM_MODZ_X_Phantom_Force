#include "ESP.h"
#include <android/log.h>
#include <algorithm>

#define LOG_TAG "ImperiumModz::ESP"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace ImperiumModz {
namespace Features {

ESP::ESP() 
    : enabled_(false),
      box_esp_enabled_(false),
      skeleton_esp_enabled_(false),
      name_esp_enabled_(false),
      distance_esp_enabled_(false),
      health_esp_enabled_(false),
      line_esp_enabled_(false),
      max_distance_(500.0f),
      line_thickness_(2.0f),
      box_color_(1.0f, 0.0f, 0.0f, 1.0f),
      skeleton_color_(0.0f, 1.0f, 0.0f, 1.0f),
      name_color_(1.0f, 1.0f, 1.0f, 1.0f),
      health_color_(0.0f, 1.0f, 0.0f, 1.0f) {
    LOGI("ESP initialized");
}

ESP::~ESP() {
    LOGI("ESP destroyed");
}

void ESP::Initialize() {
    enabled_ = false;
    box_esp_enabled_ = false;
    skeleton_esp_enabled_ = false;
    name_esp_enabled_ = false;
    distance_esp_enabled_ = false;
    health_esp_enabled_ = false;
    line_esp_enabled_ = false;
    max_distance_ = 500.0f;
    line_thickness_ = 2.0f;
    players_.clear();
    LOGI("ESP initialized with default values");
}

void ESP::Enable(bool enabled) {
    enabled_ = enabled;
    LOGI("ESP %s", enabled ? "enabled" : "disabled");
}

bool ESP::IsEnabled() const {
    return enabled_;
}

void ESP::EnableBoxESP(bool enabled) {
    box_esp_enabled_ = enabled;
    LOGI("Box ESP %s", enabled ? "enabled" : "disabled");
}

void ESP::EnableSkeletonESP(bool enabled) {
    skeleton_esp_enabled_ = enabled;
    LOGI("Skeleton ESP %s", enabled ? "enabled" : "disabled");
}

void ESP::EnableNameESP(bool enabled) {
    name_esp_enabled_ = enabled;
    LOGI("Name ESP %s", enabled ? "enabled" : "disabled");
}

void ESP::EnableDistanceESP(bool enabled) {
    distance_esp_enabled_ = enabled;
    LOGI("Distance ESP %s", enabled ? "enabled" : "disabled");
}

void ESP::EnableHealthESP(bool enabled) {
    health_esp_enabled_ = enabled;
    LOGI("Health ESP %s", enabled ? "enabled" : "disabled");
}

void ESP::EnableLineESP(bool enabled) {
    line_esp_enabled_ = enabled;
    LOGI("Line ESP %s", enabled ? "enabled" : "disabled");
}

void ESP::SetBoxColor(float r, float g, float b, float a) {
    box_color_ = glm::vec4(r, g, b, a);
    LOGI("Box color set to: (%.2f, %.2f, %.2f, %.2f)", r, g, b, a);
}

void ESP::SetSkeletonColor(float r, float g, float b, float a) {
    skeleton_color_ = glm::vec4(r, g, b, a);
    LOGI("Skeleton color set to: (%.2f, %.2f, %.2f, %.2f)", r, g, b, a);
}

void ESP::SetNameColor(float r, float g, float b, float a) {
    name_color_ = glm::vec4(r, g, b, a);
    LOGI("Name color set to: (%.2f, %.2f, %.2f, %.2f)", r, g, b, a);
}

void ESP::SetHealthColor(float r, float g, float b, float a) {
    health_color_ = glm::vec4(r, g, b, a);
    LOGI("Health color set to: (%.2f, %.2f, %.2f, %.2f)", r, g, b, a);
}

void ESP::SetMaxDistance(float distance) {
    max_distance_ = std::max(0.0f, distance);
    LOGI("Max distance set to: %.2f", max_distance_);
}

float ESP::GetMaxDistance() const {
    return max_distance_;
}

void ESP::SetLineThickness(float thickness) {
    line_thickness_ = std::max(0.1f, thickness);
    LOGI("Line thickness set to: %.2f", line_thickness_);
}

float ESP::GetLineThickness() const {
    return line_thickness_;
}

void ESP::UpdatePlayerInfo(const std::vector<PlayerInfo>& players) {
    players_ = players;
    LOGI("Updated %zu player(s) info", players_.size());
}

void ESP::Render() {
    if (!enabled_) return;
    
    for (const auto& player : players_) {
        if (player.distance > max_distance_) continue;
        
        if (box_esp_enabled_) {
            RenderBoxESP(player);
        }
        if (skeleton_esp_enabled_) {
            RenderSkeletonESP(player);
        }
        if (name_esp_enabled_) {
            RenderNameESP(player);
        }
        if (distance_esp_enabled_) {
            RenderDistanceESP(player);
        }
        if (health_esp_enabled_) {
            RenderHealthESP(player);
        }
        if (line_esp_enabled_) {
            RenderLineESP(player);
        }
    }
}

void ESP::RenderBoxESP(const PlayerInfo& player) {
    LOGI("Rendering box ESP for player %d at distance %.2f", player.player_id, player.distance);
    // Implementação específica de renderização
}

void ESP::RenderSkeletonESP(const PlayerInfo& player) {
    LOGI("Rendering skeleton ESP for player %d", player.player_id);
    // Implementação específica de renderização
}

void ESP::RenderNameESP(const PlayerInfo& player) {
    LOGI("Rendering name ESP: %s", player.player_name.c_str());
    // Implementação específica de renderização
}

void ESP::RenderDistanceESP(const PlayerInfo& player) {
    LOGI("Rendering distance ESP: %.2f", player.distance);
    // Implementação específica de renderização
}

void ESP::RenderHealthESP(const PlayerInfo& player) {
    LOGI("Rendering health ESP for player %d", player.player_id);
    // Implementação específica de renderização
}

void ESP::RenderLineESP(const PlayerInfo& player) {
    LOGI("Rendering line ESP for player %d", player.player_id);
    // Implementação específica de renderização
}

void ESP::Reset() {
    enabled_ = false;
    box_esp_enabled_ = false;
    skeleton_esp_enabled_ = false;
    name_esp_enabled_ = false;
    distance_esp_enabled_ = false;
    health_esp_enabled_ = false;
    line_esp_enabled_ = false;
    max_distance_ = 500.0f;
    line_thickness_ = 2.0f;
    players_.clear();
    LOGI("ESP reset to default values");
}

} // namespace Features
} // namespace ImperiumModz
