#ifndef JNI_STUFF_H
#define JNI_STUFF_H

#include <jni.h>
#include <string>
#include <vector>
#include "Includes/obfuscate.h"
#include "Includes/Logger.h"
#include "ImGui/imgui.h"

// Declaration of the global JavaVM from Main.cpp
extern JavaVM *jvm;

inline jobject getGlobalContext(JNIEnv *env) {
    jclass activityThread = env->FindClass("android/app/ActivityThread");
    if (!activityThread) return NULL;
    jmethodID currentActivityThread = env->GetStaticMethodID(activityThread,"currentActivityThread","()Landroid/app/ActivityThread;");
    jobject at = env->CallStaticObjectMethod(activityThread, currentActivityThread);
    if (!at) return NULL;

    jmethodID getApplication = env->GetMethodID(activityThread, "getApplication","()Landroid/app/Application;");
    jobject context = env->CallObjectMethod(at, getApplication);
    return context;
}

inline void Toast(const char *text, int length) {
    if (!jvm) return;
    JNIEnv *env;
    jint res = jvm->GetEnv((void**)&env, JNI_VERSION_1_6);
    bool detached = false;
    if (res == JNI_EDETACHED) {
        jvm->AttachCurrentThread(&env, NULL);
        detached = true;
    }
    
    if (env) {
        jstring jstr = env->NewStringUTF(text);
        jclass toast = env->FindClass(OBFUSCATE("android/widget/Toast"));
        if (toast) {
            jmethodID methodMakeText = env->GetStaticMethodID(toast,OBFUSCATE("makeText"),OBFUSCATE("(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"));
            jobject context = getGlobalContext(env);
            if (context && methodMakeText) {
                jobject toastobj = env->CallStaticObjectMethod(toast, methodMakeText, context, jstr, length);
                if (toastobj) {
                    jmethodID methodShow = env->GetMethodID(toast, OBFUSCATE("show"), OBFUSCATE("()V"));
                    if (methodShow) env->CallVoidMethod(toastobj, methodShow);
                }
            }
        }
    }
    
    if (detached) jvm->DetachCurrentThread();
}

inline int ShowSoftKeyboardInput() { return 0; }
inline int PollUnicodeChars() { return 0; }
inline std::string getClipboard() { return ""; }

inline bool secureCompare(const std::string &a, const std::string &b) {
    if (a.size() != b.size()) return false;
    volatile uint8_t result = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        result |= a[i] ^ b[i];
    }
    return result == 0;
}

#endif // JNI_STUFF_H
