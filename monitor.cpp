#include <iostream>
#include <vector>
#include <string>

struct Monitor {
    std::string manufacturer;
    int screenSize;
    double price;
};

void inputMonitor(Monitor* monitor) {
    std::cout << "Введите фирму-производителя: ";
    std::getline(std::cin, monitor->manufacturer);
    
    std::cout << "Введите размер экрана: ";
    std::cin >> monitor->screenSize;
    std::cin.ignore(); // Для очистки буфера после cin

    std::cout << "Введите цену: ";
    std::cin >> monitor->price;
    std::cin.ignore(); 
}


void printMonitor(const Monitor& monitor) {
    std::cout << "Фирма-производитель: " << monitor.manufacturer << '\n';
    std::cout << "Размер экрана: " << monitor.screenSize << " дюймов\n";
    std::cout << "Цена: " << monitor.price << " рублей\n";
}

// Функция создания экземпляров структур и сохранения их в вектор
std::vector<Monitor> createMonitors(int count) {
    std::vector<Monitor> monitors;
    for (int i = 0; i < count; ++i) {
        Monitor monitor;
        inputMonitor(&monitor);
        monitors.push_back(monitor);
    }
    return monitors;
}

int main() {
    std::vector<Monitor> monitors;
    bool running = true;
    while (running) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить монитор\n";
        std::cout << "2. Вывести информацию о мониторах\n";
        std::cout << "3. Выход\n";
        
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Сколько мониторов добавить? ";
                int count;
                std::cin >> count;
                std::cin.ignore();
                monitors = createMonitors(count);
                break;
            case 2:
                if (!monitors.empty()) {
                    for (const auto& monitor : monitors) {
                        printMonitor(monitor);
                    }
                } else {
                    std::cout << "Нет добавленных мониторов.\n";
                }
                break;
            case 3:
                running = false;
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    std::cout << "Программа завершена.\n";
    return 0;
}