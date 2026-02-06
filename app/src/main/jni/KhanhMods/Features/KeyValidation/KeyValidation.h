#ifndef KEYVALIDATION_H
#define KEYVALIDATION_H

#include <jni.h>
#include <string>
#include <map>
#include <vector>

namespace ImperiumModz {
namespace Features {

struct KeyInfo {
    std::string key;
    std::string user_id;
    bool is_valid;
    bool is_active;
    long expiration_time;
    std::string status;
};

class KeyValidation {
public:
    KeyValidation();
    ~KeyValidation();

    // Inicializar Key Validation
    void Initialize(const std::string& api_url);
    
    // Validar chave
    bool ValidateKey(const std::string& key);
    
    // Ativar chave
    bool ActivateKey(const std::string& key, const std::string& user_id);
    
    // Desativar chave
    bool DeactivateKey(const std::string& key);
    
    // Verificar se chave está ativa
    bool IsKeyActive(const std::string& key) const;
    
    // Obter informações da chave
    KeyInfo GetKeyInfo(const std::string& key) const;
    
    // Verificar expiração
    bool IsKeyExpired(const std::string& key) const;
    
    // Renovar chave
    bool RenewKey(const std::string& key);
    
    // Obter lista de chaves ativas
    std::vector<KeyInfo> GetActiveKeys() const;
    
    // Sincronizar com servidor
    bool SyncWithServer();
    
    // Configurar URL da API
    void SetAPIUrl(const std::string& url);
    std::string GetAPIUrl() const;
    
    // Reset para valores padrão
    void Reset();

private:
    std::string api_url_;
    std::map<std::string, KeyInfo> keys_;
    bool initialized_;
    
    bool SendValidationRequest(const std::string& key);
    bool SendActivationRequest(const std::string& key, const std::string& user_id);
    bool SendDeactivationRequest(const std::string& key);
    std::string EncryptKey(const std::string& key);
    std::string DecryptKey(const std::string& encrypted_key);
};

} // namespace Features
} // namespace ImperiumModz

#endif // KEYVALIDATION_H
