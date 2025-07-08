#include <iostream>
#include <thread>
#include <unordered_map>
using namespace std::chrono_literals;

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
    std::this_thread::sleep_for(1500ms);
    std::cout << "[Reader] Reading domain: " << domain << " -> IP: " << dnsCache[domain] << std::endl;
}

void writeDns(const std::string& domain, const std::string& ip) {
    dnsCache[domain] = ip;
    std::this_thread::sleep_for(1000ms);
    std::cout << "[Writer] Writing domain: " << domain << " -> New IP : " << dnsCache[domain] << std::endl;
}

int main() {

    std::thread write(writeDns, "google.com", "123.45.60.78");
    std::thread read(readDns, "google.com");
    
    write.join();
    read.join();

    return 0;
}