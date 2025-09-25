//
// Created by amapekibert on 9/25/25.
//
/*
#include <cstring>
#include <iostream>
#include <curl/curl.h>

int main() {
    CURL* curl = curl_easy_init();
    if (curl) {
        // parse to json soon...
        const char* site = "https://london.mirror.pkgbuild.com";
        const char* repo = "extra";
        const char* arch = "x86_64";
        const char* pkgname = "sddm";
        const char* pkgver = "0.21.0-6";

        // path to file:
        std::string filename = std::string(pkgname) + "-" + pkgver + "-" + arch + ".pkg.tar.zst";
        std::string url = std::string(site) + "/" + repo + "/os/" + arch + "/" + filename;

        // opening file:
        FILE* file = fopen(filename.c_str(), "wb");
        // downloading file:
        if (file) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

            CURLcode res = curl_easy_perform(curl);

            fclose(file);
        }
        // cleaning:
        curl_easy_cleanup(curl);
    }
    return 0;
}
*/