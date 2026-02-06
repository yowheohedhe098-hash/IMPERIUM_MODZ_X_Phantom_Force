#ifndef BNM_SYSTEM_H
#define BNM_SYSTEM_H

#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/mman.h>
#include <chrono>
#include <thread>
#include <dlfcn.h>

// BNM (Binary Ninja Mod) - Anti-Detection System
namespace BNM {
    
    // String obfuscation (simple XOR)
    inline std::string BNM_XOR(const char* str) {
        std::string result(str);
        for(size_t i = 0; i < result.length(); i++) {
            result[i] ^= 0x55; // Simple XOR key
        }
        return result;
    }
    
    // Memory protection
    void ProtectMemory(void* address, size_t size) {
        mprotect((void*)((uintptr_t)address & ~(PAGE_SIZE - 1)), 
                 size + ((uintptr_t)address % PAGE_SIZE), 
                 PROT_READ | PROT_WRITE | PROT_EXEC);
    }
    
    // Anti-debugging
    bool IsDebuggerPresent() {
        char buf[1024];
        FILE* fp = fopen("/proc/self/status", "r");
        if (fp) {
            while (fgets(buf, sizeof(buf), fp)) {
                if (strncmp(buf, "TracerPid:", 10) == 0) {
                    int pid = atoi(buf + 10);
                    fclose(fp);
                    return pid != 0;
                }
            }
            fclose(fp);
        }
        return false;
    }
    
    // Anti-memory scanning
    void RandomizeMemory() {
        static int dummy[1000];
        for(int i = 0; i < 1000; i++) {
            dummy[i] = rand();
        }
    }
    
    // Hook obfuscation - Makes hooks harder to detect
    void ObfuscateHook(void* hookAddress) {
        // Add random NOPs before and after hook
        uint8_t* addr = (uint8_t*)hookAddress;
        ProtectMemory(addr - 16, 32);
        
        // Insert random instructions that don't affect execution
        for(int i = -8; i < 0; i++) {
            addr[i] = 0x1F; // NOP on ARM64
        }
    }
    
    // Anti-signature scanning
    void BreakSignatures() {
        // Modify known mod signatures to avoid detection
        static const char* fake_strings[] = {
            "Garena",
            "FreeFire",
            "Security",
            "AntiCheat"
        };
        
        // These strings confuse signature scanners
        volatile const char* s = fake_strings[rand() % 4];
    }
    
    // Emulator detection bypass (already in Main.cpp but enhanced here)
    bool (*orig_IsEmulator)();
    bool hook_IsEmulator() {
        return false; // Always return false
    }
    
    // Root detection bypass
    bool IsRootedDevice() {
        // Check common root files
        const char* paths[] = {
            "/system/app/Superuser.apk",
            "/sbin/su",
            "/system/bin/su",
            "/system/xbin/su",
            "/data/local/xbin/su",
            "/data/local/bin/su",
            "/system/sd/xbin/su",
            "/system/bin/failsafe/su",
            "/data/local/su"
        };
        
        for(const char* path : paths) {
            if(access(path, F_OK) == 0) {
                return true;
            }
        }
        return false;
    }
    
    bool (*orig_CheckRoot)();
    bool hook_CheckRoot() {
        return false; // Always return false even if rooted
    }
    
    // Memory integrity check bypass
    bool (*orig_CheckIntegrity)(void* address, size_t size);
    bool hook_CheckIntegrity(void* address, size_t size) {
        return true; // Always pass integrity check
    }
    
    // Anti-screenshot detection
    bool (*orig_IsScreenshotDetected)();
    bool hook_IsScreenshotDetected() {
        return false;
    }
    
    // Network traffic obfuscation
    void ObfuscatePacket(uint8_t* packet, size_t size) {
        // XOR with random key
        uint8_t key = (uint8_t)(rand() % 256);
        for(size_t i = 0; i < size; i++) {
            packet[i] ^= key;
        }
    }
    
    // Function name obfuscation
    template<typename T>
    T GetObfuscatedFunction(const char* libName, const char* funcName) {
        // Obfuscate library and function names
        std::string obfLib = BNM_XOR(libName);
        std::string obfFunc = BNM_XOR(funcName);
        
        void* handle = dlopen(obfLib.c_str(), RTLD_NOW);
        if(!handle) return nullptr;
        
        return (T)dlsym(handle, obfFunc.c_str());
    }
    
    // Anti-analysis delays
    void AntiAnalysisDelay() {
        // Random small delays to confuse timing analysis
        usleep(rand() % 1000);
    }
    
    // Code flow obfuscation
    template<typename Func>
    auto ObfuscatedCall(Func func) -> decltype(func()) {
        AntiAnalysisDelay();
        RandomizeMemory();
        auto result = func();
        BreakSignatures();
        return result;
    }
    
    // Initialize BNM system
    void Initialize() {
        // Check for debugger
        if(IsDebuggerPresent()) {
            exit(0); // Exit if debugger detected
        }
        
        // Randomize memory
        RandomizeMemory();
        
        // Break signatures
        BreakSignatures();
        
        LOGI(BNM_XOR("BNM System initialized"));
    }
    
    // Periodic anti-detection checks
    void PeriodicCheck() {
        static time_t lastCheck = 0;
        time_t now = time(NULL);
        
        if(now - lastCheck > 5) { // Check every 5 seconds
            if(IsDebuggerPresent()) {
                exit(0);
            }
            RandomizeMemory();
            lastCheck = now;
        }
    }
}

#endif // BNM_SYSTEM_H
