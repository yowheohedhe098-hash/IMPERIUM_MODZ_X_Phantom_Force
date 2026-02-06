#pragma once
#define HOOK(ret, func, ...) \
    ret (*orig##func)(__VA_ARGS__); \
    ret my##func(__VA_ARGS__)
HOOK(void, Input, void *thiz, void *ex_ab, void *ex_ac) { 
    origInput(thiz, ex_ab, ex_ac);
	ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)thiz, {(float) screenWidth / (float) glWidth, (float) screenHeight / (float) glHeight});
    return;
}
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <optional>
#include <cstddef>

static int enable_hack;
static char *game_data_dir = NULL;
int isGame(JNIEnv *env, jstring appDataDir);
void *hack_thread(void *arg);
using namespace std;
bool isFov(Vector3 vec1, Vector3 vec2, int radius) {
    int x = vec1.x;
    int y = vec1.y;

    int x0 = vec2.x;
    int y0 = vec2.y;
    if ((pow(x - x0, 2) + pow(y - y0, 2) ) <= pow(radius, 2)) {
        return true;
    } else {
        return false;
    }
}
// Bool Aim New
using namespace std;
Quaternion GetRotationToTheLocation(Vector3 Target, float Height, Vector3 MyEnemy) {
return Quaternion::LookRotation((Target + Vector3(0, Height, 0)) - MyEnemy, Vector3(0, 1, 0));
}
const char* dir[] = {"None","Fire","Scope"};
const char* aimPart[] = {"Head", "Neck", "Body"};
int AimTarget = 0;
int AimCheck = 0;
int AimType = 0;
int AimWhen = 1;
bool Enable = false;
bool Aimbot = false;
bool checkVisible = true;
float Fov_Aim = 1000.0f;
bool Guest = false;
bool showFov = false;
const char* line[] = {"Top","Middle","Low"};
int showline = 0;
bool aline = false;
bool box1 = false;
bool health = false;
bool eName = false;
bool Grendeline = false;
bool EspGrenade = false;
bool showWeapon = false;
// Speed Time
bool TPlayer = false;
// 
bool AimKill = false;
bool AimSilent = false;
bool AimbotRage = false;
bool AimSilent2 = false;
bool SowDamage = false;
bool AimBotLegit = false;
bool Headshot = false;
bool SilentAim = false;
bool SilentKill = false;
bool eDistance = false;
bool SpeedHack = false;
bool Unlock120fps = false;
bool AimbotShoulder1 = false;
bool test666 = false;
float headshotPercentage = 85.0f;

int SetDamage = 1;
int delayCounter = 10;
int delayLimit = 20; // 
int DamageDelay = 2.0;
static int damageCooldown = 2.0;
bool uplayer = false;
std::string int_to_string(int num){
 std::string str = std::to_string(num);
     return str;
}
// --- Config màu ESP ---
int DrawScale = 13;
ImVec4 espColorHealth = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
ImVec4 espColorLine = ImVec4(0.7f, 0.0f, 1.0f, 1.0f);
ImVec4 espColorBox  = ImVec4(0.7f, 0.0f, 1.0f, 1.0f);
ImVec4 espColorName   = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
// 

#define offset_PlayerNetwork_StartFiring (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("StartFiring"), 1)
#define offset_PlayerNetwork_StopFire (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("StopFire"), 1)
#define offset_StartWholeBodyFiring (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("StartWholeBodyFiring"), 1)

#define offset_Weapon_StartFiring (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("GPBDEDFKJNA"), OBFUSCATE("MPGJOKFGLGK"), 0)
#define offset_Weapon_StopFiring (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("GPBDEDFKJNA"), OBFUSCATE("EJONAOOEOJH"), 0)

#define offset_IsClientBot (uintptr_t)Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("IsClientBot"))
#define offset_get_Delay (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("GPBDEDFKJNA"), OBFUSCATE("LMGGNHPNMNI"), 0)

#define offset_PNGAJBCPDNJ (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PhyXShield"), OBFUSCATE("PNGAJBCPDNJ"), 0)

#define offset_GetWeaponOnHand (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("GetWeaponOnHand"), 0)

#define offset_BaseDamage (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("GPBDEDFKJNA"), OBFUSCATE("LAEMLAPIAFD"))

#define offset_GetWeaponID (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("KOGBJLFDJHC"), OBFUSCATE("IDOGDPOPGAI"), 0)

#define offset_KFMGKCJMCAM (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("KFMGKCJMCAM"))

#define offset_GEGFCFDGGGP (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("GEGFCFDGGGP"))

#define offset_PlayerAttributes (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("JKPFFNEMJIF"))

#define offset_AHEKHEAHOPP (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerAttributes"), OBFUSCATE("DHADKOKAAAA"))

#define offset_DamageBaseInfo (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("AHEKHEAHOPP"), OBFUSCATE("JIIJIFKKCCB"))

#define offset_SetStartDamage (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("GPBDEDFKJNA"), OBFUSCATE("BLAGCMCGEJG"), 1)

#define offset_get_gameObject (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_gameObject"), 0)

#define offset_BodyPart (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("ELMGJKHIIAA"), OBFUSCATE("KENBMOOEHBG"))

#define offset_JMKMBNIBFNA (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("MADMMIICBNN"), OBFUSCATE("JMKMBNIBFNA")) //HitOpject

#define offset_GHACJPMCEDK (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("MADMMIICBNN"), OBFUSCATE("GHACJPMCEDK")) // HitCollider

#define offset_OJKBBAOPPIN (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("MADMMIICBNN"), OBFUSCATE("OJKBBAOPPIN")) //HitGroup

#define offset_GKHECDLGAJA (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("GKHECDLGAJA"), 1)

#define offset_LCLHHHKFCFP (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("GPBDEDFKJNA"), OBFUSCATE("LCLHHHKFCFP"), 4)

#define offset_LocalPlayer (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameFacade"), OBFUSCATE("CurrentLocalPlayer"), 0)

#define offset_CFFPIACECIG (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("IHAAMHPPLMG"), OBFUSCATE("CFFPIACECIG"), 1)

#define GetUniqueID(WeaponHand) *(uint32_t*)((uint64_t)WeaponHand + 0x8)

#define offset_LHGGPDLOPAH (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("message"), OBFUSCATE("LLOABGDLMGK"), OBFUSCATE("LHGGPDLOPAH"), 1)

#define offset_SendFunction (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameFacade"), OBFUSCATE("Send"), 4)

struct DamageInfo2_o {
    void *klass;
    void *monitor;
    int32_t DBLBLKADCNP;
    int32_t KENBMOOEHBG;
    monoString* JANPNJIFOJJ;
    bool NNNADMOFPIE;
    void* GPBDEDFKJNA;
    int32_t PIAMIOFEBKF;
    Vector3 CNEICNJFGLM;
    Vector3 HECJHKEDFEB;
    Vector3 JNLGFLFLBHO;
    uint8_t ACAKHEABPEJ;
    bool MJIHLDJNHLF;
    int32_t LOKIMAEAPCB;
    monoDictionary<uint8_t*, void **> *FHLFLAHCIBN;
};

