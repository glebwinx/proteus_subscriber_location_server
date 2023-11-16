#include <iostream>
#include <spdlog/spdlog.h>
#include <string>
#include <cmath>


//Загрузка из файла конфигурации списка зон
void GetZoneFromFile(){

};

// Получение и хранение местоположения абонента
void GetSubscriber(std:: string& id){

};
// Конфигурирование зон
void AddZone(int id, std:: string& NameZone, int x, int y, int radius){

};
// Получение списка зон в которых находится абонент
void SetSubscriberLocation(std:: string& id, int x, int y){

};

// Выдача списка абонентов, которые находятся в зоне id
void GetSubscriberinZone(int id){

};

// Триггер на зону
void TriggerOnZone(){

};

// Триггер на сближение абонентов
void TriggerForUnionSubscribers(){

};


int main(){
    spdlog::info("Checking functional");
    std::cout << "Checking Fetch" << std::endl;
    return 0;
};