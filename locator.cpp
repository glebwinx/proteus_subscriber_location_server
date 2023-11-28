#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <nlohmann/json.hpp>

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
    std::string id;
    int x;
    int y;
};

void to_json(json& j, const Subscriber& subscriber) {
    j = json {
        {"id", subscriber.id},
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
    j = json{
        {"id", zone.id},
        {"name", zone.name},
        {"x", zone.x},
        {"y", zone.y},
        {"radius", zone.radius}
    };
}

// Загрузка из файла конфигурации списка зон
void getZoneFromFile() {
    // Реализация загрузки из файла
}

bool checkDataInJson(const std::string& name, std::string& state) {
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
    if (state == "zones") {
        for (auto& item : locator["properties"]["zones"]["items"]) {
            if (item["name"] == name) {
                return true;
            }
        }
    } else if (state == "subscribers"){
        if (!locator.contains("subscribers")) {
            locator["subscribers"] = json::array();
        }
        for (auto& item : locator["subscribers"]) {
            if (item["id"] == name) {
                return true;
            }
        }
    }

    return false;
}

void setSubscriberLocation(const std::string& id, int x, int y) {
    json locator;
    std::string state = "subscribers";
    std::ifstream inputFile(locator_json);
    if (inputFile.is_open()) {
        inputFile >> locator;
        inputFile.close();
    }
    if (id.length() == 12) {
        log_var_msg << "Добавление абонента: " << id;
        MyLogger::logInfo(log_var_msg.str());
        if(!checkDataInJson(id, state)){
            log_var_msg << "Пользователь " << id << " не найден.";
            MyLogger::logInfo(log_var_msg.str());

            Subscriber subscriberEntry{ id, x, y };
            locator["subscribers"].push_back(subscriberEntry);
            log_var_msg << "Пользователь " << id << " добавлен.";
            MyLogger::logInfo(log_var_msg.str());
        } else {
            for(auto& item : locator["subscribers"]){
                if (item["id"] == id) {
                    item["x"] == x;
                    item["y"] == y;
                }
            }
            log_var_msg << "Местоположение для"<< id << " было перезаписано."; 
            MyLogger::logInfo(log_var_msg.str());
        }
        
    } else {
        log_var_msg << "Номер введён не корректно или не распознан. Введено: " << id;
        MyLogger::logInfo(log_var_msg.str());
    }
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
        log_var_msg << "Имя зоны " << name << " было перезаписано."; 
        MyLogger::logInfo(log_var_msg.str());
    }

    std::ofstream outputFile(locator_json);
    outputFile << std::setw(4) << locator << std::endl;
    outputFile.close();
}

// Получение списка зон в которых находится абонент
void setSubscriberLocation(std::string& id) {
    // Реализация получения списка зон для абонента
}

// Выдача списка абонентов, которые находятся в зоне id
void getSubscriberinZone(int id) {
    // Реализация получения списка абонентов в зоне
}

// Триггер на зону
void triggerOnZone() {
    // Реализация триггера на вход в зону
}

// Триггер на сближение абонентов
void triggerForUnionSubscribers() {
    // Реализация триггера на сближение абонентов
}

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Приложение запущено" << std::endl;
    MyLogger::init("logfile.txt");
    setSubscriberLocation("+79398874657", 4, 5);
    setSubscriberLocation("+79398874657", 4, 5);
    setSubscriberLocation("+79398874654", 6, 7);
    addZone(1, "SaintP", 10, 20, 15);
    addZone(2, "Moscow", 100, 200, 150);
    addZone(3, "Moscow", 100, 200, 150);
    addZone(3, "Moscow", -100, -200, -150);
    return 0;
}
