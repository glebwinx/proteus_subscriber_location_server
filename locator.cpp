#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <nlohmann/json.hpp>
#include <cmath>

std::stringstream log_var_msg;

using json = nlohmann::json;
const std::string locator_json = "./locator.json";

class MyLogger {
public:
    static void init(const std::string& filename) {
        // Используйте basic_logger_mt для многозадачности и добавьте синк для записи в файл.
        logger_ = spdlog::basic_logger_mt("file_logger", filename);
        spdlog::flush_every(std::chrono::seconds(1)); // Форсированная запись в файл каждую секунду
        logger_->set_level(spdlog::level::debug);
    }

    static void logDebug(const std::string& message) {
        std::cout << message << std::endl;
        logger_->debug(message);
        log_var_msg.str("");
        
    }

    static void logInfo(const std::string& message) {
        std::cout << message << std::endl;
        logger_->info(message);
        log_var_msg.str("");
    }

    static void logError(const std::string& message) {
        std::cout << message << std::endl;
        logger_->error(message);
        log_var_msg.str("");
    }

    static void logCritical(const std::string& message) {
        std::cout << message << std::endl;
        logger_->critical(message);
        log_var_msg.str("");
    }

private:
    static std::shared_ptr<spdlog::logger> logger_;
};

std::shared_ptr<spdlog::logger> MyLogger::logger_ = nullptr;


struct Subscriber {
    std::string number;
    int x;
    int y;
};

void to_json(json& j, const Subscriber& subscriber) {
    j = json {
        {"number", subscriber.number},
        {"x", subscriber.x},
        {"y", subscriber.y}
    };
}

struct Zone {
    int id;
    std::string name;
    int x;
    int y;
    int radius;
};

void to_json(json& j, const Zone& zone) {
    j = json {
        {"id", zone.id},
        {"name", zone.name},
        {"x", zone.x},
        {"y", zone.y},
        {"radius", zone.radius}
    };
}

struct Trigger_zone {
    int id;
    std::string subscriber_id;
    int zone_id;
    std::string event;
};

void to_json(json& j, const Trigger_zone& trigger_zone) {
    j = json {
        {"id", trigger_zone.id},
        {"subscriber_id", trigger_zone.subscriber_id},
        {"zone_id", trigger_zone.zone_id},
        {"event", trigger_zone.event},
    };
}

struct Trigger_Union_Subscribers {
    int id;
    std::string subscriber1_id;
    std::string subscriber2_id;
    int distance;
};

void to_json(json& j, const Trigger_Union_Subscribers& trigger_subscribers) {
    j = json {
        {"id", trigger_subscribers.id},
        {"subscriber1_id", trigger_subscribers.subscriber1_id},
        {"subscriber2_id", trigger_subscribers.subscriber2_id},
        {"distance", trigger_subscribers.distance},
    };
}

// Реализация триггера на вход и выход из зоны
void triggerOnZone(const std::string& number, int x, int y) {
    log_var_msg << "Проверка триггера на вход и выход из зон для абонента: " << number << " с координатами " << "[" << x << " : "<< y << "]";
    MyLogger::logInfo(log_var_msg.str());

    int zone_x, zone_y, radius, delta_x, delta_y, zone_id, get_location = 0;
    std::ifstream inputFile(locator_json);
    json locator;

    if (inputFile.is_open()) {
       inputFile >> locator;
       inputFile.close();
    }

    for (auto& item : locator["properties"]["zones"]["items"]) {

        zone_x = item["x"];
        zone_y = item["y"];
        zone_id = item["id"];
        radius = item["radius"];
        
        delta_x = zone_x - x;
        delta_y = zone_y - y;
        get_location = std::sqrt(std::pow(delta_x, 2) + std::pow(delta_y, 2));


        if(get_location == radius - 1){
            log_var_msg << "Абонент " << number << " вошёл в зону c id: " << zone_id;
            MyLogger::logInfo(log_var_msg.str());
        } else if(get_location == radius + 1) {
            log_var_msg << "Абонент " << number << " вышёл из зоны c id: " << zone_id;
            MyLogger::logInfo(log_var_msg.str());
        }
    }
}

