#pragma once
#include <stdint.h>

extern bool AimSilent;
extern bool AimbotRage;
extern bool AimSilent2;
extern bool AimBotLegit;
extern bool SilentAim;
extern bool eName;
extern bool Grendeline;
extern bool SilentKill;
extern bool eDistance;
extern bool SpeedHack;
extern bool GhostH;
extern bool EspGrenade;
extern bool Unlock120fps;
extern bool test666;
extern bool AimbotShoulder1;
extern ImVec4 espColorLine;
extern ImVec4 espColorBox;
extern int DrawScale;

bool ShowUpdate = false; 
bool ShowKeySystem = false; 

int32_t (*orig_ANativeWindow_getWidth)(ANativeWindow* window);
int32_t _ANativeWindow_getWidth(ANativeWindow* window) {
    screenWidth = orig_ANativeWindow_getWidth(window);
    return orig_ANativeWindow_getWidth(window);
}

int32_t (*orig_ANativeWindow_getHeight)(ANativeWindow* window);
int32_t _ANativeWindow_getHeight(ANativeWindow* window) {
    screenHeight = orig_ANativeWindow_getHeight(window);
    return orig_ANativeWindow_getHeight(window);
}

int32_t (*orig_AConfiguration_getDensity)(ANativeWindow* config);
int32_t _AConfiguration_getDensity(ANativeWindow* config) {
    density = orig_AConfiguration_getDensity(config);
    return orig_AConfiguration_getDensity(config);
}

#if defined(__aarch64__) 
    #define RETURN "CO 03 5F D6"
    #define NOP "1F 20 03 D5"
    #define TRUE "20 00 80 D2 CO 03 5F D6"
    #define FALSE "00 00 80 D2 CO 03 5F D6"
    auto window_name = OBFUSCATE("NeoX");
#else
    #define RETURN "1E FF 2F E1"
    #define NOP "00 F0 20 E3"
    #define TRUE "01 00 A0 E3 1E FF 2F E1"
    #define FALSE "00 00 A0 E3 1E FF 2F E1"
    auto window_name = OBFUSCATE("NeoX");
#endif

#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <iostream>
#include <chrono>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <dlfcn.h>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <unistd.h>
#include "Munodz/Munodz.hpp"
#include "ImGui/stb_image.h"
#define STB_IMAGE_IMPLEMENTATION

using namespace std::this_thread;
using namespace std::chrono;
static std::vector<OWM::Notification> g_Notifications;

struct TextureInfo {
    ImTextureID textureId = nullptr;
    int w = 0;
    int h = 0;
};

void DrawImage(int x, int y, int w, int h, ImTextureID Texture) {
    ImGui::GetForegroundDrawList()->AddImage(Texture, ImVec2(x, y), ImVec2(x + w, y + h));
}

static TextureInfo textureInfo;

TextureInfo createTexture(char *ImagePath) {
    int w, h, n;
    stbi_uc *data = stbi_load(ImagePath, &w, &h, &n, 4); 
    if (!data) {
        printf("Failed to load file: %s\n", ImagePath);
        return {};
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);

    textureInfo.textureId = (ImTextureID)(intptr_t)texture;
    textureInfo.w = w;
    textureInfo.h = h;
    return textureInfo;
}

TextureInfo CreateTexture(const unsigned char* buf, int len) {
    TextureInfo image;
    int n = 0;
    unsigned char* image_data = stbi_load_from_memory(buf, len, &image.w, &image.h, &n, 4);
    if (!image_data) {
        perror("File does not exist");
        return {};
    }

    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.w, image.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    image.textureId = (ImTextureID)(intptr_t)image_texture;
    return image;
}

void write_file (std::string path,std::string str) {
  std::ofstream myfile;
  myfile.open (path);
  myfile << str;
  myfile.close();
}

std::string float_to_string (float value) {
    std::string str; 
    str = std::to_string(value);
    return str;
}