struct PlayerID_MKFEKBKJCKE_o;
struct PlayerID {
    uint32_t NBPDJAAAFBH;
    uint32_t JEDDPHIHGKL;
    uint8_t IOICFFEKAIL;
    uint8_t PHAFNFOFFDB;
    uint64_t BNFAIDHEHOM;
};
struct message_CHDLJFJCPFN_o2 {
    void *klass;
    void *monitor;
    bool UDPClientMessageBase_m_GetFromPool;
    uint32_t ALFINFGBOBE;
    uint16_t ECDBFHHNPMI;
    uint16_t EKCONDDBKFO;
    uint32_t BJBPPEBIPFA;
    uint32_t LIIGLCNGOHG;
    int32_t PIAMIOFEBKF;
    uint32_t HCMIEJEBKAL;
    uint8_t ODCJPCEJHPK;
    uint32_t CEDJCPLOLNE;
    message_DEACEIFBHJK_o* CNEICNJFGLM;
    message_DEACEIFBHJK_o* PGDEDHFOMCN;
    void *AALHLOAJLEE;
    uint32_t HOBOHHJNDNH;
    float AILHIPMKJKJ;
    uint64_t LHGGPCFJNOO;
    int8_t ACAKHEABPEJ;
    bool MJIHLDJNHLF;
    bool MBGCAHPACOH;
    monoList<int*> * FIKOAMIDEHL;
    float IOGIIEFAALP;
    bool HDEJLJKNLCI;
};

struct message_C2S_RUDP_TakeDamage_Req_fields {
    uint32_t AttackableEntityID;   // 0x14
    uint16_t RealDamageValue;      // 0x18
    uint16_t ShieldDamageValue;    // 0x1A
    uint32_t DamageValue;          // 0x1C
    uint32_t DamagerID;            // 0x20
    int32_t  WeaponDataID;         // 0x24
    uint32_t WeaponUniqueID;       // 0x28
    uint8_t  HitBodyPart;          // 0x2C
    uint32_t TickCount;            // 0x30
    void*    FirePos;              // 0x38 (PVector3IntPos*)
    void*    TargetPos;            // 0x40
    void*    CheckParams;          // 0x48 (List*)
    uint32_t ExtraData;            // 0x50
    float    ArmorRatio;           // 0x54
    uint64_t ExtraFlag;            // 0x58
    int16_t  SpecialHitType;       // 0x60
    bool     ForceNoHeadShot;      // 0x62
    bool     IsPlayerBackArea;     // 0x63
    void*    DamageData;           // 0x68 (List*)
    float    BaseTime;             // 0x70
    bool     ManualReload;         // 0x74
};
struct message_C2S_RUDP_TakeDamage_Req_o {
    void* klass;
    void* monitor;
    message_C2S_RUDP_TakeDamage_Req_fields fields;
};
#pragma pack(push, 1)
struct COW_GamePlay_DamageInfo_fields {
    int32_t BaseDamage;             // 0x10
    int32_t HitColliderType;        // 0x14 (enum EColliderType)
    void*   HitColliderName;        // 0x18 (System.String*)
    bool    isBackArea;             // 0x20
    char    pad_21[0x7];            // align đến 0x28
    void*   Damager;                // 0x28 (PlayerID struct/class)
    char    pad_30[0x10];           // padding đến 0x40
    void*   Weapon;                 // 0x40 (Weapon*)
    int32_t WeaponDataID;           // 0x48
    Vector3 FirePos;                // 0x4C
    Vector3 HitPos;                 // 0x58
    Vector3 HitNormal;              // 0x64
    int16_t SpecialHitType;         // 0x70
    bool    ForceNoHeadShot;        // 0x72
    char    pad_73[0x1];            // align đến 0x74
    int32_t ExtraInfo;              // 0x74
    void*   SpecialHitDic;          // 0x78 (Dictionary<int,?>*)
};
#pragma pack(pop)

struct COW_GamePlay_DamageInfo_o {
    void* klass;
    void* monitor;
    COW_GamePlay_DamageInfo_fields fields;
};

struct message_PVector3IntPos_o {
    void* klass;
    void* monitor;
    struct {
        int32_t X; // 0x14
        int32_t Y; // 0x18
        int32_t Z; // 0x1c
    } fields;
};

/*static float get_Range(void *pthis)
{
    return ((float (*)(void *))(offset_JDGGIFMKIKF))(pthis);
}*/

static void StartFiring(void* player, void* weapon) {
    if (!player || !weapon) return;
    auto fn = reinterpret_cast<void(*)(void*, void*)>(offset_PlayerNetwork_StartFiring);
    fn(player, weapon);
}

static void StopFire(void* player, void* weapon) {
    if (!player || !weapon) return;
    auto fn = reinterpret_cast<void(*)(void*, void*)>(offset_PlayerNetwork_StopFire);
    fn(player, weapon);
}

static void StartWholeBodyFiring(void* player, void* weapon) {
    if (!player || !weapon) return;
    auto fn = reinterpret_cast<void(*)(void*, void*)>(offset_StartWholeBodyFiring);
    fn(player, weapon);
}

static void StartFiring2(void* weapon) {
    if (!weapon) return;
    auto fn = reinterpret_cast<void(*)(void*)>(offset_Weapon_StartFiring);
    fn(weapon);
}

static void StopFiring2(void* weapon) {
    if (!weapon) return;
    auto fn = reinterpret_cast<void(*)(void*)>(offset_Weapon_StopFiring);
    fn(weapon);
}

static float get_Delay2(void *pthis)
{
    return ((float (*)(void *))(offset_get_Delay))(pthis);
}

/*static void *GetWeaponOnHand(void *local)
{
    void *(*_GetWeaponOnHand)(void *local) = (void *(*)(void *))(offset_GetWeaponOnHand);
    return _GetWeaponOnHand(local);
}*/

static int GetWeapon(void* enemy)
{
    int (*GetWeapon)(void *player) = (int(*)(void *))(offset_GetWeaponID);
    return GetWeapon(enemy);
}

/*void *get_gameObject(void *Pthis)
{
    return ((void* (*)(void *))(offset_get_gameObject))(Pthis);
}*/

void *GKHECDLGAJA(void *pthis, void* a1)
{
    return ((void* (*)(void *,void *))(offset_GKHECDLGAJA))(pthis,a1);
}

System_Collections_Generic_List_float__o *LCLHHHKFCFP(void *Weapon,void *CAGCICACKCF,void *HFBDJJDICLN,bool LDGHPOPPPNL,COW_GamePlay_DamageInfo_o *DamageInfo)
{
    return ((System_Collections_Generic_List_float__o * (*)(void*,void*,void*,bool,COW_GamePlay_DamageInfo_o*))(offset_LCLHHHKFCFP))(Weapon,CAGCICACKCF,HFBDJJDICLN,LDGHPOPPPNL,DamageInfo);
}
monoList<float *> *LCLHHHKFCFP1(void *Weapon,void *CAGCICACKCF,void *HFBDJJDICLN,bool LDGHPOPPPNL,DamageInfo2_o *DamageInfo)
{
    return ((monoList<float *> * (*)(void*,void*,void*,bool,DamageInfo2_o*))(offset_LCLHHHKFCFP))(Weapon,CAGCICACKCF,HFBDJJDICLN,LDGHPOPPPNL,DamageInfo);
}
static void *Current_Local_Player()
{
    void *(*_Local_Player)(void *players) = (void *(*)(void *))(offset_LocalPlayer);
    return _Local_Player(NULL);
}
#define m_get_player_ID (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("get_PlayerID"), 0)
COW_GamePlay_IHAAMHPPLMG_o GetplayerID(void *_this)
{
    return ((COW_GamePlay_IHAAMHPPLMG_o (*)(void *))(m_get_player_ID))(_this);
}
uint32_t CFFPIACECIG(COW_GamePlay_IHAAMHPPLMG_o IDNEFEOPGIF)
{
    return ((uint32_t (*)(COW_GamePlay_IHAAMHPPLMG_o))(offset_CFFPIACECIG))(IDNEFEOPGIF);
}
message_DEACEIFBHJK_o *LHGGPDLOPAH(Vector3 JOGHOHLEJFL)
{
    return ((message_DEACEIFBHJK_o* (*)(Vector3))offset_LHGGPDLOPAH)(JOGHOHLEJFL);
}

