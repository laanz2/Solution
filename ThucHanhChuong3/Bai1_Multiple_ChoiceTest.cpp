#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class CauhoiTN {
private:
    string ques, a, b, ans;

public:

    void input() {
        cin.ignore();
        cout << "\nCau hoi: ";
        getline(cin, ques);
        cout << "\tA. ";
        getline(cin, a);
        cout << "\tB. ";
        getline(cin, b);
        cout << " *Dap an: ";
        getline(cin, ans);
    }

    void read_File(ifstream& f) {
        getline(f, ques);
        getline(f, a);
        getline(f, b);
        getline(f, ans);
    }

    void writes_File(ofstream& f) {
        f << "Cau hoi: " << ques;
        f << "\n\tA. " << a;
        f << "\n\tB. " << b;
        f << "\n *Dap an: " << ans << "\n";
    }

    bool check() {
        cout << "Cau hoi: " << ques;
        cout << "\n\tA. " << a;
        cout << "\n\tB. " << b;
        string yourAns;
        cout << "\n*Ban chon: ";
        cin >> yourAns;
        return yourAns == ans;
    }

    void output() {
        cout << "\nCau hoi: " << ques;
        cout << "\n\tA. " << a;
        cout << "\n\tB. " << b;
        cout << "\n *Dap an: " << ans;
        cout << "\n";
    }

    friend bool giongnhau(CauhoiTN ques1, CauhoiTN ques2) {
        return ques1.ques == ques2.ques && ques1.a == ques2.a && ques1.b == ques2.b && ques1.ans == ques2.ans;
    }
};

int menu() {
    int choice;
    cout << "Chuc nang he thong ho tro:\n";
    cout << "\t1. Tao de thi trac nghiem moi\n";
    cout << "\t2. Them cau hoi vao de thi hien hanh\n";
    cout << "\t3. Xem danh sach cau hoi hien co trong de thi\n";
    cout << "\t4. Luu de thi\n";
    cout << "\t5. Lay de thi tu file co san\n";
    cout << "\t6. Thi\n";
    cout << "\t0. Thoat chuong trinh\n";
    cout << "\nNhap lua chon cua ban: ";
    cin >> choice;
    return choice;
}

int main() {
    cout << "054205001985 - Do Ngoc Lan\n\n\n";
    vector<CauhoiTN> quesList;
    int choice;
    do {
        CauhoiTN test;
        choice = menu();
        switch (choice) {
        case 1: {
            quesList.clear();
            int number;
            system("cls");
            cout << "Nhap so cau hoi cua de can tao: ";
            cin >> number;
            for (int i = 1; i <= number; i++) {
                test.input();
                quesList.push_back(test);
            }
            cout << "\n";  system("pause");
            break;
        }
        case 2: {
            system("cls");
            int insert;
            cout << "Nhap so cau hoi muon them: ";
            cin >> insert;
            for (int i = 1; i <= insert; i++) {
                test.input();
                quesList.push_back(test);
            }
            cout << "\n";  system("pause");
            break;
        }
        case 3: {
            system("cls");
            if (quesList.empty()) {
                cout << "!!!Hien chua co de thi nao duoc tao. Ban co muon them de thi? (Nhan: 1 de them de thi, 0 de thoat..)";
                char qd; qd = _getch();
                if (qd == 1) {
                    int number;
                    system("cls");
                    cout << "Nhap so cau hoi cua de can tao: ";
                    cin >> number;
                    for (int i = 1; i <= number; i++) {
                        test.input();
                        quesList.push_back(test);
                    }
                }
            }
            else {
                for (CauhoiTN& test : quesList) {
                    test.output();
                }
            }
            cout << "\n";  system("pause");
            break;
        }
        case 4: {
            system("cls");
            string fileName;
            cout << "Nhap ten file muon luu (bao gom ca file type): ";
            cin.ignore();
            getline(cin, fileName);
            ofstream myFile(fileName.c_str());
            if (!myFile) {
                cout << "\nKhong the mo file de ghi.\n";
            }
            else {
                for (CauhoiTN& test : quesList) {
                    test.writes_File(myFile);
                }
                cout << "\nDa luu thanh cong!!!\n";
            }
            myFile.close();
            cout << "\n";  system("pause");
            break;
        }
        case 5: {
            system("cls");
            string fileName;
            cout << "Nhap ten file muon lay (bao gom ca file type): ";
            cin.ignore();
            getline(cin, fileName);
            ifstream _myFile(fileName.c_str());
            if (!_myFile) {
                cout << "\nKhong the mo file de doc.\n";
            }
            else {
                quesList.clear();
                while (!_myFile.eof()) {
                    test.read_File(_myFile);
                    quesList.push_back(test);
                }
                cout << "\nDa lay du lieu thanh cong!!!\n";
            }
            _myFile.close();
            cout << "\n";  system("pause");
            break;
        }
        case 6: {
            char qd, ansCorrect = 0;
            system("cls");
            for (CauhoiTN& test : quesList) {
                system("cls");
                if (test.check()) {
                    ansCorrect++;
                }
            }
            system("cls");
            cout << "\nSo cau dung: " << ansCorrect;
            cout << "\n\nBan co muon xem dap an cua de thi? (Nhan: 1 de xem, 0 de thoat.)";
            qd = _getch();
            if (qd == '1') {
                for (CauhoiTN& test : quesList) {
                    test.output();
                }
            }
            cout << "\n";  system("pause");
            break;
        }
        case 0: {
            cout << "Thoat chuong trinh.\n";
            break;
        }
        default: {
            cout << "Lua chon khong hop le.\n";
            cout << "\n";  system("pause");
            break;
        }
        }
        system("cls");
    } while (choice != 0);

    return 0;
}