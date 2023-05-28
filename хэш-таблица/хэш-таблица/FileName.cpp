#include <iostream>
#include <vector>

const int TABLE_SIZE = 10;

// Функция хеширования
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Класс хеш-таблицы
class HashTable {
private:
    std::vector<int> table[TABLE_SIZE];

public:
    // Вставка элемента в хеш-таблицу
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Поиск элемента в хеш-таблице
    bool search(int key) {
        int index = hashFunction(key);
        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

    // Вывод хеш-таблицы
    void printTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            std::cout << "Index " << i << ": ";
            for (int value : table[i]) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {

    setlocale(0, "ru");
    int arr[8];

    // Ввод массива
    std::cout << "Введите 8 целых чисел из диапазона 34000-62000:" << std::endl;
    for (int i = 0; i < 8; i++) {
        std::cin >> arr[i];
    }

    // Создание и заполнение хеш-таблицы
    HashTable hashtable;
    for (int i = 0; i < 8; i++) {
        hashtable.insert(arr[i]);
    }

    // Вывод исходного массива
    std::cout << "Исходный массив: ";
    for (int i = 0; i < 8; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Вывод хеш-таблицы
    std::cout << "Хеш-таблица:" << std::endl;
    hashtable.printTable();

    // Поиск элемента в хеш-таблице
    int searchKey;
    std::cout << "Введите элемент для поиска: ";
    std::cin >> searchKey;

    if (hashtable.search(searchKey)) {
        std::cout << "Элемент " << searchKey << " найден в хеш-таблице." << std::endl;
    }
    else {
        std::cout << "Элемент " << searchKey << " не найден в хеш-таблице." << std::endl;
    }

    return 0;
}