bool isEnemyInRangeWeapon(void *player, void *enemy, void* weapon)
{
    if (player != nullptr && enemy != nullptr && weapon != nullptr)
    {
        Vector3 EnemyHeadPosition = GetHeadPosition(enemy);
        Vector3 PlayerHeadPosition = GetHeadPosition(player);
        float distance = Vector3::Distance(PlayerHeadPosition, EnemyHeadPosition);
        float range = get_Range(weapon);

        if (distance <= range) {
            return true;
        }
    }
    return false;
}
bool GameFacade_Send(uint32_t messageID,void *msg,uint8_t sendOption,bool cacheMsgAnyWay)
{
    return ((bool (*)(uint32_t,void *,uint8_t,bool))(offset_SendFunction))(messageID,msg,sendOption,cacheMsgAnyWay);
}
void* GameFacadeCurrentLocalPlayer(){
    void*(*CurrentLocalPlayer) (void*) = (void*(*)(void*))(offset_LocalPlayer);
    return CurrentLocalPlayer(NULL);
}
static void StartonFiring(void *LocalPlayer, void *WeaponHand)
{
    StartFiring(LocalPlayer, WeaponHand);
    StartWholeBodyFiring(LocalPlayer, WeaponHand);
    StopFire(LocalPlayer, WeaponHand);
}
static void StartonFiring2(void *LocalPlayer, void *WeaponHand)
{
    StartFiring(LocalPlayer, WeaponHand);
    StartWholeBodyFiring(LocalPlayer, WeaponHand);
}
static void StoponFiring(void *LocalPlayer, void *WeaponHand)
{
    StopFire(LocalPlayer, WeaponHand);
}

// Aimkill 1
namespace Save {
    void* DamageInfo = nullptr;
    clock_t AimDelay = 0;
    int AimFPS = (1000 / 60);
}
inline void write_int(void* base, size_t offset, int value) {
    if (!base) return;
    int* p = reinterpret_cast<int*>(reinterpret_cast<char*>(base) + offset);
    *p = value;
}
inline void write_ptr(void* base, size_t offset, void* value) {
    if (!base) return;
    void** p = reinterpret_cast<void**>(reinterpret_cast<char*>(base) + offset);
    *p = value;
}
inline void write_uint32(void* base, size_t offset, uint32_t value) {
    if (!base) return;
    uint32_t* p = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(base) + offset);
    *p = value;
}
struct message_C2S_RUDP_TakeDamage_Req_o2 {//struct message_CHDLJFJCPFN_o2 {
    void *klass;
    void *monitor;
    bool UDPClientMessageBase_m_GetFromPool;
    uint32_t AttackableEntityID;//    uint32_t ALFINFGBOBE;
    uint16_t RealDamageValue;//ECDBFHHNPMI
    uint16_t ShieldDamageValue;//EKCONDDBKFO
    uint32_t DamageValue;//BJBPPEBIPFA
    uint32_t DamagerID;//LIIGLCNGOHG
    int32_t WeaponDataID;//PIAMIOFEBKF
    uint32_t WeaponUniqueID;//HCMIEJEBKAL
    uint8_t HitBodyPart;//ODCJPCEJHPK
    uint32_t TickCount;//CEDJCPLOLNE
    message_PVector3IntPos_o* FirePos;//message_DEACEIFBHJK_o* CNEICNJFGLM;
    message_PVector3IntPos_o* TargetPos;//PGDEDHFOMCN
    monoList<float*> * CheckParams;//AALHLOAJLEE
    uint32_t ExtraData;//HOBOHHJNDNH
    float ArmorRatio;//AILHIPMKJKJ
    uint64_t ExtraFlag;//LHGGPCFJNOO
    int8_t SpecialHitType;//ACAKHEABPEJ
    bool ForceNoHeadShot;//MJIHLDJNHLF
    bool IsPlayerBackArea;//MBGCAHPACOH
    monoList<int*> * DamageData;//FIKOAMIDEHL
    float BaseTime;//IOGIIEFAALP
    bool ManualReload;//HDEJLJKNLCI
};

#define offset_TakeDamage (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("TakeDamage"), 9)
static int32_t TakeDamage(void *_this, int32_t KOCMLPLOILD, PlayerID HLJDHPGGODB, void* JIIJIFKKCCB, int32_t BOEIBGAABDL, Vector3 NJMFBKNHMBP, Vector3 DOBOBMFMKBJ, monoList<float *> *NBKBEBFNDBE, void* damagerWeaponDynamicInfo, uint32_t damagerVehicleID) {
    return ((int32_t (*)(void*, int32_t, PlayerID, void*, int32_t, Vector3, Vector3, monoList<float *> *, void*, uint32_t))(offset_TakeDamage))(_this, KOCMLPLOILD, HLJDHPGGODB, JIIJIFKKCCB, BOEIBGAABDL, NJMFBKNHMBP, DOBOBMFMKBJ, NBKBEBFNDBE, damagerWeaponDynamicInfo, damagerVehicleID);
}
#define offset_SimulationTimer (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameFacade"), OBFUSCATE("CurrentGameSimulationTimer"), 0)
void* CurrentGameSimulationTimer()
{
    return ((void* (*)(void *))(offset_SimulationTimer))(NULL);
}
#define BNJIPPIIMDF1616 Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("message"), OBFUSCATE("BNJIPPIIMDF"), OBFUSCATE(".ctor"), 0)
#define Classdamageinfo Il2CppGetClassType(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("ELMGJKHIIAA"))

//#define offset_IsClientBot (uintptr_t)Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("IsClientBot"))

#include <map>
#include <chrono>

// map lưu thời gian bắn lần cuối từng mục tiêu
static std::map<void*, std::chrono::steady_clock::time_point> lastShotTimePerTarget;

#define offset_TakeDamage_New Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("TakeDamage"), 4)
#define offset_get_PlayerID Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("get_PlayerID"), 0)

struct DamageInfo2_o2 {
    void *klass;
    void *monitor;
    int32_t DBLBLKADCNP;
    int32_t KENBMOOEHBG;
    monoString* JANPNJIFOJJ;
    bool NNNADMOFPIE;
    char pad_0x21[0x7];
    PlayerID DHGCIEKPBFA;
    void* GPBDEDFKJNA;
    int32_t PIAMIOFEBKF;
    Vector3 CNEICNJFGLM;
    Vector3 HECJHKEDFEB;
    Vector3 JNLGFLFLBHO;
    int16_t ACAKHEABPEJ;
    bool MJIHLDJNHLF;
    char pad_0x73[0x1];
    int32_t LOKIMAEAPCB;
    void* FHLFLAHCIBN;
};

typedef void (*TakeDamage_New_Func)(void* instance, DamageInfo2_o2* damageInfo, void* weaponDynamicInfo, monoList<float*>* checkParams, uint32_t vehicleID);
typedef PlayerID (*GetPlayerID_Func)(void* instance);

