// STC_2.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

//int lcg(int x0, int x1, int x2, int x3) {//Linear congruential generator. 
int lcg(int x[5]){


    int max = 0; 
    for (int i = 0; i < 4; i++) {//ищу максимальный X среди заданных. Это позволит ограничить модуль (переменную m снизу)
        if (max < x[i]) {max = x[i]; }          
    }

    for (int m = max + 1; m < 65536; m++) {//по условию модуль ограничен 65535.
        for (int a = 1; a < m; a++) {//Ограничиваем значения сверху модулем
            for (int c = 0; c < m; c++) {
                if ((x[0] * a + c) % m == x[1] && (x[1] * a + c) % m == x[2] && (x[2] * a + c) % m == x[3]) {//проверяю переменные для чисел
                    return (a * x[3] + c) % m;//возвращаю 5-ой число последовательности
                }
            }
        }
    }
    return 0;
}
int main(){

    int x[5] = {157,5054,25789,13214,0};
    cout << "Answer: " << lcg(x);

    int y[5];

    cout << endl << "Enter x0: ";
    cin >> y[0];
    cout << "Enter x1: ";
    cin >> y[1];
    cout << "Enter x2: ";
    cin >> y[2];
    cout << "Enter x3: ";
    cin >> y[3];

    cout << "Answer: " << lcg(y);
}