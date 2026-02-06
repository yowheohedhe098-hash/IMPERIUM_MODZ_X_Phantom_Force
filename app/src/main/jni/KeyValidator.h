#ifndef KEYVALIDATOR_H
#define KEYVALIDATOR_H

#include <string>
#include <curl/curl.h>
#include <curl/json.hpp>

using json = nlohmann::json;

class KeyValidator {
private:
    std::string apiUrl = "https://pysico-lib-guardian.lovable.app/api/trpc/api.validateKey";
    std::string deviceId;
    bool isValidated = false;
    
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
    
public:
    KeyValidator() {
        // Generate or get device ID
        deviceId = getDeviceId();
    }
    
    std::string getDeviceId() {
        // Get Android device ID
        char prop[PROP_VALUE_MAX];
        __system_property_get("ro.serialno", prop);
        return std::string(prop);
    }
    
    bool validateKey(const std::string& keyCode) {
        CURL* curl;
        CURLcode res;
        std::string readBuffer;
        
        curl = curl_easy_init();
        if(curl) {
            // Prepare JSON payload
            json payload;
            payload["keyCode"] = keyCode;
            payload["deviceId"] = deviceId;
            
            std::string jsonStr = payload.dump();
            
            // Set URL
            curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
            
            // Set POST data
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonStr.c_str());
            
            // Set headers
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            
            // Set callback
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            
            // Perform request
            res = curl_easy_perform(curl);
            
            if(res == CURLE_OK) {
                try {
                    json response = json::parse(readBuffer);
                    if(response.contains("result") && response["result"].contains("data")) {
                        auto data = response["result"]["data"];
                        if(data.contains("success") && data["success"].get<bool>()) {
                            isValidated = true;
                            curl_easy_cleanup(curl);
                            curl_slist_free_all(headers);
                            return true;
                        }
                    }
                } catch(...) {
                    // Parse error
                }
            }
            
            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
        }
        
        return false;
    }
    
    bool isKeyValid() {
        return isValidated;
    }
    
    void setApiUrl(const std::string& url) {
        apiUrl = url;
    }
};

#endif // KEYVALIDATOR_H