void StartTakeDamaFake2(void* ClosestEnemy) {
    if (!Aimbot || !ClosestEnemy) return;

    if (offset_IsClientBot) {
         bool isBot = *(bool*)((uintptr_t)ClosestEnemy + offset_IsClientBot);
         if (isBot) return; 
    }

    void* trandau = Curent_Match();
    void* LocalPlayer = GetLocalPlayer(trandau);
    void* WeaponHand = GetWeaponOnHand(LocalPlayer);

    if (!trandau || !LocalPlayer || !WeaponHand) return;

    if (!offset_PNGAJBCPDNJ) return;
    auto damagePacket = (message_C2S_RUDP_TakeDamage_Req_o2*)((void* (*)(void*))offset_PNGAJBCPDNJ)(LocalPlayer);
    
    void* Class_message_DamageInfo_c = Classdamageinfo;
    if (!Class_message_DamageInfo_c) return;
    
    if (!Classdamageinfo) return;
    auto DamageInfo = (DamageInfo2_o2*)((void* (*)(void*))(BNJIPPIIMDF1616))(Class_message_DamageInfo_c);
    if (!DamageInfo) return;

    int weaponID = GetWeapon(WeaponHand);
    int baseDamage = *(int*)((uintptr_t)WeaponHand + offset_BaseDamage);
    if (baseDamage <= 0) baseDamage = 30;

    void* objectPool = *(void**)((uintptr_t)LocalPlayer + offset_GEGFCFDGGGP);
    if (!objectPool) return;

    static bool s_Il2CppMethodIntialized = false;
    if (!s_Il2CppMethodIntialized) {
        ((void (*)(void*, void*))offset_SetStartDamage)(WeaponHand, objectPool);
        ((void* (*)(void*))offset_PNGAJBCPDNJ)(LocalPlayer);
        s_Il2CppMethodIntialized = true;
    }

    GetPlayerID_Func getID = (GetPlayerID_Func)offset_get_PlayerID;
    PlayerID myPlayerID = getID(LocalPlayer);

    Save::DamageInfo = DamageInfo;
    
    *(PlayerID*)((uintptr_t)Save::DamageInfo + 0x28) = myPlayerID;

    write_int(Save::DamageInfo, 0x14, 1);
    write_int(Save::DamageInfo, 0x10, baseDamage);
    write_ptr(Save::DamageInfo, 0x40, WeaponHand);
    write_int(Save::DamageInfo, 0x48, weaponID);

    void* headCollider = Player_GetHeadCollider(ClosestEnemy);
    if (!headCollider) return;

    write_ptr(objectPool, offset_JMKMBNIBFNA, get_gameObject(headCollider));
    write_ptr(objectPool, offset_GHACJPMCEDK, headCollider);
    write_int(objectPool, offset_OJKBBAOPPIN, 1);

    void* sl3 = GKHECDLGAJA(LocalPlayer, objectPool);
    if (!sl3) return;

    monoList<float*>* paramCheck = LCLHHHKFCFP1(WeaponHand, sl3, headCollider, false, (DamageInfo2_o*)DamageInfo);
    
    if (!paramCheck) return; 

    auto now = std::chrono::steady_clock::now();
    auto& lastTime = lastShotTimePerTarget[ClosestEnemy]; 
    int interval_ms = 200; 

    if (isEnemyInRangeWeapon(LocalPlayer, ClosestEnemy, WeaponHand)) {
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime).count();
        if (elapsed >= interval_ms) {
            
            TakeDamage_New_Func fn = (TakeDamage_New_Func)offset_TakeDamage_New;
            
            if (fn) {
                fn(ClosestEnemy, DamageInfo, nullptr, paramCheck, 0);
                StartonFiring(LocalPlayer, WeaponHand);
                lastTime = now;
            }
        }
    } else {
        lastTime = now - std::chrono::milliseconds(1000);
    }
}

float (*old_GetCurrentDashSpeed)(void *instance);
float hook_GetCurrentDashSpeed(void *instance) {
    void* localPlayer = GetLocalPlayer(Curent_Match());
    if (instance != nullptr && instance == localPlayer) {
        if (SpeedHack) {
            //10f Is Limit BY SYNTHAX (Gay)
            return 9.0; 
        }
    }
    return old_GetCurrentDashSpeed(instance);
}

bool isUnlocked = false;

bool (*orig_IsHighFPS120Open)(void* _this);

bool hook_IsHighFPS120Open(void* _this) {
    if (isUnlocked) {
        return true;
    }

    if (Unlock120fps == true) {
        Unlock120fps = true;
        isUnlocked = true;
        return true;
    }

    return orig_IsHighFPS120Open(_this);
}

bool GhostH = false;

bool (*orig_NeedSendMessage)(void* _this, int Value);

bool hook_NeedSendMessage(void* _this, int Value) {
    if (_this != nullptr) {
        if (GhostH) {
            return false; 
        }
    }
    return orig_NeedSendMessage(_this, Value);
}

/*uint32_t (*get_UserLevel)(void *_this);
uint32_t _get_UserLevel(void *_this) {
    if (_this != NULL) {
        uint32_t level = get_UserLevel(_this);
        return 49;
    } 
    return get_UserLevel(_this);
}

uint32_t (*get_UserExp)(void *_this);
uint32_t _get_UserExp(void *_this) {
    if (_this != NULL) {
        uint32_t exp = get_UserExp(_this);
        return 6255813;
    }
    return get_UserExp(_this);
}*/

std::string GetNameFromPlayer(void* player) {
    if (!player) return "Player";
    void* (*get_NickName)(void*) = (void* (*)(void*))Il2CppGetMethodOffset("Assembly-CSharp.dll", "COW.GamePlay", "Player", "get_NickName", 0);
    if (!get_NickName) return "Player";
    void* nickNamePtr = get_NickName(player);
    if (!nickNamePtr) return "Player";
    int length = *(int*)((uintptr_t)nickNamePtr + 0x10);
    if (length <= 0) return "Player";
    std::u16string str16((char16_t*)((uintptr_t)nickNamePtr + 0x14), length);
    std::string str8;
    for (char16_t c : str16) {
        if (c < 128) str8 += (char)c;
        else str8 += '?';
    }
    return str8.empty() ? "Player" : str8;
}

bool Visible_Check(void* enemy) {
    if (!enemy) return false;

    void* cam = Camera_main();
    if (!cam) return false;

    void* head = Player_GetHeadCollider(enemy);
    if (!head) return false;

    Vector3 camPos = Transform_GetPosition(Component_GetTransform(cam));
    Vector3 headPos = Transform_GetPosition(Component_GetTransform(head));

    void* hit = nullptr;
    return !Physics_Raycast(camPos, headPos, 12, &hit);
}

void *EnemyVisible(void *match) {
    if (!match) return nullptr;

    void* LocalPlayer = GetLocalPlayer(match);
    if (!LocalPlayer) return nullptr;

    if (ListPlayer == 0) return nullptr;

    auto players = *(monoDictionary<uint8_t*, void **> **)((long)match + ListPlayer);
    if (!players || !players->values) return nullptr;

    void* cam = Camera_main();
    if (!cam) return nullptr;

    float shortestDistance = 99999.0f;
    float maxAngle = Fov_Aim;
    void* closestEnemy = nullptr;

    for (int u = 0; u < players->getNumValues(); u++) {
        void* Player = players->getValues()[u];
        if (!Player) continue;

        if (get_isLocalTeam(Player) || get_IsDieing(Player) || !get_MaxHP(Player) || get_God(Player))
            continue;

        Vector3 PlayerPos = GetHeadPosition(Player);
        Vector3 LocalPlayerPos = GetHeadPosition(LocalPlayer);

        Vector3 targetDir = Vector3::Normalized(PlayerPos - LocalPlayerPos);
        
        float angle = Vector3::Angle(
            targetDir,
            GetForward(Component_GetTransform(cam))
        ) * 100.0f;

        if (angle > maxAngle)
            continue;

        if (checkVisible && !Visible_Check(Player))
            continue;

        if (angle < shortestDistance) {
            shortestDistance = angle;
            closestEnemy = Player;
        }
    }
    return closestEnemy;
}