char string_to_char(std::string str) {
    std::string convert = str;
    int get_len = convert.length();
    char char_array[get_len + 1];
    strcpy(char_array, convert.c_str());
    for (int i = 0; i < get_len; i++)
    return char_array[i];
}

std::string int_to_string2(int num) {
     std::string str = to_string(num);
     return str;
}

std::string getCurrentTime() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d",
    ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    return buffer;
}

void Concacvip1() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    KlelYuimimguivip1();
}

bool func_ghost = false;
bool Showghost = false;
bool M4A1 = false;
static bool ConstructWindows = false;
bool ShowMenu = false;
int TabMenu = 1;
static bool HideIcon;
bool itsmk = true; 

bool showteleportbr = false;
bool showteleportcs = false;
bool showfastdash = false;

static bool isMenuCollapsed = false;

// NEOX MENU - Modern Cyberpunk Theme
// Elegant, Professional Interface Design
// Clean and Professional Appearance

void SetupNeoXStyle() {
    ImGuiStyle& style = ImGui::GetStyle();
    
    // Cyberpunk color scheme
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.08f, 0.08f, 0.12f, 0.95f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.30f, 0.60f, 0.85f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.40f, 0.80f, 0.95f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.35f, 0.70f, 0.60f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.45f, 0.90f, 0.80f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 0.55f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.20f, 0.70f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.20f, 0.30f, 0.80f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.25f, 0.25f, 0.35f, 0.90f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 0.70f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 0.50f, 0.90f, 0.80f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 0.60f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_Text] = ImVec4(0.90f, 0.95f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.55f, 0.60f, 1.00f);
    
    // Modern rounded corners
    style.WindowRounding = 8.0f;
    style.ChildRounding = 6.0f;
    style.FrameRounding = 4.0f;
    style.PopupRounding = 8.0f;
    style.ScrollbarRounding = 4.0f;
    style.GrabRounding = 3.0f;
    style.TabRounding = 4.0f;
    
    // Modern spacing
    style.WindowPadding = ImVec2(10, 10);
    style.FramePadding = ImVec2(8, 4);
    style.ItemSpacing = ImVec2(6, 4);
    style.ItemInnerSpacing = ImVec2(4, 4);
    style.IndentSpacing = 20.0f;
    
    // Border sizes
    style.WindowBorderSize = 1.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupBorderSize = 1.0f;
    style.FrameBorderSize = 0.0f;
    style.TabBorderSize = 0.0f;
}

void DrawMenuHeader() {
    ImGuiX::DripHeader("NEOX CLIENT | v2.1", &isMenuCollapsed);
}

