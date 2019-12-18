#include <iostream>
#include <thread>
#include <atomic>

class Semphore {
private:
    std::atomic<int> anzressourcen;

public:
    Semphore(int anzressourcen) {
        this->anzressourcen = anzressourcen;
    }

    void wait() {
        while (this->anzressourcen == 0) {
        }
        anzressourcen--;
    }

    void release() {
        anzressourcen++;
    }

};

Semphore sa(1);

void kleinesAlphabet() {
    sa.wait();
    for(char buchstabe = 'a';buchstabe <= 'z';buchstabe++) {
        std::cout << buchstabe;
    }
    std::cout << std::endl;
    sa.release();
}

void natZahlen() {
    sa.wait();
    for (int i = 0; i < 33; i++) {
        std::cout << i;
    }
    std::cout << std::endl;
    sa.release();
}

void grossesAlphabet() {
    sa.wait();
    for(char buchstabe = 'A';buchstabe <= 'Z';buchstabe++) {
        std::cout << buchstabe;
    }
    std::cout << std::endl;
    sa.release();
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