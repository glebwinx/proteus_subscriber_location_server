#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

std::stringstream log_var_msg;

class MyLogger {
public:
    static void init(const std::string& filename) {
        // Используйте basic_logger_mt для многозадачности и добавьте синк для записи в файл
        logger_ = spdlog::basic_logger_mt("file_logger", filename);
        spdlog::flush_every(std::chrono::seconds(1)); // Форсированная запись в файл каждую секунду
        logger_->set_level(spdlog::level::debug);
    }

    static void logTrace(const std::string& message) {
        logger_->trace(message);
    }

    static void logDebug(const std::string& message) {
        logger_->debug(message);
    }

    static void logInfo(const std::string& message) {
        logger_->info(message);
    }

    static void logWarn(const std::string& message) {
        logger_->warn(message);
    }

    static void logError(const std::string& message) {
        logger_->error(message);
    }

    static void logCritical(const std::string& message) {
        logger_->critical(message);
    }

private:
    static std::shared_ptr<spdlog::logger> logger_;
};

std::shared_ptr<spdlog::logger> MyLogger::logger_ = nullptr;

void GetSubscriber(const std::string& id) {
    MyLogger::logInfo(log_var_msg.str());
    if (id.length() == 12) {
        // Вместо spdlog::info используйте MyLogger::logInfo
        log_var_msg << "Поиск местоположения для абонента: " << id;
        MyLogger::logInfo(log_var_msg.str());
    } else {
        log_var_msg << "Номер введён не корректно или не распознан. Введено: " << id;
        MyLogger::logInfo(log_var_msg.str());
    }
}

int main() {
    MyLogger::init("logfile.txt");
    GetSubscriber("+79398874657");
    spdlog::info("Checking functional for spdlog");  // Используйте MyLogger::logInfo для собственного логгера
    std::cout << "Checking Fetch" << std::endl;
    return 0;
}