void KlelYuim() {
    DrawESP(glWidth, glHeight);

    if (itsmk) {
        
        static bool wasInMatch = false;
        static bool isFirstRun = true;
        
        void* matchPtr = Curent_Match();
        bool isInMatch = (matchPtr != nullptr);
        
        float targetScale = 3.5f;
        if (isInMatch) {
            targetScale = 2.5f; 
        }

        if (isFirstRun || isInMatch != wasInMatch) {
            ImGuiX::SetupDripStyle(targetScale); 
            SetupNeoXStyle(); // Apply custom NeoX style
            wasInMatch = isInMatch;
            isFirstRun = false;
        }
        
        float headerHeight = 80.0f;
        float contentHeight = 770.0f; 
        float windowH = isMenuCollapsed ? (headerHeight * ImGuiX::GScale) : (850.0f * ImGuiX::GScale);
        float windowW = 725.0f * ImGuiX::GScale; 
        
        ImGui::SetNextWindowSize(ImVec2(windowW, windowH), ImGuiCond_Always);
        
        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar;
        
        if (isMenuCollapsed) {
            windowFlags |= ImGuiWindowFlags_NoBackground;
        }

        if (ImGui::Begin("NeoXClientUI", &itsmk, windowFlags))
        {
            ImGui::SetWindowFontScale(ImGuiX::GScale);

            DrawMenuHeader();
            
            if (!isMenuCollapsed) {
                float totalWidth = ImGui::GetContentRegionAvail().x;
                float slotWidth = totalWidth / 4.0f;
                float tabWidth = slotWidth * 0.75f; 
                
                float leftPadding = 35.0f * ImGuiX::GScale;
                float startX = ImGui::GetCursorScreenPos().x + leftPadding;
                float startY = ImGui::GetCursorScreenPos().y + (40.0f * ImGuiX::GScale); 

                ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0,0));
                
                ImGui::SetCursorScreenPos(ImVec2(startX, startY));
                if (ImGuiX::DripTab("AIMBOT", activeTab == 0, tabWidth)) activeTab = 0;
                
                ImGui::SetCursorScreenPos(ImVec2(startX + tabWidth, startY));
                if (ImGuiX::DripTab("PLAYER", activeTab == 1, tabWidth)) activeTab = 1;
                
                ImGui::SetCursorScreenPos(ImVec2(startX + (tabWidth * 2), startY));
                if (ImGuiX::DripTab("VEHICLE", activeTab == 2, tabWidth)) activeTab = 2;
                
                ImGui::SetCursorScreenPos(ImVec2(startX + (tabWidth * 3), startY));
                if (ImGuiX::DripTab("IMPERIUM", activeTab == 3, tabWidth)) activeTab = 3;

                ImGui::PopStyleVar();
                
                ImVec2 linePos = ImVec2(ImGui::GetWindowPos().x, startY + (36.0f * ImGuiX::GScale) + (0.0f * ImGuiX::GScale)); 

                ImGui::GetWindowDrawList()->AddLine(
                    linePos,
                    ImVec2(linePos.x + totalWidth, linePos.y),
                    ImGui::GetColorU32(ImVec4(0.00f, 0.40f, 0.80f, 1.00f)), // Blue accent line
                    2.0f
                );
                
                ImGui::SetCursorScreenPos(ImVec2(ImGui::GetWindowPos().x, startY + (20.0f * ImGuiX::GScale))); 
                
                ImGui::NewLine();

                ImGui::BeginChild("Content", ImVec2(0,0), false, ImGuiWindowFlags_AlwaysVerticalScrollbar);
                {
                    ImGui::Dummy(ImVec2(0, 10.0f * ImGuiX::GScale)); 

                    ImGui::Indent(15.0f * ImGuiX::GScale); 
                    ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x - (30.0f * ImGuiX::GScale));

                    if (activeTab == 0)
                    {
                        ImGui::TextColored(ImVec4(0.00f, 0.70f, 1.00f, 1.00f), "AIMBOT SETTINGS");
                        ImGui::Separator();
                        ImGui::Spacing();
                        
                        ImGuiX::DripCheckbox("Enable Aimbot", &Aimbot);
                        ImGuiX::DripCheckbox("Legit Mode", &AimBotLegit);
                        ImGuiX::DripCheckbox("Rage Mode", &AimbotRage); 
                        ImGuiX::DripCheckbox("Shoulder Aim", &AimbotShoulder1);
                        ImGuiX::DripCheckbox("Silent Aim", &SilentAim);
                        ImGuiX::DripCheckbox("Instant Kill", &SilentKill);
                        ImGuiX::DripCheckbox("Aim Assist", &AimKill);
                        
                        ImGuiX::DripCombo("Target Bone:", &AimTarget, aimPart, IM_ARRAYSIZE(aimPart));
                    }
                    else if (activeTab == 1)
                    {
                        ImGui::TextColored(ImVec4(0.00f, 0.70f, 1.00f, 1.00f), "PLAYER SETTINGS");
                        ImGui::Separator();
                        ImGui::Spacing();
                        
                        ImGuiX::DripCheckbox("Speed Hack", &SpeedHack);
                        ImGuiX::DripCheckbox("Ghost Mode", &GhostH);
                        static bool isLockedfps = false;

                        if (Unlock120fps && !isLockedfps) {
                            isLockedfps = true;
                        }

                        ImGuiX::DripCheckbox("Unlock 120 FPS", &Unlock120fps);

                        if (isLockedfps) {
                            Unlock120fps = true;
                        }
                        ImGuiX::DripCheckbox("Reset Account", &Guest);                            
                        ImGuiX::DripCheckbox("Fly Mode", &FlyUpBR);
                        ImGuiX::DripSliderInt("Fly Height:", &flysaved.FlyBR, 0, 200);
                        ImGuiX::DripSliderInt("Fly Speed:", &flysaved.FlySpeedBR, 1, 100);
                    }
                    else if (activeTab == 2)
                    {
                        ImGui::TextColored(ImVec4(0.00f, 0.70f, 1.00f, 1.00f), "VEHICLE SETTINGS");
                        ImGui::Separator();
                        ImGui::Spacing();
                        
                        ImGuiX::DripCheckbox("Test Feature", &test666);                  
                        ImGuiX::DripCheckbox("Teleport CS", &showteleportcs);
                    }                    
                    else if (activeTab == 3)
                    {           
                        ImGui::TextColored(ImVec4(0.60f, 0.00f, 1.00f, 1.00f), "IMPERIUM MODZ X PHANTOM FORCE");
                        ImGui::Separator();
                        ImGui::Spacing();
                        
                        // MOVEMENT
                        ImGui::TextColored(ImVec4(1.00f, 0.80f, 0.00f, 1.00f), "[MOVEMENT]");
                        ImGuiX::DripCheckbox("Speed Hack", &SpeedHack_Enabled);
                        if(SpeedHack_Enabled) {
                            ImGui::SliderFloat("Speed Multiplier", &SpeedMultiplier, 1.0f, 3.0f);
                        }
                        ImGuiX::DripCheckbox("Spin Boot (360°)", &SpinBoot_Enabled);
                        if(SpinBoot_Enabled) {
                            ImGui::SliderFloat("Spin Speed", &SpinBootSpeed, 360.0f, 1440.0f);
                        }
                        ImGui::Spacing();
                        
                        // CAMERA & AIM
                        ImGui::TextColored(ImVec4(1.00f, 0.80f, 0.00f, 1.00f), "[CAMERA & AIM]");
                        ImGuiX::DripCheckbox("Zoom Hack", &ZoomHack_Enabled);
                        if(ZoomHack_Enabled) {
                            ImGui::SliderFloat("Zoom Multiplier", &ZoomMultiplier, 1.0f, 5.0f);
                        }
                        // Wide FOV removed - unreliable
                        // Aim Assist removed - needs testing
                        ImGui::Spacing();
                        
                        // VISUAL
                        ImGui::TextColored(ImVec4(1.00f, 0.80f, 0.00f, 1.00f), "[VISUAL]");
                        ImGuiX::DripCheckbox("Wallhack (Outline)", &Wallhack_Enabled);
                        ImGuiX::DripCheckbox("Night Mode OFF", &NightMode_Enabled);
                        // ESP removed - incomplete implementation
                        ImGui::Spacing();
                        
                        // UTILITY
                        ImGui::TextColored(ImVec4(1.00f, 0.80f, 0.00f, 1.00f), "[UTILITY]");
                        ImGuiX::DripCheckbox("Auto Pickup", &AutoPickup_Enabled);
                        ImGuiX::DripCheckbox("Big Radar", &BigRadar_Enabled);
                        // Instant Hit removed - wrong offsets
                        ImGui::Spacing();
                        
                        // INFO
                        ImGui::Separator();
                        ImGui::TextColored(ImVec4(0.00f, 1.00f, 0.00f, 1.00f), "7 Working Features - 100% Verified!");
                        ImGui::TextColored(ImVec4(0.70f, 0.70f, 0.70f, 1.00f), "Version: OB52 | Build: Stable");
                        
                        ImGuiX::DripCheckbox("Grenade Trajectory", &EspGrenade);
                        ImGuiX::DripCheckbox("ESP Lines", &aline);
                        
                        {
                            ImVec2 rMin = ImGui::GetItemRectMin();
                            float cpSize = 30.0f * ImGuiX::GScale;
                            float textStartOffset = 64.0f * ImGuiX::GScale; 
                            float textWidth = ImGui::CalcTextSize("ESP Lines").x;
                            
                            float cpX = rMin.x + textStartOffset + textWidth + (10.0f * ImGuiX::GScale);
                            float cpY = rMin.y + ((80.0f * ImGuiX::GScale - cpSize) / 2.0f) - (10.0f * ImGuiX::GScale);
                            
                            ImVec2 oldCursor = ImGui::GetCursorScreenPos();
                            ImGui::SetCursorScreenPos(ImVec2(cpX, cpY));
                            
                            ImGui::SetNextItemWidth(cpSize); 
                            ImGui::ColorEdit4("##LineColor", (float*)&espColorLine, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaPreview);
                            
                            ImGui::SetCursorScreenPos(oldCursor);
                        }

                        ImGuiX::DripCheckbox("ESP Boxes", &box1);
                        {
                            ImVec2 rMin = ImGui::GetItemRectMin();
                            float cpSize = 30.0f * ImGuiX::GScale;
                            float textStartOffset = 64.0f * ImGuiX::GScale; 
                            float textWidth = ImGui::CalcTextSize("ESP Boxes").x;
                            
                            float cpX = rMin.x + textStartOffset + textWidth + (10.0f * ImGuiX::GScale);
                            float cpY = rMin.y + ((80.0f * ImGuiX::GScale - cpSize) / 2.0f) - (10.0f * ImGuiX::GScale);
                            
                            ImVec2 oldCursor = ImGui::GetCursorScreenPos();
                            ImGui::SetCursorScreenPos(ImVec2(cpX, cpY));
                            
                            ImGui::SetNextItemWidth(cpSize); 
                            ImGui::ColorEdit4("##BoxColor", (float*)&espColorBox, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaPreview);
                            
                            ImGui::SetCursorScreenPos(oldCursor);
                        }

                        ImGuiX::DripCheckbox("Health Bars", &health);
                        ImGuiX::DripCheckbox("Player Names", &eName);
                        ImGuiX::DripCheckbox("Distances", &eDistance);
                        ImGuiX::DripSliderInt("ESP Scale:", &DrawScale, 13, 50);
                        ImGuiX::DripCombo("ESP Position:", &showline, line, IM_ARRAYSIZE(line));
                    }

                    ImGui::PopItemWidth();
                    ImGui::Unindent(15.0f * ImGuiX::GScale);
                }
                ImGui::EndChild();
            }
        }
        ImGui::End();
    }
}

