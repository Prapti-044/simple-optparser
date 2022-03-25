#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

inline int sub(int a, int b) {
    return a - b;
}

int main() {
    int a = 5;
    int b = 10;
    int c = a + b;

    int d = add(a,b);
    int e = sub(a, b);

    int g = 0;
    for(int i = 0; i<10; i++) {
        g -= sub(a,b);

        for(int j = 0; j<10; j++) {
            g += add(a, b);
        }
    }

    cout << g << endl;

    for(int i = 0; i<10; i++) {
        cout << "hello" << endl;
    }

    std::cout << "hello" << std::endl;

    return 0;
}