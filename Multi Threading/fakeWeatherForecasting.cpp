#include<iostream>
#include<thread>
#include<map>
#include<string>
using namespace std::chrono_literals;

std::map<std::string, float> fake_weather_data()
{
    return {
        {"New Delhi" , 20},
        {"New York" , 40},
        {"Chennai" , 32},
    };
}

void RefreshForeCast(std::map<std::string, float> foorecastData) {
    while(true) {
        std::cout << "\n###############\n";
        for(auto &[city, temperature] : foorecastData) {
            std::cout << city << " - " << temperature << std::endl;
            temperature += 2;
        }
        std::this_thread::sleep_for(2000ms);
    }
}

int main() {
    std::map<std::string, float> forecastdata = fake_weather_data();
    
    std::cout << "Weather station is started" << std::endl;
    std::thread weatherStation(RefreshForeCast, forecastdata);


    for(int i = 0.;i < 100;i++) {
        std::cout << "[Wind Speed] " << i + 10 << " m/s" << std::endl;
        std::this_thread::sleep_for(1000ms);
    }

    weatherStation.join();
}