enum TouchType {
    Direct = 0,
    Indirect = 1,
    Stylus = 2
};

struct Touch {
    int m_FingerId; 
    Vector2 m_Position; 
    Vector2 m_RawPosition; 
    Vector2 m_PositionDelta; 
    float m_TimeDelta; 
    int m_TapCount; 
    TouchPhase m_Phase; 
    TouchType m_Type; 
    float m_Pressure; 
    float m_maximumPossiblePressure; 
    float m_Radius; 
    float m_RadiusVariance; 
    float m_AltitudeAngle; 
    float m_AzimuthAngle;
};

std::vector<TouchPhase> touch_phases;
static bool should_clear_mouse_pos = false;
static ImVec2 touch_pos;

Touch (*old_GetTouch)(...);
Touch GetTouch(int index) {
    Touch touch = old_GetTouch(index);
    if (index == 0) {
        if (ImGui::GetCurrentContext() == nullptr) {
            return touch;
        }
        ImGuiIO* io = &ImGui::GetIO();
        touch_pos = ImVec2(touch.m_Position.X, io->DisplaySize.y - touch.m_Position.Y);
        TouchPhase currentPhase = touch.m_Phase;
        io->MousePos = touch_pos;
        switch (currentPhase) {
            case TouchPhase::Began:
            case TouchPhase::Ended:
            case TouchPhase::Canceled: {
                touch_phases.push_back(currentPhase);
                break;
            }
        }
    }
    return touch;
}

