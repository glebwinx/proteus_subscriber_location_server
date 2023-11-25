#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <nlohmann/json.hpp>

std::stringstream log_var_msg;

using json = nlohmann::json;
const std::string filename_zone = "./locator.json";

class MyLogger {
public:
    static void init(const std::string& filename) {
        // Используйте basic_logger_mt для многозадачности и добавьте синк для записи в файл
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
void GetZoneFromFile() {
    // Реализация загрузки из файла
}

void GetSubscriber(const std::string& id) {
    if (id.length() == 12) {
        log_var_msg << "Поиск местоположения для абонента: " << id;
        MyLogger::logInfo(log_var_msg.str());
    } else {
        log_var_msg << "Номер введён не корректно или не распознан. Введено: " << id;
        MyLogger::logInfo(log_var_msg.str());
    }
}

bool checkNameZoneInFile(int id, const std::string& name, int x, int y, int radius) {
    std::ifstream inputFile(filename_zone);
    if (!inputFile.is_open()) {
        log_var_msg << "Ошибка открытия файла и проверки имени зоны: " << name;
        MyLogger::logCritical(log_var_msg.str());
        log_var_msg << "Файл JSON для зон -> был создан";
        MyLogger::logInfo(log_var_msg.str());
        std::ofstream outputFile(filename_zone);
        return false;
    }

    json locator;
    inputFile >> locator;

    for (auto& item : locator["properties"]["zones"]["items"]) {
        if (item["name"] == name) {
            return true;
        }
    }

    return false;
}

// Добавление и изменение зон
void addZone(int id, const std::string& name, int x, int y, int radius) {
    json locator;
    //Загрузка данных в локатор
    std::ifstream inputFile(filename_zone);
    if (inputFile.is_open()) {
        inputFile >> locator;
        inputFile.close();
    }

    if (!checkNameZoneInFile(id, name, x, y, radius)) {
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
        log_var_msg << " Имя зоны " << name << " было перезаписано."; 
    }

    std::ofstream outputFile(filename_zone);
    outputFile << std::setw(4) << locator << std::endl;
    outputFile.close();
}

// Получение списка зон в которых находится абонент
void SetSubscriberLocation(std::string& id, int x, int y) {
    // Реализация получения списка зон для абонента
}

// Выдача списка абонентов, которые находятся в зоне id
void GetSubscriberinZone(int id) {
    // Реализация получения списка абонентов в зоне
}

// Триггер на зону
void TriggerOnZone() {
    // Реализация триггера на вход в зону
}

// Триггер на сближение абонентов
void TriggerForUnionSubscribers() {
    // Реализация триггера на сближение абонентов
}

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Приложение запущено" << std::endl;
    MyLogger::init("logfile.txt");
    GetSubscriber("+79398874657");
    addZone(1, "SaintP", 10, 20, 15);
    addZone(2, "Moscow", 100, 200, 150);
    addZone(3, "Moscow", 100, 200, 150);
    addZone(3, "Moscow", -100, -200, -150);
    return 0;
}
