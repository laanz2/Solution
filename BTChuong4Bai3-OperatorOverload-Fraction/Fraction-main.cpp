#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include "Fraction.h"
using namespace std;

int menu() {
    int choice;
    cout << "Chuc nang he thong ho tro:\n";
    cout << "\t1. Tao 100 phan so duong ngau nhien (co tu va mau rong 1 doan xac dinh)\n";
    cout << "\t  Sau do co the:\n";
    cout << "\t    a. In ra cac phan so khong lon hon 1/2\n";
    cout << "\t    b. In ra cac phan so khong trung nhau\n";
    cout << "\t2. Tong hai phan so\n";
    cout << "\t3. Hieu hai phan so\n";
    cout << "\t4. Tich hai phan so\n";
    cout << "\t5. Thuong hai phan so\n";
    cout << "\t6. So sanh hai phan so\n";
    cout << "\t0. Thoat chuong trinh\n";
    cout << "\nNhap lua chon cua ban: ";
    cin >> choice;
    return choice;
}

Fraction input(string s) {
    int num, denom;
    cout << "- Nhap tu so va mau so cua phan so " << s;
    cout << "\n\t + Tu so : "; cin >> num;
    cout << "\t + Mau so : "; cin >> denom;
    cout << "\n";
    Fraction f(num, denom);
    return f;
}

void notGreater(vector<Fraction>& frList) {
    cout << "Cac phan so da tao khong lon hon 1/2 la:\n\n";
    int count = 0;
    for (Fraction& f : frList) {
        if (f < (Fraction(1, 2)) || f == (Fraction(1, 2))) {
            cout << f << "\t\t";
            count++;
            if (count % 5 == 0) {
                cout << "\n\n";
            }
        }
    }
}

void notMatch(vector<Fraction>& frList) {
    cout << "Cac phan so da tao khong trung nhau la:\n\n";
    int count = 0;
    for (int i = 0; i < frList.size(); i++) {
        bool isMatch = false;
        for (int j = 0; j < frList.size(); j++) {
            if (j != i && frList[i] == frList[j]) {
                isMatch = true;
                break;
            }
        }
        if (!isMatch) {
            cout << frList[i] << "\t\t";
            count++;
            if (count % 5 == 0) {
                cout << "\n\n";
            }
        }
    }
}

void fRandom(Fraction& f, vector<Fraction>& frList) {
    srand(time(NULL));
    int n;
    cout << "Doan [0, ?] ban muon: ";
    cin >> n;
    for (int i = 0; i < 100; i++) {
        Fraction f(n);
        frList.push_back(f);
    }
    cout << "\nDa tao 100 phan so duong ngau nhien co tu va mau thuoc doan [0, " << n << "] thanh cong!!!\n";
}

void math(int pick) {
    Fraction fr1 = input("thu nhat:");
    Fraction fr2 = input("thu hai:");
    if (pick == 2) {
        cout << "\n* Tong cua " << fr1 << " va " << fr2 << " la: " << fr1 + fr2 << "\n\n";
    }
    else if (pick == 3) {
        cout << "\n* Hieu cua " << fr1 << " va " << fr2 << " la: " << fr1 - fr2 << "\n\n";
    }
    else if (pick == 4) {
        cout << "\n* Tich cua " << fr1 << " va " << fr2 << " la: " << fr1 * fr2 << "\n\n";
    }
    else if (pick == 5) {
        cout << "\n* Thuong cua " << fr1 << " va " << fr2 << " la: " << fr1 / fr2 << "\n\n";
    }
    else {
        if (fr1 == fr2) {
            cout << "\n* Ket qua: " << fr1 << " = " << fr2;
        }
        else {
            if (fr1 < fr2) {
                cout << "\n* Ket qua: " << fr1 << " < " << fr2 << "\n\n";
            }
            else {
                cout << "\n* Ket qua: " << fr1 << " > " << fr2 << "\n\n";
            }
        }
    }
}

int main() {
    cout << "054205001985 - Do Ngoc Lan\n\n\n";
    vector<Fraction> fList;
    int choice;
    do {
        choice = menu();
        if (choice == 1) {
            Fraction fr(0, 1);
            system("cls");
            fRandom(fr, fList);
            char pick; cout << "\n";
            do {
                cout << "Ban co muon:\n\ta. In ra cac phan so khong lon hon 1/2\n\tb. In ra cac phan so khong trung nhau\n\tc. Quay tro lai Menu\n Ban chon: ";
                pick = _getch();
                switch (pick) {
                case 'a':
                    system("cls");
                    notGreater(fList);
                    cout << "\n\n"; system("pause");
                    break;
                case 'b':
                    system("cls");
                    notMatch(fList);
                    cout << "\n\n"; system("pause");
                    break;
                case 'c':
                    break;
                default:
                    break;
                }
                system("cls");
            } while (pick != 'c');
        }
        else if (choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6) {
            system("cls");
            math(choice);
            system("pause");
        }
        else if (choice == 0) {
            break;
        }
        else {
            system("cls");
            cout << "!!!Lua chon khong hop le. Moi chon lai.\n\n";
            system("pause");
        }
        system("cls");
    } while (choice != 0);

    return 0;
}