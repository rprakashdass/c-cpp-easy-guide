#include <iostream>
#include <thread>
#include <unordered_map>
#include <shared_mutex>
#include <mutex> 

using namespace std::chrono_literals;

std::shared_mutex serverMutex;

std::unordered_map<std::string, std::string> dnsCache = {
    {"rprakashdass.in", "166.67.6.64"},
    {"google.com", "166.67.66.4"},
    {"openai.com", "104.16.99.52"},
    {"example.com", "93.184.216.34"},
    {"github.com", "140.82.113.3"},
    {"yahoo.com", "98.137.11.163"},
    {"bing.com", "204.79.197.200"},
    {"cloudflare.com", "104.17.210.9"}
};

void readDns(const std::string& domain) {
    std::shared_lock<std::shared_mutex> lock(serverMutex); 
    std::cout << "[START READING] " << domain << std::endl;
    std::this_thread::sleep_for(200ms);
    std::cout << "[Reader] Domain: " << domain << " → IP: " << dnsCache[domain] << std::endl;
    std::cout << "[END READING]\n" << std::endl;
}

void writeDns(const std::string& domain, const std::string& ip) {
    std::unique_lock<std::shared_mutex> lock(serverMutex);
    std::cout << "[START WRITING] " << domain << std::endl;
    dnsCache[domain] = ip;
    std::this_thread::sleep_for(300ms);
    std::cout << "[Writer] Updated domain: " << domain << " → IP: " << ip << std::endl;
    std::cout << "[END WRITING]\n" << std::endl;
}

int main() {
    std::thread writer(writeDns, "google.com", "123.45.60.78");
    std::thread reader(readDns, "google.com");

    writer.join();
    reader.join();

    // More writes
    for (int i = 0; i < 3; ++i) {
        std::string ip = "123.64.3." + std::to_string(21 + i);
        writeDns("google.com", ip);
    }

    // More reads
    for (int i = 0; i < 3; ++i) {
        readDns("google.com");
    }

    return 0;
}