void *hackerrrr() {
    bool checkVisible113 = false;
    float shortestDistance = 9999;
    void* closestEnemy = nullptr;   
    void* get_MatchGame = Curent_Match();
    void* LocalPlayer = GetLocalPlayer(get_MatchGame);
    if (LocalPlayer != nullptr && get_MatchGame != nullptr && Aimbot) {
        monoDictionary<uint8_t *, void **> *players = *(monoDictionary<uint8_t*, void **> **)((long)get_MatchGame + ListPlayer);
        for (int u = 0; u < players->getNumValues(); u++) {
            void* Player = players->getValues()[u]; 
            if (Player != nullptr && !get_isLocalTeam(Player) && !get_IsDieing(Player) && get_MaxHP(Player)) {
                Vector3 PlayerPos = getPosition(Player);
                Vector3 LocalPlayerPos = getPosition(LocalPlayer);
                Vector3 pos2 = WorldToScreenPoint(Camera_main(), PlayerPos);
                bool isFov1 = isFov(Vector3(pos2.x, pos2.y), Vector3(glWidth / 2, glHeight / 2), Fov_Aim);
                float distance = Vector3::Distance(LocalPlayerPos, PlayerPos);
                if (distance < 1000) {
                    Vector3 targetDir = Vector3::Normalized(PlayerPos - LocalPlayerPos);
                    float angle = Vector3::Angle(targetDir, GetForward(Component_GetTransform(Camera_main()))) * 100.0;
                    if (angle <= Fov_Aim && isFov1 && angle < shortestDistance) {
                        if (checkVisible113) {
                            if (!Visible_Check(Player)) {
                                continue;
                            }
                        }
                        shortestDistance = angle;
                        closestEnemy = Player;
                    }
                }
            }
        }
    }
    return closestEnemy;
}

struct FlySaved {
    float HaruX, HaruY, HaruZ;
    Vector3 MountCam;
    float FlyCS = 0.0f;
    float FlySpeedCS = 1.0f;
    int FlyBR = 2;
    int FlySpeedBR;
} flysaved;
bool FlyBR = false;
bool FlyBR1 = false;
int valueBr = 0;
int valueBr1 = 0;
// Math
static Vector3 VecAdd(Vector3 a, Vector3 b) {
    return { a.x + b.x, a.y + b.y, a.z + b.z };
}
static Vector3 VecMul(Vector3 a, float s) {
    return { a.x * s, a.y * s, a.z * s };
}
static bool get_IsCatapultFalling(void *m_catapult) {
    bool (*_get_IsCatapultFalling)(void *m_local) = (bool (*)(void *))Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("IsCatapultFalling"), 0);
    return _get_IsCatapultFalling(m_catapult);
}
static void OnStopCatapultFalling(void* m_Match) {
    void (*_OnStopCatapultFalling)(void *match) = (void (*)(void *))Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("OnStopCatapultFalling"), 0);
    _OnStopCatapultFalling(m_Match);
}
// Fly
static bool FlyUpCS = false;
static bool FlyUpBR = false;
static void FLYCS(void *local_player, float FlyAltura, float FlySpeed){

    // Clamp bảo vệ lần 2
    if (FlyAltura < 0.0f) FlyAltura = 0.0f;
    if (FlyAltura > 4.0f) FlyAltura = 4.0f;

    if (FlySpeed < 0.0f) FlySpeed = 0.0f;
    if (FlySpeed > 20.0f) FlySpeed = 20.0f;

    // Bay lên cực chậm: 0 → 4 thành 0 → 0.08
    float slowUp = FlyAltura * 0.02f;

    if (FlyUpCS) {

        Vector3 MountPlayer =
            Transform_GetPosition(Component_GetTransform(local_player));

        Vector3 camForward =
            GetForward(Component_GetTransform(Camera_main()));

        // Bay ngang mượt theo speed
        flysaved.MountCam = VecAdd(
            MountPlayer,
            VecMul(camForward, FlySpeed * 0.1f)   // FlySpeed giới hạn 20
        );

        flysaved.HaruX = MountPlayer.x;
        flysaved.HaruZ = MountPlayer.z;

        // Bay lên chậm
        flysaved.HaruY = MountPlayer.y + slowUp;

        set_position_Injected(
            Component_GetTransform(local_player),
            Vvector3(
                flysaved.MountCam.x,
                flysaved.HaruY,
                flysaved.MountCam.z
            )
        );
    }
}
static void FLYBR(void *local_player, int FlyAltura, int FlySpeed){
    if (FlyUpBR) {
        if (get_IsCatapultFalling(local_player)) {
            OnStopCatapultFalling(local_player);
        }

        Vector3 MountPlayer = Transform_GetPosition(Component_GetTransform(local_player));
        Vector3 camForward = GetForward(Component_GetTransform(Camera_main()));
        flysaved.MountCam = VecAdd(MountPlayer, VecMul(camForward, (float)FlySpeed / 10.0f));
        if(FlyAltura > 0){
            flysaved.HaruZ = MountPlayer.z;
            flysaved.HaruX = MountPlayer.x;
            flysaved.HaruY = MountPlayer.y;
            if(FlyAltura > 1) 
                flysaved.HaruY += (float)FlyAltura / 10.0f;
            set_position_Injected(Component_GetTransform(local_player),
                Vvector3(flysaved.MountCam.x, flysaved.HaruY, flysaved.MountCam.z));
        }
    }
}

bool TeleportProCs = false;
bool TeleportProBr = false;

void KlelYuimteleport() {
    void* CurrentMatch  = Curent_Match();
    void* LocalPlayer   = GetLocalPlayer(CurrentMatch);
    void* closestEnemy  = hackerrrr();

    if (closestEnemy != nullptr && LocalPlayer != nullptr && CurrentMatch != nullptr) {

        // Teleport BR
        if (TeleportProBr && LocalPlayer) {
            void* _TeleKillTP = get_transform(closestEnemy);
            if (_TeleKillTP != NULL) {
                Vector3 TeleKillTP = get_position11(_TeleKillTP) - (GetForward(_TeleKillTP) * 0);
                set_position_Injected(get_transform(LocalPlayer),
                                      Vvector3(TeleKillTP.x, TeleKillTP.y, TeleKillTP.z));
            }
        }

        // Teleport CS
        if (TeleportProCs) {
            void* enemyTf = get_transform(closestEnemy);
            Vector3 PosEnemy = get_position11(enemyTf) -
                               (GetForward(enemyTf) * 1.0f);

            set_position_Injected(get_transform(LocalPlayer),
                                  Vvector3(PosEnemy.x, PosEnemy.y, PosEnemy.z));
        }
    }
}