// Загрузка из файла конфигурации списка зон
void getZoneFromFile() {
    // Реализация загрузки из файла
}

bool checkDataInJson(const std::string& name, const std::string& state) {
    std::ifstream inputFile(locator_json);
    if (!inputFile.is_open()) {
        log_var_msg << "Ошибка открытия файла и проверки имени для " << state << " " << name;
        MyLogger::logCritical(log_var_msg.str());
        log_var_msg << "Cтруктура JSON для " << state << " -> была создана";
        MyLogger::logInfo(log_var_msg.str());
        std::ofstream outputFile(locator_json);
        return false;
    }

    json locator;
    inputFile >> locator;
    //Проверка дубликата
    if (state == "zones" || state == "zones_id") {
        for (auto& item : locator["properties"]["zones"]["items"]) {
            if (state == "zones_id") {
                if (item["id"] == std::stoi(name)) {
                    return true;
                }

            } else {
                if (item["name"] == name) {
                return true;
                }
            }
            
        }
    } else if (state == "subscribers"){
        if (!locator.contains("subscribers")) {
            locator["subscribers"] = json::array();
            return true;
        }
        for (auto& item : locator["subscribers"]) {
            if (item["number"] == name) {
                return true;
            }
        }

    }

    return false;
}

void setSubscriberLocation(const std::string& number, int x, int y) {
    json locator;
    std::string state = "subscribers";
    std::ifstream inputFile(locator_json);
    if (inputFile.is_open()) {
        inputFile >> locator;
        inputFile.close();
    }
    if (number.length() == 12) {
        log_var_msg << "Добавление абонента: -> " << number;
        MyLogger::logInfo(log_var_msg.str());
        if(!checkDataInJson(number, state)) {
            log_var_msg << "Пользователь " << number << " -> не найден.";
            MyLogger::logInfo(log_var_msg.str());

            Subscriber subscriberEntry{ number, x, y };
            locator["subscribers"].push_back(subscriberEntry);
            log_var_msg << "Пользователь " << number << " -> добавлен.";
            MyLogger::logInfo(log_var_msg.str());
        } else {
            for(auto& item : locator["subscribers"]) {
                if (item["number"] == number) {
                    item["x"] = x;
                    item["y"] = y;
                }
            }
            log_var_msg << "Местоположение для -> "<< number << " было перезаписано."; 
            MyLogger::logInfo(log_var_msg.str());
        }
        
    } else {
        log_var_msg << "Номер введён не корректно или не распознан. Введено: -> " << number;
        MyLogger::logInfo(log_var_msg.str());
    }
    triggerOnZone(number, x, y);
    std::ofstream outputFile(locator_json);
    outputFile << std::setw(4) << locator << std::endl;
    outputFile.close();
}

// Добавление и изменение зон
void addZone(int id, const std::string& name, int x, int y, int radius) {
    json locator;
    std::string state =  "zones";
    //Загрузка данных в локатор
    std::ifstream inputFile(locator_json);
    if (inputFile.is_open()) {
        inputFile >> locator;
        inputFile.close();
    }

    if (!checkDataInJson(name, state)) {
        log_var_msg << "Имя для зоны " << name << " не найдено.";
        MyLogger::logInfo(log_var_msg.str());

        Zone zoneEntry{ id, name, x, y, radius };
        locator["properties"]["zones"]["items"].push_back(zoneEntry);
        log_var_msg << "Зона с именем " << name << " была добавлена.";
        MyLogger::logInfo(log_var_msg.str());
    } else {
        for (auto& item : locator["properties"]["zones"]["items"]) {
            if (item["name"] == name) {
                item["id"] = id;
                item["x"] = x;
                item["y"] = y;
                item["radius"] = radius;
            }
        }
        log_var_msg << "Координаты зоны " << name << " были перезаписаны."; 
        MyLogger::logInfo(log_var_msg.str());
    }

    std::ofstream outputFile(locator_json);
    outputFile << std::setw(4) << locator << std::endl;
    outputFile.close();
}