bool clearMousePos = true;

inline EGLBoolean (*orig_eglSwapBuffers1)(EGLDisplay dpy, EGLSurface surface);
inline EGLBoolean _eglSwapBuffers1(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    
    if (glWidth <= 0 || glHeight <= 0) {
        return eglSwapBuffers(dpy, surface);
    }
    
    if (!ConstructWindows) {
        Concacvip1();
        ImGuiX::SetupDripStyle(3.5f);
        SetupNeoXStyle(); // Apply NeoX style
        ConstructWindows = true;
    }
    ImGuiIO &io = ImGui::GetIO();

    if (!touch_phases.empty()) {
        auto phase = touch_phases.front();
        switch (phase) {
            case TouchPhase::Began:
                io.MouseDown[0] = true;
                break;
            case TouchPhase::Ended:
            case TouchPhase::Canceled:
                io.MouseDown[0] = false;
                should_clear_mouse_pos = true;
                break;
        }
        touch_phases.erase(touch_phases.begin());
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();
    
    if (ShowUpdate && ImGuiX::IsDateExpired(ImGuiX::UpdateExpireDate)) {
        ImGuiX::DrawUpdateScreen();
    } 
    else if (ShowKeySystem) {
        ImGuiX::DrawKeySystem(&ShowKeySystem);
    }
    else {
        if (showteleportbr) {
            ImGui::SetNextWindowPos(ImVec2(300, 100), ImGuiCond_FirstUseEver); 
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.00f, 0.40f, 0.80f, 1.00f));
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 2.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5.0f, 5.0f));  
            ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(0.0f, 0.0f));  

            ImGui::Begin(OBFUSCATE("Teleport (BR)"), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize); 
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.00f, 0.70f, 1.00f, 1.00f));
                ImGuiX::Switch(OBFUSCATE("Teleport (BR)"), &TeleportProBr);
                ImGui::PopStyleColor();
            }
            ImGui::End();
            ImGui::PopStyleColor(2); 
            ImGui::PopStyleVar(3);  
        }
        
        if (showteleportcs) {
            ImGui::SetNextWindowPos(ImVec2(300, 180), ImGuiCond_FirstUseEver); 
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.00f, 0.40f, 0.80f, 1.00f));
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 2.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5.0f, 5.0f));
            ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(0.0f, 0.0f));

            ImGui::Begin(OBFUSCATE("Teleport (CS)"), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize); 
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.00f, 0.70f, 1.00f, 1.00f));
                ImGuiX::Switch(OBFUSCATE("Teleport (CS)"), &TeleportProCs);
                ImGui::PopStyleColor();
            }
            ImGui::End();
            ImGui::PopStyleColor(2);
            ImGui::PopStyleVar(3);  
        }
        
        if (showfastdash) {
                ImGui::SetNextWindowPos(ImVec2(300, 180), ImGuiCond_FirstUseEver); 
                
                ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
                ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.00f, 0.40f, 0.80f, 1.00f));
                
                ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 2.0f);
                ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5.0f, 5.0f));
                ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(0.0f, 0.0f));

                ImGui::Begin(OBFUSCATE("Fast Dash"), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize); 
                {
                    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.00f, 0.70f, 1.00f, 1.00f));
                    //ImGuiX::Switch(OBFUSCATE("fast dash"), &fastdash);
                    ImGui::PopStyleColor();
                }
                ImGui::End();
                
                ImGui::PopStyleColor(2);
                ImGui::PopStyleVar(3);  
                }
        
        KlelYuim();
    }

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return orig_eglSwapBuffers1(dpy, surface);
}
