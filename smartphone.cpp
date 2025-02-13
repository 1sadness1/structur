#include <iostream>
#include <vector>
#include <string>

struct Smartphone {
    std::string manufacturer;
    int memorySize;
    double price;
};


void inputSmartphone(Smartphone* phone) {
    std::cout << "Введите производителя: ";
    std::getline(std::cin, phone->manufacturer);

    std::cout << "Введите объем встроенной памяти (в ГБ): ";
    std::cin >> phone->memorySize;
    std::cin.ignore(); 

    std::cout << "Введите цену: ";
    std::cin >> phone->price;
    std::cin.ignore();
}

void printSmartphone(const Smartphone& phone) {
    std::cout << "Производитель: " << phone.manufacturer << "\n";
    std::cout << "Объем памяти: " << phone.memorySize << " ГБ\n";
    std::cout << "Цена: " << phone.price << " руб.\n";
}

// Функция для создания динамических экземпляров структур и сохранения их в вектор
std::vector<Smartphone*> createDynamicInstances(int count) {
    std::vector<Smartphone*> phones;

    for (int i = 0; i < count; ++i) {
        Smartphone* phone = new Smartphone;
        inputSmartphone(phone);
        phones.push_back(phone);
    }

    return phones;
}

void menu() {
    std::cout << "Меню:\n";
    std::cout << "1. Добавить смартфон\n";
    std::cout << "2. Вывести информацию о всех смартфонах\n";
    std::cout << "3. Завершить программу\n";
    std::cout << "Ваш выбор: ";
}

int main() {
    std::vector<Smartphone*> smartphones;

    while (true) {
        menu();

        int choice;
        std::cin >> choice;
        std::cin.ignore(); 

        if (choice == 1) {
            Smartphone* phone = new Smartphone;
            inputSmartphone(phone);
            smartphones.push_back(phone);

            std::cout << "Смартфон добавлен!\n";
        }
        else if (choice == 2) {
            if (!smartphones.empty()) {
                std::cout << "Информация о смартфонах:\n";

                for (const auto& phone : smartphones) {
                    printSmartphone(*phone);
                    std::cout << "\n";
                }
            }
            else {
                std::cout << "Нет смартфонов для отображения.\n";
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            std::cout << "Неверный ввод! Попробуйте еще раз.\n";
        }
    }

    // Освобождаем память
    for (auto phone : smartphones) {
        delete phone;
    }

    return 0;
}