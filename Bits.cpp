#include <iostream>
using namespace std;

void write(unsigned int number, int bytes) {
    long long int bitCounter = 1;
    for (int i = 0; i < 8 * bytes; i++) {
        bitCounter *= 2;
    }
    bitCounter /= 2;

    int count = 1;
    cout << "Number " << number << " in " << bytes << " bytes: ";
    for (; bitCounter > 0; bitCounter /= 2) {
        if (number & bitCounter)

            cout << "1";
        else
            cout << "0";

        if (count == 8) {
            cout << " ";
            count = 1;
        } else
            count++;
    }
    cout << endl;
}

int setBit(int num, int position) {
    int mask = 1 << position;
    return num | mask;
}

bool getBit(int num, int position) {
    bool bit = num & (1 << position);
    return bit;
}

int clearBit(int num, int position) {
    int mask = 1 << position;
    return num & ~mask;
}

int main() {
    unsigned int a = 0;
    cout << "Give a number: ";
    cin >> a;
    write(a, 1);
    a = setBit(a, 3);
    write(a, 1);
    cout << a << endl;

    a = clearBit(a, 2);
    write(a, 1);
    cout << a << endl;

    return 0;
}
