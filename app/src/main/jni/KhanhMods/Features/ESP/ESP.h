#ifndef ESP_H
#define ESP_H

#include <jni.h>
#include <string>
#include <vector>
#include <glm/glm.hpp>

namespace ImperiumModz {
namespace Features {

struct PlayerInfo {
    int player_id;
    glm::vec3 position;
    glm::vec3 head_position;
    float distance;
    bool is_alive;
    bool is_visible;
    int team;
    std::string player_name;
};

class ESP {
public:
    ESP();
    ~ESP();

    // Inicializar ESP
    void Initialize();
    
    // Ativar/Desativar ESP
    void Enable(bool enabled);
    bool IsEnabled() const;
    
    // Tipos de ESP
    void EnableBoxESP(bool enabled);
    void EnableSkeletonESP(bool enabled);
    void EnableNameESP(bool enabled);
    void EnableDistanceESP(bool enabled);
    void EnableHealthESP(bool enabled);
    void EnableLineESP(bool enabled);
    
    // Configurar cores
    void SetBoxColor(float r, float g, float b, float a);
    void SetSkeletonColor(float r, float g, float b, float a);
    void SetNameColor(float r, float g, float b, float a);
    void SetHealthColor(float r, float g, float b, float a);
    
    // Configurar distância máxima
    void SetMaxDistance(float distance);
    float GetMaxDistance() const;
    
    // Configurar espessura de linhas
    void SetLineThickness(float thickness);
    float GetLineThickness() const;
    
    // Atualizar informações de jogadores
    void UpdatePlayerInfo(const std::vector<PlayerInfo>& players);
    
    // Renderizar ESP
    void Render();
    
    // Reset para valores padrão
    void Reset();

private:
    bool enabled_;
    bool box_esp_enabled_;
    bool skeleton_esp_enabled_;
    bool name_esp_enabled_;
    bool distance_esp_enabled_;
    bool health_esp_enabled_;
    bool line_esp_enabled_;
    
    float max_distance_;
    float line_thickness_;
    
    // Cores
    glm::vec4 box_color_;
    glm::vec4 skeleton_color_;
    glm::vec4 name_color_;
    glm::vec4 health_color_;
    
    std::vector<PlayerInfo> players_;
    
    void RenderBoxESP(const PlayerInfo& player);
    void RenderSkeletonESP(const PlayerInfo& player);
    void RenderNameESP(const PlayerInfo& player);
    void RenderDistanceESP(const PlayerInfo& player);
    void RenderHealthESP(const PlayerInfo& player);
    void RenderLineESP(const PlayerInfo& player);
};

} // namespace Features
} // namespace ImperiumModz

#endif // ESP_H
