#ifndef BNM_H
#define BNM_H

#include <jni.h>
#include <string>
#include <vector>
#include <map>

namespace ImperiumModz {
namespace Features {

class BNM {
public:
    BNM();
    ~BNM();

    // Inicializar BNM
    void Initialize();
    
    // Ativar/Desativar BNM
    void Enable(bool enabled);
    bool IsEnabled() const;
    
    // Registrar detecção de ban
    void RegisterBanDetection(const std::string& reason);
    
    // Obter histórico de detecções
    std::vector<std::string> GetDetectionHistory() const;
    
    // Limpar histórico
    void ClearHistory();
    
    // Configurar modo de proteção
    void SetProtectionMode(int mode);
    int GetProtectionMode() const;
    
    // Verificar integridade do sistema
    bool VerifySystemIntegrity();
    
    // Aplicar patches de proteção
    void ApplyProtectionPatches();
    
    // Remover patches de proteção
    void RemoveProtectionPatches();
    
    // Obter status de proteção
    std::string GetProtectionStatus() const;
    
    // Reset para valores padrão
    void Reset();

private:
    bool enabled_;
    int protection_mode_;
    std::vector<std::string> detection_history_;
    std::map<std::string, bool> protection_patches_;
    
    void LogDetection(const std::string& reason);
    void UpdateProtectionStatus();
};

} // namespace Features
} // namespace ImperiumModz

#endif // BNM_H
