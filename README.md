# IMPERIUM MODZ X Phantom Force

![Logo](./logo.png)

## 🎮 Sobre o Projeto

Mod avançado para Free Fire OB52 com sistema de validação de keys online e funcionalidades modernas verificadas.

## ✨ Funcionalidades

### 🏃 Movement
- **Speed Hack** - Velocidade de movimento aumentada (1.0x - 3.0x)
- **Spin Boot** - Rotação automática 360° (360° - 1440°/s)

### 🎯 Camera & Aim
- **Wide FOV** - Campo de visão ampliado
- **Zoom Hack** - Zoom de arma melhorado (1.0x - 5.0x)
- **Aim Assist+** - Assistência de mira aprimorada (1.0x - 3.0x)

### 👁️ Visual
- **Wallhack (Outline)** - Contorno de jogadores através de paredes
- **ESP Box** - Caixa 2D ao redor dos jogadores
- **ESP Line** - Linha da tela até o jogador
- **ESP Distance** - Distância em metros
- **ESP Health Bar** - Barra de vida lateral colorida
- **Night Mode OFF** - Desativa modo noturno para melhor visibilidade

### 🛠️ Utility
- **Auto Pickup** - Coleta automática de itens
- **Big Radar** - Radar expandido no minimapa
- **Instant Hit** - Tiros com alcance infinito

## 🔒 Sistema de Segurança

- **BNM Anti-Detection** - Sistema de ofuscação e anti-análise
- **Key Validation** - Validação de licença via API online
- **Anti-Emulator Bypass** - Bypass de detecção de emulador

## 📋 Offsets Verificados (OB52)

Todos os offsets foram extraídos e verificados do dump oficial:

```cpp
// Movement
0x2ed3040 - GetMoveSpeedForFPPMode
0x7eedf7c - GetRotationYawByDiretion
0x46290a8 - SetRotation

// Camera
0x325dfcc - IsCameraModeZooming

// Weapon
0x2e59468 - GetWeaponZoomAmplifier

// Aim
0x2dd0618 - GetAimAssistOnSighting
0x2e59514 - GetAimAssistDampCoefficient

// Anti-Detection
0x327f0d4 - IsEmulator
0x327f178 - SetIsEmulator

// Wallhack
0x5a150c8 - EnableShowPlayerOutline
0x3713318 - ShowPlayerOutline
0x5a15184 - EnableShowTeamOutline

// Utility
0x4e21724 - CanAutoPickUp
0x5a10ccc - GetMinimapMode
0x844307c - GetNightMode
0x7002188 - GetMinDistance
0x7002198 - GetMaxDistance

// ESP Functions
0x5456df4 - GetMaxHP
0x7b9e85c - GetWorldPosition
0x4f0f714 - GetHeadPosition
0x8ca0cfc - WorldToScreenPoint
0x4323900 - GetAlivePlayerCount
```

## 🛠️ Compilação

### Requisitos
- Android NDK r21+
- CMake 3.10+
- Gradle 7.0+

### Passos

1. Clone o repositório
```bash
git clone [seu-repositorio]
cd IMPERIUM_MODZ_X_Phantom_Force
```

2. Configure o NDK path no `local.properties`
```properties
ndk.dir=/path/to/android-ndk
```

3. Compile o projeto
```bash
./gradlew assembleRelease
```

4. O APK estará em `app/build/outputs/apk/release/`

## 📦 Estrutura do Projeto

```
app/src/main/jni/
├── Main.cpp                    # Entry point principal
├── ConstructMenu.h             # Interface ImGui
├── FinalFunctions.h            # Todas as funcionalidades
├── BNM_System.h                # Sistema anti-detecção
├── KeyValidator.h              # Validação de keys
├── ModernESP.h                 # Sistema ESP
├── Offsets.h                   # Offsets do OB52
└── Struct/
    ├── Unity.h                 # Estruturas Unity
    └── Class.h                 # Classes do jogo
```

## ⚙️ Configuração

### Android.mk
```makefile
LOCAL_MODULE := libil2cpp
LOCAL_SRC_FILES := Main.cpp
LOCAL_LDLIBS := -llog -landroid -lEGL -lGLESv3
LOCAL_CPPFLAGS := -std=c++17 -fexceptions
```

### AndroidManifest.xml
Adicione as permissões necessárias:
```xml
<uses-permission android:name="android.permission.INTERNET"/>
<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>
```

## 🔑 Sistema de Keys

O sistema de validação de keys está integrado com a API online. Para configurar:

1. Configure a URL da API em `KeyValidator.h`:
```cpp
const char* API_URL = "https://seu-dominio.com/api/validate";
```

2. A API deve retornar JSON no formato:
```json
{
  "valid": true,
  "expiry": "2024-12-31",
  "features": ["all"]
}
```

## ⚠️ Avisos Importantes

1. **Uso Responsável**: Este mod é apenas para fins educacionais
2. **Risco de Ban**: Usar mods pode resultar em banimento permanente
3. **Termos de Serviço**: Viola os ToS da Garena
4. **Sem Garantias**: Use por sua própria conta e risco

## 🐛 Troubleshooting

### Erro de Compilação
- Verifique se o NDK está instalado corretamente
- Confirme que todos os headers estão presentes
- Limpe o build: `./gradlew clean`

### Crash ao Iniciar
- Verifique se os offsets estão corretos para sua versão
- Confirme que o BNM está inicializado antes dos hooks
- Verifique logs: `adb logcat | grep IMPERIUM`

### Features Não Funcionam
- Confirme que a key foi validada
- Verifique se os toggles estão ativados no menu
- Teste uma feature por vez

## 📝 Changelog

### v1.0.0 (Final)
- ✅ 12 funções principais com Dobby Hook
- ✅ Sistema ESP completo (5 tipos)
- ✅ BNM Anti-Detection integrado
- ✅ Key Validation online
- ✅ Menu ImGui moderno
- ✅ Logo IMPERIUM MODZ
- ✅ Todos offsets verificados no dump OB52
- ✅ Zero erros de compilação
- ✅ Código otimizado e comentado

## 👨‍💻 Créditos

- **Desenvolvedor**: IMPERIUM MODZ Team
- **Base**: KhanhMods Framework
- **UI**: ImGui + Custom Drip Theme
- **Hooks**: Dobby Hook Engine
- **Anti-Detection**: BNM System

## 📄 Licença

Este projeto é apenas para fins educacionais. Não nos responsabilizamos pelo uso indevido.

---

**IMPERIUM MODZ X Phantom Force** - *Poder Absoluto no Free Fire* 👑
