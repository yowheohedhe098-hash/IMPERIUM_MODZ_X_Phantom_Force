#include "SpinBoot.h"
#include <cmath>
#include <android/log.h>

#define LOG_TAG "ImperiumModz::SpinBoot"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace ImperiumModz {
namespace Features {

SpinBoot::SpinBoot() 
    : enabled_(false), 
      rotation_speed_(0.5f), 
      sensitivity_(1.0f), 
      rotation_angle_(0.0f),
      current_rotation_(0.0f) {
    LOGI("SpinBoot initialized");
}

SpinBoot::~SpinBoot() {
    LOGI("SpinBoot destroyed");
}

void SpinBoot::Initialize() {
    enabled_ = false;
    rotation_speed_ = 0.5f;
    sensitivity_ = 1.0f;
    rotation_angle_ = 0.0f;
    current_rotation_ = 0.0f;
    LOGI("SpinBoot initialized with default values");
}

void SpinBoot::Enable(bool enabled) {
    enabled_ = enabled;
    LOGI("SpinBoot %s", enabled ? "enabled" : "disabled");
}

bool SpinBoot::IsEnabled() const {
    return enabled_;
}

void SpinBoot::SetRotationSpeed(float speed) {
    rotation_speed_ = std::max(0.0f, std::min(1.0f, speed));
    LOGI("SpinBoot rotation speed set to: %.2f", rotation_speed_);
}

float SpinBoot::GetRotationSpeed() const {
    return rotation_speed_;
}

void SpinBoot::SetSensitivity(float sensitivity) {
    sensitivity_ = std::max(0.1f, std::min(5.0f, sensitivity));
    LOGI("SpinBoot sensitivity set to: %.2f", sensitivity_);
}

float SpinBoot::GetSensitivity() const {
    return sensitivity_;
}

void SpinBoot::SetRotationAngle(float angle) {
    rotation_angle_ = angle;
    while (rotation_angle_ >= 360.0f) rotation_angle_ -= 360.0f;
    while (rotation_angle_ < 0.0f) rotation_angle_ += 360.0f;
    LOGI("SpinBoot rotation angle set to: %.2f", rotation_angle_);
}

float SpinBoot::GetRotationAngle() const {
    return rotation_angle_;
}

void SpinBoot::Update(float deltaTime) {
    if (!enabled_) return;
    
    // Calcular rotação baseada na velocidade e sensibilidade
    float rotation_delta = rotation_speed_ * sensitivity_ * deltaTime * 360.0f;
    current_rotation_ += rotation_delta;
    
    // Normalizar ângulo
    while (current_rotation_ >= 360.0f) current_rotation_ -= 360.0f;
    
    ApplyRotation();
}

void SpinBoot::ApplyRotation() {
    // Aplicar rotação ao jogador
    // Esta função seria implementada com hooks específicos do jogo
    // Por enquanto, apenas registramos o valor
    LOGI("Applying rotation: %.2f degrees", current_rotation_);
}

void SpinBoot::Reset() {
    enabled_ = false;
    rotation_speed_ = 0.5f;
    sensitivity_ = 1.0f;
    rotation_angle_ = 0.0f;
    current_rotation_ = 0.0f;
    LOGI("SpinBoot reset to default values");
}

} // namespace Features
} // namespace ImperiumModz