void AimLegit() {
    if (!AimBotLegit) return; 

    void* CurrentMatch = Curent_Match();
    void* LocalPlayer = GetLocalPlayer(CurrentMatch);
    if (!LocalPlayer) return;

    void* closestEnemy = EnemyVisible(CurrentMatch);
    if (!closestEnemy) return;

    bool IsScopeOn = get_IsSighting(LocalPlayer);
    bool IsFiring = get_IsFiring(LocalPlayer);

    if (IsFiring || IsScopeOn) {
        
        int enemyHP = GetHp(closestEnemy);
        Vector3 TargetPos = GetHeadPosition(closestEnemy);

        if (enemyHP < 51) {
            TargetPos.y -= 0.45f; 
        } else {
            TargetPos.y -= 0.18f;
        }
        
        Vector3 PlayerPos = CameraMain(LocalPlayer);
        Quaternion LookRot = GetRotationToTheLocation(TargetPos, 0.1f, PlayerPos);
        set_aim(LocalPlayer, LookRot);
    }
}

void AimShoulder() {
    if (!AimbotShoulder1) return;

    void* CurrentMatch = Curent_Match();
    void* LocalPlayer = GetLocalPlayer(CurrentMatch);
    if (!LocalPlayer) return;

    void* closestEnemy = EnemyVisible(CurrentMatch);
    if (!closestEnemy) return;

    bool IsScopeOn = get_IsSighting(LocalPlayer);
    bool IsFiring = get_IsFiring(LocalPlayer);

    if (IsFiring || IsScopeOn) {
        Vector3 EnemyLocation = GetHeadPosition(closestEnemy);
        Vector3 PlayerLocation = CameraMain(LocalPlayer);

        EnemyLocation = EnemyLocation - Vector3{0, 0.15f, 0};

        Vector3 forward = Vector3::Normalized(PlayerLocation - EnemyLocation);
        Vector3 right = {forward.z, 0, -forward.x};
        EnemyLocation = EnemyLocation - (right * 0.15f);

        Quaternion PlayerLook = GetRotationToTheLocation(EnemyLocation, 0.1f, PlayerLocation);
        set_aim(LocalPlayer, PlayerLook);
    }
}

struct HitObjectInfo {
    void *klass;
    void *monitor;
    bool m_IsInPool;
    void *HitObject;
    void *HitCollider;
    Vector3 HitLocation;
    Vector3 HitNormal;
    Vector3 RayDir;
    Vector3 StartPosition;
    int32_t Damage;
    float Distance;
    int32_t ActorLayer;
    int32_t HitGroup;
    void *HitPhysicMaterial;
    bool IgnoreHappens;
    bool ViewBlocked;
    struct Vector3 OrigStartPosition;
    uint8_t SpecialHitType;
    uint32_t SpecialHitLevelObjID;
};
struct PlayerID_MKFEKBKJCKE_o;

int (*orig_PlayerNetwork_TakeDamage)(void *ClosestEnemy, int baseDamage, PlayerID damager, DamageInfo2_o *damageInfo, int weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float> *checkParams, void *damagerWeaponDynamicInfo, int damagerVehicleID);
int hook_PlayerNetwork_TakeDamage(void *ClosestEnemy, int baseDamage, PlayerID damager, DamageInfo2_o *damageInfo, int weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float> *checkParams, void *damagerWeaponDynamicInfo, int damagerVehicleID) {
    
    void* CurrentMatch = Curent_Match();
    void* LocalPlayer = GetLocalPlayer(CurrentMatch);
    
    if (LocalPlayer && ClosestEnemy) {
        firePos = GetHeadPosition(LocalPlayer);
        hitPos = GetHeadPosition(ClosestEnemy);
    }

    if (ClosestEnemy != NULL && Headshot) {
        if (damageInfo != NULL) {
            *(int *)((long) damageInfo + offset_BodyPart) = 1;
        }
    }
    
    return orig_PlayerNetwork_TakeDamage(ClosestEnemy, baseDamage, damager, damageInfo, weaponDataID, firePos, hitPos, checkParams, damagerWeaponDynamicInfo, damagerVehicleID);
}

int (*old_BLAGCMCGEJG1)(void *, HitObjectInfo *);

int BLAGCMCGEJG1(void *ist, HitObjectInfo *HitObject) {
    if (SilentAim) {
        if (HitObject != nullptr) {
            void *current_match = Curent_Match();
            if (current_match != NULL) {
                void* local_player = GetLocalPlayer(current_match);
                if (local_player != NULL) {
                    void* WeaponHand = GetWeaponOnHand(local_player);
                    
                    auto *ClosestEnemy = EnemyVisible(current_match);
                    
                    if (ClosestEnemy != nullptr) {
                        if (isEnemyInRangeWeapon(local_player, ClosestEnemy, WeaponHand)) {
                            Vector3 EnemyLocation;
                            
                            if (AimTarget == 0) {
                                EnemyLocation = GetHeadPosition(ClosestEnemy);
                            } 
                            else if (AimTarget == 2) {
                                EnemyLocation = GetHipPosition(ClosestEnemy); 
                            }                            
                            Vector3 PlayerLocation = CameraMain(local_player);
                            HitObject->HitObject = get_gameObject(Player_GetHeadCollider(ClosestEnemy));
                            HitObject->HitCollider = Player_GetHeadCollider(ClosestEnemy);
                            
                            HitObject->HitLocation = EnemyLocation;
                            HitObject->HitNormal = EnemyLocation;
                            HitObject->RayDir = Vector3::Normalized(EnemyLocation - PlayerLocation);
                            HitObject->StartPosition = PlayerLocation;
                            HitObject->OrigStartPosition = PlayerLocation;
                            HitObject->SpecialHitType = 0;
                            HitObject->HitGroup = 1;
                            HitObject->IgnoreHappens = false;
                            HitObject->ViewBlocked = false;
                        }
                    }
                }
            }
        }
    }
    return old_BLAGCMCGEJG1(ist, HitObject);
}

struct HitObjectInfokill {
    void *klass;
    void *monitor;
    bool m_IsInPool;
    void *HitObject;
    void *HitCollider;
    Vector3 HitLocation;
    Vector3 HitNormal;
    Vector3 RayDir;
    Vector3 StartPosition;
    int32_t Damage;
    float Distance;
    int32_t ActorLayer;
    int32_t HitGroup;
    void *HitPhysicMaterial;
    bool IgnoreHappens;
    bool ViewBlocked;
    struct Vector3 OrigStartPosition;
    uint8_t SpecialHitType;
    uint32_t SpecialHitLevelObjID;
};
struct PlayerID_MKFEKBKJCKE_o;

int (*orig_PlayerNetwork_TakeDamagekill)(void *ClosestEnemy, int baseDamage, PlayerID damager, DamageInfo2_o *damageInfo, int weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float> *checkParams, void *damagerWeaponDynamicInfo, int damagerVehicleID);

int hook_PlayerNetwork_TakeDamagekill(void *ClosestEnemy, int baseDamage, PlayerID damager, DamageInfo2_o *damageInfo, int weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float> *checkParams, void *damagerWeaponDynamicInfo, int damagerVehicleID) {
    
    void* CurrentMatch = Curent_Match();
    void* LocalPlayer = GetLocalPlayer(CurrentMatch);
    
    if (LocalPlayer && ClosestEnemy) {
        firePos = GetHeadPosition(LocalPlayer);
        hitPos = GetHeadPosition(ClosestEnemy);
    }

    if (ClosestEnemy != NULL && Headshot) {
        if (damageInfo != NULL) {
            *(int *)((long) damageInfo + offset_BodyPart) = 1;
        }
    }
    
    return orig_PlayerNetwork_TakeDamagekill(ClosestEnemy, baseDamage, damager, damageInfo, weaponDataID, firePos, hitPos, checkParams, damagerWeaponDynamicInfo, damagerVehicleID);
}

