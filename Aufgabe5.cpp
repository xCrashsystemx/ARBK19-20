#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;   

void kleinesAlphabet() {
    mtx.lock();
    for(char buchstabe = 'a';buchstabe <= 'z';buchstabe++) {
        std::cout << buchstabe;
    }
    std::cout << std::endl;
    mtx.unlock();
}

void natZahlen() {
    mtx.lock();
    for (int i = 0; i < 33; i++) {
        std::cout << i;
    }
    std::cout << std::endl;
    mtx.unlock();
}

void grossesAlphabet() {
    mtx.lock();
    for(char buchstabe = 'A';buchstabe <= 'Z';buchstabe++) {
        std::cout << buchstabe;
    }
    std::cout << std::endl;
    mtx.unlock();
}

int main() {
    std::thread first (kleinesAlphabet);
    std::thread second (natZahlen);
    std::thread third (grossesAlphabet);
    
    first.join(); 
    second.join();
    third.join();

    return 0;
}