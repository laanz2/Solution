// Demo_Menu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    cout << "054205001985 - Do Ngoc Lan\n\n";
    cout << "::::::::::::::Demo Menu Class::::::::::::\n";
    Menu m1("MENU CHINH");
    m1.themLuachon("Thoat chuong trinh");
    m1.themLuachon("Chuc nang 1");
    m1.themLuachon("Chuc nang 2");
    m1 << "Chuc nang 3"; // cau lenh sau khi cai dat toan tu chen (<<) o Class Menu
    m1 << "Chuc nang 4" << "Chuc nang 5" << "Chuc nang 6"; // cau lenh sau khi cai dat toan tu chen (<<) o Class Menu

    Menu m2("Xac nhan");
    m2.themLuachon("Dong y thuc hien");
    m2.themLuachon("Huy thao tac");
    m2 << "Dong y thuc hien";// cau lenh sau khi cai dat toan tu chen (<<) o Class Menu
    m2 << "Huy thao tac";// cau lenh sau khi cai dat toan tu chen (<<) o Class Menu

    while (true) {
        switch (m1.chon())
        {
        case 0:
            if (m2.chon() == 0)
                return 0; //Thoat chuong trinh
            break;
        case 1:
            if (m2.chon() == 0)
                cout << "Da thuc hien chuc nang 1\n";
            break;
        default:
            cout << "Xin loi chuc nang dang phat trien\n";
            break;
        }
    }
}