int (*old_BLAGCMCGEJG1kill)(void *, HitObjectInfokill *);
int BLAGCMCGEJG1kill(void *ist, HitObjectInfokill *HitObject) {
    if (SilentKill) {
        if (HitObject != nullptr) {
            void *current_match = Curent_Match();
            if (current_match != NULL) {
                void* local_player = GetLocalPlayer(current_match);
                if (local_player != NULL) {
                    
                    void* WeaponHand = GetWeaponOnHand(local_player);
                    
                    if (WeaponHand != nullptr) { 
                        
                        auto *ClosestEnemy = EnemyVisible(current_match);
                        
                        if (ClosestEnemy != nullptr) {
                                                        
                            Vector3 EnemyLocation;
                            
                            if (AimTarget == 0) {
                                EnemyLocation = GetHeadPosition(ClosestEnemy);
                            } 
                            else if (AimTarget == 2) {
                                EnemyLocation = GetHipPosition(ClosestEnemy); 
                            }                            
                            Vector3 PlayerLocation = CameraMain(local_player);                            
                            HitObject->HitObject = get_gameObject(Player_GetHeadCollider(ClosestEnemy));
                            HitObject->HitCollider = Player_GetHeadCollider(ClosestEnemy);                            
                            HitObject->HitLocation = EnemyLocation;
                            HitObject->HitNormal = EnemyLocation;
                            HitObject->RayDir = Vector3::Normalized(EnemyLocation - PlayerLocation);
                            HitObject->StartPosition = PlayerLocation;
                            HitObject->OrigStartPosition = PlayerLocation;
                            HitObject->SpecialHitType = 0;
                            HitObject->HitGroup = 1;
                            HitObject->IgnoreHappens = false;
                            HitObject->ViewBlocked = false;
                        }
                    }
                }
            }
        }
    }
    return old_BLAGCMCGEJG1kill(ist, HitObject);
}

int tS1,tS2,tS3;

void ESPDistance() {
    if (!eDistance) return;

    void* uiInstance = CurrentInGameUIScene();
    if (uiInstance == nullptr) return;

    void* match = Curent_Match();
    if (!match) return;

    void* localPlayer = GetLocalPlayer(match);
    if (!localPlayer) return;

    monoDictionary<uint8_t*, void**>* players = *(monoDictionary<uint8_t*, void**>**)((long)match + ListPlayer);
    if (!players || !players->values) return;

    for (int i = 0; i < players->getNumValues(); i++) {
        void* enemy = players->getValues()[i];
        
        if (!enemy || enemy == localPlayer) continue;
        if (get_isLocalTeam(enemy)) continue;
        if (get_IsDieing(enemy)) continue;

        float distance = Vector3::Distance(getPosition(localPlayer), getPosition(enemy));
        float hp = (float)GetHp(enemy);

        std::string nameStr = GetNameFromPlayer(enemy); 
        monoString* nameMono = U3DStr(nameStr.c_str());

        bool isBot = false;
        if (offset_IsClientBot) {
             isBot = *(bool*)((uintptr_t)enemy + offset_IsClientBot);
        }

        monoString* infoLine;
        if (isBot) {
            infoLine = U3DStrFormat(distance, hp);
        } else {
            infoLine = U3DStrPlayer2(distance, hp);
        }

        ShowAssistantText(uiInstance, nameMono, infoLine);
    }
}

#include <chrono>
static std::chrono::steady_clock::time_point lastAutoShotTime;
static bool isAutoFiring = false;
static bool isFPSSet = false;

float delayweapon = 0.25f;

int damageCooldown1 = 0;
int delayCounter1 = 0;
int delayLimit1 = 2;
int delayLimit21 = 0;
int DamageDelay1 = 2;

void (*LateUpdate)(void *Player);

void _LateUpdate(void *Player)
{
    if (!Player) {
        LateUpdate(Player);
        return;
    }

    void* CurrentMatch = Curent_Match();
    if (!CurrentMatch) {
        LateUpdate(Player);
        return;
    }

    void* local_player = GetLocalPlayer(CurrentMatch);
    if (!local_player) {
        LateUpdate(Player);
        return;
    }

    void* closestEnemyESP = EnemyVisible(CurrentMatch);

    if (Aimbot) {
        KlelYuimteleport();
        AimLegit();
        AimShoulder();
        ESPDistance();        
        if (!isFPSSet) {
            SetHighFPS(3);
            isFPSSet = true;
        }
        
        if (local_player != nullptr) {
            FLYCS(local_player, flysaved.FlyCS, flysaved.FlySpeedCS);
            FLYBR(local_player, flysaved.FlyBR, flysaved.FlySpeedBR);
        }

        void* closestEnemyAim = EnemyVisible(CurrentMatch);

        if (closestEnemyAim != nullptr && local_player != nullptr) {
            Vector3 EnemyLocation = GetHeadPosition(closestEnemyAim);

            if (AimTarget == 1) {
                EnemyLocation = EnemyLocation - Vector3{0, 0.2f, 0};
            } else if (AimTarget == 2) {
                EnemyLocation = EnemyLocation - Vector3{0, 0.5f, 0};
            }

            Vector3 PlayerLocation = CameraMain(local_player);
            
            Quaternion PlayerLook = GetRotationToTheLocation(
                EnemyLocation,
                0.1f,
                PlayerLocation
            );

            bool IsScopeOn = get_IsSighting(local_player);
            bool IsFiring = get_IsFiring(local_player);

            if (AimbotRage) {
                if (AimWhen == 0) {
                    set_aim(local_player, PlayerLook);
                } else if (AimWhen == 1 && IsFiring) {
                    set_aim(local_player, PlayerLook);
                } else if (AimWhen == 2 && IsScopeOn) {
                    set_aim(local_player, PlayerLook);
                }
            }
        }
    } else {
        isFPSSet = false;
    }
    
    if (SilentKill) {
        void* CurrentMatch = Curent_Match();
        void* LocalPlayer = GetLocalPlayer(CurrentMatch);
            
        if (LocalPlayer) {
            void* WeaponHand = GetWeaponOnHand(LocalPlayer);
                
            if (WeaponHand) {
                void* target = EnemyVisible(CurrentMatch);

                if (target != nullptr) {
                    if (isEnemyInRangeWeapon(LocalPlayer, target, WeaponHand)) {
                        auto now = std::chrono::steady_clock::now();
                        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastAutoShotTime).count();
                            
                        if (elapsed >= 300) {
                            StartFiring2(WeaponHand);
                            StartWholeBodyFiring(LocalPlayer, WeaponHand);
                            lastAutoShotTime = now;
                            isAutoFiring = true;
                        }
                    }
                } else {
                    if (isAutoFiring) {
                        StopFiring2(WeaponHand);
                        isAutoFiring = false;
                    }
                }
            }
        }
    }
    
    if (Aimbot && closestEnemyESP && EspGrenade) {
         Vector3 LocalHead = GetHeadPosition(local_player);
         Vector3 EnemyHead = GetHeadPosition(closestEnemyESP);

         GrenadeLine_DrawLine(LineGrenade, LocalHead, LocalHead, Vector3(0, 0.1f, 0) * 0.1);
         if (RenderLine) {
             UnityColor RedColor = {1.0f, 0.0f, 0.0f, 1.0f};
             LineRenderer_SetColor(RenderLine, RedColor);

             LineRenderer_Set_PositionCount(RenderLine, 0x2);
             LineRenderer_SetPosition(RenderLine, 0, LocalHead);
             LineRenderer_SetPosition(RenderLine, 1, EnemyHead);
         }
    }
    
    if (AimKill && closestEnemyESP != nullptr) {
        void* WeaponHand = GetWeaponOnHand(local_player);

        if (WeaponHand != nullptr && GetWeapon(WeaponHand) > 0) {
            if (damageCooldown1 <= 0) {
                StartTakeDamaFake2(closestEnemyESP);
                damageCooldown1 = DamageDelay1;
            } else {
                damageCooldown1--;
            }
        }
    }
    
    
    
    LateUpdate(Player);
}

