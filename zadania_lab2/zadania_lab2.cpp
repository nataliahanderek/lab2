#include <iostream>
#include <algorithm>
#include <locale.h>
using namespace std;

void swap_zadanie1(int *x, int *y){
    
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap_zadanie2(int &x, int &y) {

    int tmp = x;
    x = y;
    y = tmp;
}

void swap_zadanie3(int &x, int *y) {

    int tmp = x;
    x = *y;
    *y = tmp;
}

int funkcja_zadanie4(int x, int y, int &suma){

    suma = x + y;
    return x * y;
}

namespace fun
{
    template < typename T >
    void swap_zadanie5(T &z, T &s){

        T tmp = z;
        z = s;
        s = tmp;
    }
}

template < typename T >
void swap_zadanie6(T &x,T &y) {

    T t(move (x));
    x = move (y);
    y = move (t);
}

int main() {

    int x, y;
    cout << "Podaj dwie liczby calkowite, aby przetestowac funkcje: ";
    cin >> x >> y;

    cout << "Przed wykonaniem funkcji: x = " << x << "\t y = " << y << endl;

    //zadanie 1
    if(x > y) {
        swap_zadanie1(&x, &y);
        cout << "Po wykonaniu funkcji 1: x = " << x << "\t y = " << y << endl;
    } else {
        cout << "Po wykonaniu funkcji 1: x = " << x << "\t y = " << y << endl;
    }

    //zadanie 2
    swap_zadanie2(x, y);
    cout << "Po wykonaniu funkcji 2: x = " << x << "\t y = " << y << endl;

    //zadanie 3
    swap_zadanie3(x, &y);
    cout << "Po wykonaniu funkcji 3: x = " << x << "\t y = " << y << endl;

    //zadanie4
    int suma = 0;
    int iloczyn = funkcja_zadanie4(x, y, suma);
    cout << "Po wykonaniu funkcji 4: suma = " << suma << "\t iloczyn = " << iloczyn << endl;

    //zadanie5
    fun::swap_zadanie5(x, y);
    cout << "Po wykonaniu funkcji 5: x = " << x << "\t y = " << y << endl;
    string z, s;
    cout << "Podaj pierwszy i drugi wyraz, aby je ze soba zamienic: ";
    cin >> z >> s;
    fun::swap_zadanie5(z, s);
    cout << "Po wykonaniu funkcji 5: wyraz 1 = " << z << "\t wyraz 2 = " << s << endl;
    
    //zadanie6
    swap_zadanie6(x, y);
    cout << "Po wykonaniu funkcji 6: x = " << x << "\t y = " << y << endl;
    swap_zadanie6(z, s);
    cout << "Po wykonaniu funkcji 6: wyraz 1 = " << z << "\t wyraz 2 = " << s << endl;

    return 0;
}
