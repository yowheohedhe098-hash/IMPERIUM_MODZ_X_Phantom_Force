#ifndef SPINBOOT_H
#define SPINBOOT_H

#include <jni.h>
#include <string>
#include <vector>

namespace ImperiumModz {
namespace Features {

class SpinBoot {
public:
    SpinBoot();
    ~SpinBoot();

    // Inicializar Spin Boot
    void Initialize();
    
    // Ativar/Desativar Spin Boot
    void Enable(bool enabled);
    bool IsEnabled() const;
    
    // Configurar velocidade de rotação (0.0 - 1.0)
    void SetRotationSpeed(float speed);
    float GetRotationSpeed() const;
    
    // Configurar sensibilidade
    void SetSensitivity(float sensitivity);
    float GetSensitivity() const;
    
    // Configurar ângulo de rotação
    void SetRotationAngle(float angle);
    float GetRotationAngle() const;
    
    // Atualizar frame
    void Update(float deltaTime);
    
    // Reset para valores padrão
    void Reset();

private:
    bool enabled_;
    float rotation_speed_;
    float sensitivity_;
    float rotation_angle_;
    float current_rotation_;
    
    void ApplyRotation();
};

} // namespace Features
} // namespace ImperiumModz

#endif // SPINBOOT_H
