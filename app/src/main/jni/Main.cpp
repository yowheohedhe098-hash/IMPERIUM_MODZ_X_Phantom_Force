#include <cstring>
#include <jni.h>
#include <pthread.h>
#include <cstdio>
#include <unistd.h>
#include <dlfcn.h>
#include <list>
#include <vector>
#include <fstream>
#include <iostream>
#include <fcntl.h>
#include <linux/ptrace.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/system_properties.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <KittyMemory/KittyScanner.h>
#include <KittyMemory/KittyUtils.h>
#include "KittyMemory/KittyMemory.h"
#include "KittyMemory/MemoryPatch.h"
using namespace KittyMemory;
#include "oxorany/oxorany.h"
#include "Includes/obfuscate.h"
#include "Includes/Logger.h"
#include "Includes/Macros.h"
#include "Includes/Utils.h"
#include "xdl/xdl.h"
#include "curl/json.hpp"
#include "KhanhMods/fake_dlfcn.h"
#include "KhanhMods/Call_Me.h"
#include "Struct/Class.h"
#include "Struct/Unity.h"
#include "Misc.h"
#include "zygisk.hpp"
#include "Hook.h"

#define ALPHA    ( ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoBorder )
#define NO_ALPHA ( ImGuiColorEditFlags_NoTooltip    | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoBorder )

JavaVM *jvm = nullptr;
JavaVM *jvm1 = nullptr; // Define jvm1 to satisfy external references
jobject g_Activity = nullptr;

ProcMap _Libil2cpp, _Libunity;

// Global variables needed by Jni_Stuff.h and other files
std::string g_Token, g_Auth;
bool bValid = false;
std::string EXP = "";
std::string UUID = "";
bool IsEverythingLoad = false;

// IMPERIUM MODZ X Phantom Force - New Features (MUST BE BEFORE ConstructMenu.h)
#include "BNM_System.h"
#include "KeyValidator.h"
#include "ImperiumFinal_WORKING.h"

#include "ConstructMenu.h"
#include "Jni_Stuff.h"
#include "ImGui/Call_ImGui.h"
#include "Includes/hide.h"

// Hex Auto 
#define FALSE64BIT "00 00 80 D2 C0 03 5F D6"
#define TRUE64BIT  "20 00 80 D2 C0 03 5F D6"
#define RETURN64BIT "C0 03 5F D6"
#define KLYUIM(assembly, namespaceName, className, methodName, paramCount, newFunc, oldFunc) \
DobbyHook((void*)Il2CppGetMethodOffset(OBFUSCATE(assembly), OBFUSCATE(namespaceName), OBFUSCATE(className), OBFUSCATE(methodName), paramCount), (void*)newFunc, (void**)&oldFunc)

void ResolveGameActivity(JNIEnv* env) {
    if (g_Activity != nullptr) return;
    LOGI("Resolving Game Activity...");

    jclass activityThreadClass = env->FindClass("android/app/ActivityThread");
    if (activityThreadClass) {
        jmethodID currentActivityThread = env->GetStaticMethodID(activityThreadClass, "currentActivityThread", "()Landroid/app/ActivityThread;");
        jobject at = env->CallStaticObjectMethod(activityThreadClass, currentActivityThread);
        if (at) {
            jmethodID getApplication = env->GetMethodID(activityThreadClass, "getApplication", "()Landroid/app/Application;");
            jobject app = env->CallObjectMethod(at, getApplication);
            if (app) {
                g_Activity = env->NewGlobalRef(app);
                LOGI("Activity resolved via ActivityThread");
                return;
            }
        }
    }
    
    jclass unityPlayerClass = env->FindClass("com/unity3d/player/UnityPlayer");
    if (unityPlayerClass) {
        jfieldID currentActivityField = env->GetStaticFieldID(unityPlayerClass, "currentActivity", "Landroid/app/Activity;");
        if (currentActivityField) {
            jobject act = env->GetStaticObjectField(unityPlayerClass, currentActivityField);
            if (act) {
                g_Activity = env->NewGlobalRef(act);
                LOGI("Activity resolved via UnityPlayer");
            }
        }
    }
}

void *hack_thread(void *arg){
    LOGI("Hack thread started, waiting for libraries...");
    
    int retry = 0;
    while (retry < 60) {
        _Libil2cpp = KittyMemory::getLibraryBaseMap("libil2cpp.so");
        _Libunity = KittyMemory::getLibraryBaseMap("libunity.so");
        if (_Libil2cpp.isValid() && _Libunity.isValid()) break;
        sleep(1);
        retry++;
    }

    if (!_Libil2cpp.isValid()) {
        LOGE("libil2cpp.so not found after 60s! Aborting.");
        return nullptr;
    }

    LOGI("Libraries found! libil2cpp at %p", (void*)_Libil2cpp.startAddress);
    sleep(5); // Wait for il2cpp to initialize fully

    Il2CppAttach();
    LOGI("Il2Cpp attached.");

    // Install IMPERIUM MODZ hooks
    LOGI("Installing IMPERIUM MODZ X Phantom Force...");
    InstallWorkingHooks();
    
    LOGI("Installing system hooks...");
    void* eglSwap = DobbySymbolResolver(OBFUSCATE("/system/lib64/libEGL.so"), OBFUSCATE("eglSwapBuffers"));
    if (!eglSwap) eglSwap = DobbySymbolResolver(OBFUSCATE("/system/lib/libEGL.so"), OBFUSCATE("eglSwapBuffers"));
    
    if (eglSwap) {
        DobbyHook(eglSwap, (void *) _eglSwapBuffers1, (void **) &orig_eglSwapBuffers1);
        LOGI("eglSwapBuffers hooked.");
    }

    IsEverythingLoad = true;
    LOGI("IMPERIUM MODZ loaded successfully!");
    return nullptr;
}

extern "C" {
    JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
        jvm = vm;
        jvm1 = vm;
        JNIEnv *env;
        if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
            return JNI_FALSE;
        }

        LOGI("JNI_OnLoad called");
        ResolveGameActivity(env);

        pthread_t ptid;
        pthread_create(&ptid, nullptr, hack_thread, nullptr);
               
        return JNI_VERSION_1_6;
    }
}