// Получение списка зон в которых находится абонент
void getSubscriber(const std::string& number) {
    int zone_id, sub_x, sub_y, zone_x, zone_y, radius_zone, delta_x, delta_y, get_location, iter = 0;
    std::string state = "subscribers";
    if(!checkDataInJson(number, state)) {
        log_var_msg << "Абонент " << number << " -> не найден.";
        MyLogger::logInfo(log_var_msg.str());
    } else {
        std::ifstream inputFile(locator_json);
        json locator;
        inputFile >> locator;
        inputFile.close();
        for (auto& item : locator["subscribers"]) {
            if (item["number"] == number) {
                sub_x = item["x"];
                sub_y = item["y"];
            }
        }
        log_var_msg  << "Координаты абонента " << number << " [" << sub_x << " : " << sub_y << "]";
        MyLogger::logInfo(log_var_msg.str());
        for (auto& item : locator["properties"]["zones"]["items"]) {
            zone_id = item["id"];
            zone_x = item["x"];
            zone_y = item["y"];
            radius_zone = item["radius"];
            delta_x = zone_x - sub_x;
            delta_y = zone_y - sub_y;
            get_location = std::sqrt(std::pow(delta_x, 2) + std::pow(delta_y, 2));
            if (radius_zone >= get_location) {
                iter += 1;
                log_var_msg << "Абонент " << number << " находится в зоне с id: -> " << zone_id;
                MyLogger::logInfo(log_var_msg.str());
            }
        }
        if (iter == 0) {
            log_var_msg << "Абонент " << number << " -> вне зон.";
            MyLogger::logInfo(log_var_msg.str());
        }
    }

}

// Выдача списка абонентов, которые находятся в зоне id
void getSubscriberinZone(int id) {
    std::string state = "zones_id";
    std::string number = "";
    int x_zone, y_zone, radius_zone, get_location, delta_x, delta_y, iter = 0;
    if(!checkDataInJson(std::to_string(id), state)) {
        log_var_msg << "Зона с id: " << id << " не найдена";
        MyLogger::logInfo(log_var_msg.str());
    } else {
        std::ifstream inputFile(locator_json);
        json locator;
        inputFile >> locator;
        inputFile.close();
        for (auto& item : locator["properties"]["zones"]["items"]) {
            if (item["id"] == id){
                x_zone = item["x"];
                y_zone = item["y"];
                radius_zone = item["radius"];
            }

        }
        for (auto& item : locator["subscribers"]) {
            number = item["number"];
            int x = item["x"];
            int y = item["y"];
            delta_x = x_zone - x;
            delta_y = y_zone - y;
            get_location = std::sqrt(std::pow(delta_x, 2) + std::pow(delta_y, 2));
            if (get_location <= radius_zone) {
                iter += 1;
                log_var_msg << "В зоне id: " << id << " находится абонент -> " << number;
                MyLogger::logInfo(log_var_msg.str());
            }
        }
        if (iter == 0) {
            log_var_msg << "Зона с id: " << id << " -> пуста.";
            MyLogger::logInfo(log_var_msg.str());
        }
    }
    // Реализация получения списка абонентов в зоне
}

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Приложение запущено." << std::endl;
    MyLogger::init("logfile.txt");
    setSubscriberLocation("+79398874657", 4, 5);
    setSubscriberLocation("+79398874657", 20, 30);
    setSubscriberLocation("+79398874657", 19, 31);
    setSubscriberLocation("+79398874657", 15, 35);
    setSubscriberLocation("+79398874657", 10, 4);
    setSubscriberLocation("+79990000000", 10, 20);
    setSubscriberLocation("+79398874654", 6, 6);
    addZone(1, "SaintP", 10, 20, 15);
    addZone(2, "Moscow", 100, 200, 150);
    addZone(3, "Moscow", 100, 200, 150);
    addZone(3, "Moscow", -100, -200, -150);
    getSubscriber("+79398874654");
    getSubscriber("+79398844457");
    getSubscriberinZone(1);
    getSubscriberinZone(2);
    getSubscriberinZone(3);
    return 0;
}