void DrawESP(float screenWidth, float screenHeight) {
    ImDrawList* draw = ImGui::GetBackgroundDrawList();
    if (!draw || !Aimbot) return;

    void* current_Match = Curent_Match();
    if (!current_Match) return;

    void* local_player = GetLocalPlayer(current_Match);
    if (!local_player) return;

    monoDictionary<uint8_t*, void**>* players = *(monoDictionary<uint8_t*, void**>**)((long)current_Match + ListPlayer);
    void* camera = Camera_main();
    if (!players || !camera) return;

    for (int i = 0; i < players->getNumValues(); ++i) {
        
        void* enemy = players->getValues()[i];
        
        if (!enemy || enemy == local_player || get_isLocalTeam(enemy) || !get_isVisible(enemy)) continue;

        Vector3 WorldPosFeet = getPosition(enemy);
        Vector3 toeScreen = WorldToScreenPoint(camera, WorldPosFeet);
        if (toeScreen.z < 1) continue;

        Vector3 headPos = WorldPosFeet + Vector3(0, 1.7f, 0);
        Vector3 headScreen = WorldToScreenPoint(camera, headPos);
        if (headScreen.z < 1) continue;

        float height = abs(headScreen.y - toeScreen.y) * (1.2f / 1.1f);
        float width = height * 0.5f;
        
        struct { float x, y, w, h; } rect = { headScreen.x - width / 2.f, screenHeight - headScreen.y, width, height };

        bool isKnocked = get_IsDieing(enemy);

        if (aline) {
            ImU32 lineColor = isKnocked 
                ? IM_COL32(255, 0, 0, 255) 
                : ImGui::ColorConvertFloat4ToU32(espColorLine);

            if (showline == 0) draw->AddLine(ImVec2(screenWidth/2, 0), ImVec2(rect.x+rect.w/2, rect.y), lineColor, 1.5f);
            else if (showline == 1) draw->AddLine(ImVec2(screenWidth/2, screenHeight/2), ImVec2(rect.x+rect.w/2, rect.y+rect.h/2), lineColor, 1.5f);
            else if (showline == 2) draw->AddLine(ImVec2(screenWidth/2, screenHeight), ImVec2(rect.x+rect.w/2, rect.y+rect.h), lineColor, 1.5f);
        }

        if (box1) {
            ImU32 boxColor = isKnocked 
                ? IM_COL32(255, 0, 0, 255) 
                : ImGui::ColorConvertFloat4ToU32(espColorBox);

            draw->AddRect(ImVec2(rect.x, rect.y), ImVec2(rect.x + rect.w, rect.y + rect.h), boxColor, 0.0f, 0, 1.5f);
        }

        if (health) {
            int currentHP = GetHp(enemy);
            int maxHP = get_MaxHP(enemy);
            if (maxHP <= 0) maxHP = 100;
            float hpPercent = (float)currentHP / (float)maxHP;

            ImColor hpColor;
            if (hpPercent < 0.25f) hpColor = ImColor(255, 0, 0); 
            else if (hpPercent < 0.5f) hpColor = ImColor(255, 255, 0);
            else hpColor = ImColor(0, 255, 0);

            float barWidth = 5.0f; 
            float barGap = 2.0f;
            float barX = rect.x + rect.w + barGap;

            draw->AddRectFilled(ImVec2(barX, rect.y), ImVec2(barX + barWidth, rect.y + rect.h), ImColor(0, 0, 0, 150));
            
            float fillHeight = rect.h * hpPercent;
            draw->AddRectFilled(ImVec2(barX, rect.y + (rect.h - fillHeight)), ImVec2(barX + barWidth, rect.y + rect.h), hpColor);
        }

        if (eName) {
            std::string strNum  = std::to_string(i);
            std::string strName = GetNameFromPlayer(enemy);
            
            std::string strDist = std::to_string((int)Vector3::Distance(getPosition(local_player), WorldPosFeet)) + "m";

            float scaleRatio = (float)DrawScale / 13.0f;

            float fontSize = 11.0f * scaleRatio; 
            float paddingX = 3.0f * scaleRatio;
            float gap      = 5.0f * scaleRatio;
            float textOffsetY = 1.0f * scaleRatio; 
            float boxPaddingY = 2.0f * scaleRatio;
            float boxDistY    = 3.0f * scaleRatio; 

            ImVec2 szNum  = ImGui::GetFont()->CalcTextSizeA(fontSize, FLT_MAX, 0.0f, strNum.c_str());
            ImVec2 szName = ImGui::GetFont()->CalcTextSizeA(fontSize, FLT_MAX, 0.0f, strName.c_str());
            ImVec2 szDist = ImGui::GetFont()->CalcTextSizeA(fontSize, FLT_MAX, 0.0f, strDist.c_str());

            float numBoxW = szNum.x + (paddingX * 2);
            float infoContentW = szName.x + gap + szDist.x;
            float infoBoxW = infoContentW + (paddingX * 2);

            if (infoBoxW < (50.0f * scaleRatio)) infoBoxW = (50.0f * scaleRatio);

            float boxH = szName.y + boxPaddingY;

            float totalW = numBoxW + infoBoxW;
            float startX = rect.x + (rect.w - totalW) / 2.0f;
            float startY = rect.y - boxH - boxDistY;

            draw->AddRectFilled(ImVec2(startX, startY),
                                ImVec2(startX + numBoxW, startY + boxH),
                                IM_COL32(180, 0, 255, 255),
                                2.0f, ImDrawFlags_RoundCornersLeft);
            
            draw->AddText(nullptr, fontSize, ImVec2(startX + paddingX, startY + textOffsetY), ImColor(255,255,255), strNum.c_str());

            float infoStartX = startX + numBoxW;
            
            draw->AddRectFilled(ImVec2(infoStartX, startY),
                                ImVec2(infoStartX + infoBoxW, startY + boxH),
                                ImColor(0, 0, 0, 200), 2.0f, ImDrawFlags_RoundCornersRight);

            draw->AddText(nullptr, fontSize, ImVec2(infoStartX + paddingX, startY + textOffsetY),
                          ImGui::ColorConvertFloat4ToU32(espColorName), strName.c_str());

            draw->AddText(nullptr, fontSize, ImVec2(infoStartX + infoBoxW - szDist.x - paddingX, startY + textOffsetY),
                          ImColor(255, 255, 0), strDist.c_str());
        }
    }

    if (showFov) {
        ImVec2 screenCenter = ImVec2(screenWidth / 2.0f, screenHeight / 2.0f);
        draw->AddCircle(screenCenter, Fov_Aim, IM_COL32(255, 255, 255, 255), 64, 1.0f);
    }
}
