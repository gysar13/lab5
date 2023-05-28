#include <iostream>
#include <vector>

const int TABLE_SIZE = 10;

// ������� �����������
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// ����� ���-�������
class HashTable {
private:
    std::vector<int> table[TABLE_SIZE];

public:
    // ������� �������� � ���-�������
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // ����� �������� � ���-�������
    bool search(int key) {
        int index = hashFunction(key);
        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

    // ����� ���-�������
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

    // ���� �������
    std::cout << "������� 8 ����� ����� �� ��������� 34000-62000:" << std::endl;
    for (int i = 0; i < 8; i++) {
        std::cin >> arr[i];
    }

    // �������� � ���������� ���-�������
    HashTable hashtable;
    for (int i = 0; i < 8; i++) {
        hashtable.insert(arr[i]);
    }

    // ����� ��������� �������
    std::cout << "�������� ������: ";
    for (int i = 0; i < 8; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // ����� ���-�������
    std::cout << "���-�������:" << std::endl;
    hashtable.printTable();

    // ����� �������� � ���-�������
    int searchKey;
    std::cout << "������� ������� ��� ������: ";
    std::cin >> searchKey;

    if (hashtable.search(searchKey)) {
        std::cout << "������� " << searchKey << " ������ � ���-�������." << std::endl;
    }
    else {
        std::cout << "������� " << searchKey << " �� ������ � ���-�������." << std::endl;
    }

    return 0;
}