#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <map>
#include <iomanip>
using namespace std;

class SinhVien {
private:
    string mssv, hoTen;
    int vang;
    float diemTH, diemGK;

public:

    SinhVien(string ht, string ms, int v, float dth, float dgk)
        : hoTen(ht), mssv(ms), vang(v), diemTH(dth), diemGK(dgk) {}

    void input() {
        cin.ignore();
        cout << "*MSSV: ";
        getline(cin, mssv);
        cout << "- Ho va ten: ";
        getline(cin, hoTen);
        cout << "- So buoi vang: ";
        cin >> vang;
        cout << "- Diem thuc hanh: ";
        cin >> diemTH;
        cout << "- Diem giua ky: ";
        cin >> diemGK;
        cout << "\n";
    }

    void read_File(ifstream& f) {
        const char* a;
        string line;
        getline(f, mssv);
        getline(f, hoTen);
        getline(f, line);
        vang = stoi(line);
        getline(f, line);
        diemTH = stof(line);
        getline(f, line);
        diemGK = stof(line);
    }

    void writes_File(ofstream& f) {
        f << setfill(' ') << "\n" << setw(15) << left << mssv << setw(20) << left << hoTen << setw(20) << left << vang << setw(15) << left << diemTH << setw(15) << left << diemGK << setw(15) << left << diemQT();
    }

    void output() {
        cout << setfill(' ') << "\n" << setw(15) << left << mssv << setw(20) << left << hoTen << setw(20) << left << vang << setw(15) << left << diemTH << setw(15) << left << diemGK << setw(15) << left << diemQT();
    }

    float diemQT() {
        if (vang <= 5) {
            return (10 - vang * 2) * 0.2 + diemTH * 0.3 + diemGK * 0.5;
        }
        else { return 0; }
    }

    void ho(string fn) {
        string H = "", h = "";
        for (int i = 0; hoTen[i] != ' '; i++) {
            H += hoTen[i];
            h += tolower(hoTen[i]);
        }
        if (h == fn || H == fn) {
            output();
        }
    }

    string ten() {
        string t = "";
        for (int i = hoTen.length(); hoTen[i] != ' '; i--) {
            t = hoTen[i] + t;
        }
        return t;
    }

    void cungTen(vector<SinhVien>& ds, SinhVien& s) {
        cout << "Danh sach sinh vien co cung ten voi mot sinh vien khac:\n";
        cout << "\n" << setfill(' ') << setw(15) << left << "MSSV" << setw(20) << left << "Ho va ten" << setw(20) << left << "So buoi vang" << setw(15) << left << "Diem TH" << setw(15) << left << "Diem GK" << setw(15) << left << "Diem QT";
        cout << "\n" << setfill('-') << setw(100) << "-";
        vector<int> tenSV;
        vector<string> dsTen;
        for (int i = 0; i < ds.size(); i++) {
            tenSV.clear();
            bool flag = true;
            for (vector<string>::iterator it = dsTen.begin(); it != dsTen.end(); ++it) {
                if (ds[i].ten() == *it) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                continue;
            }
            dsTen.push_back(ds[i].ten());
            bool isAdded = false;
            for (int j = i + 1; j < ds.size(); j++) {
                if (ds[j].ten() == ds[i].ten()) {
                    if (!isAdded) {
                        tenSV.push_back(i);
                        isAdded = true;
                    }
                    tenSV.push_back(j);
                }
            }
            for (vector<int>::iterator it = tenSV.begin(); it != tenSV.end(); ++it) {
                ds[*it].output();
            }
            cout << "\n";
        }
    }
};

void luuDS(vector<SinhVien>& ds, bool dk) {
    char pick;
    cout << "\n\nBan co muon luu danh sach nay? (Nhan 1 de luu)";
    pick = _getch();
    if (pick == '1') {
        string fileName;
        cout << "\nNhap ten file muon luu (bao gom ca file type): ";
        cin.ignore();
        getline(cin, fileName);
        ofstream myFile(fileName.c_str());
        if (!myFile) {
            cout << "\nKhong the mo file de ghi.\n";
        }
        else {
            myFile << "\n" << setfill(' ') << setw(15) << left << "MSSV" << setw(20) << left << "Ho va ten" << setw(20) << left << "So buoi vang" << setw(15) << left << "Diem TH" << setw(15) << left << "Diem GK" << setw(15) << left << "Diem QT";
            myFile << "\n" << setfill('-') << setw(100) << "-";
            for (SinhVien& s : ds) {
                if (!dk || s.diemQT() >= 3) {
                    s.writes_File(myFile);
                }
            }
            cout << "\nDa luu thanh cong!!!\n";
        }
        myFile.close();
    }
}

int menu() {
    int choice;
    cout << "Chuc nang he thong ho tro:\n";
    cout << "\t1. Tao du lieu\n";
    cout << "\t  a. Nhap thu cong\n";
    cout << "\t  b. Lay tu tep co san\n";
    cout << "\t2. Tinh diem qua trinh\n";
    cout << "\t3. Danh sach sinh vien du dieu kien du thi (DiemQT >= 3)\n";
    cout << "\t4. Danh sach sinh vien co cung ho\n";
    cout << "\t5. Danh sach cac sinh vien cung ten\n";
    cout << "\t0. Thoat chuong trinh\n";
    cout << "\nNhap lua chon cua ban: ";
    cin >> choice;
    return choice;
}

int main() {
    cout << "054305001985 - Do Ngoc Lan\n\n\n";
    vector<SinhVien> dsSinhVien;
    int choice;
    do {
        SinhVien sv("Nguyen Van A", "SV001", 1, 8.5, 7.0);
        choice = menu();
        switch (choice) {
        case 1: {
            dsSinhVien.clear();
            int number;
            char pick;
            system("cls");
            cout << "Ban chon?\n";
            cout << "   a. Nhap thu cong\n";
            cout << "   b. Lay tu tep co san\n";
            pick = _getch();
            system("cls");
            string fileName;
            ifstream myFile;
            switch (pick) {
            case 'a':
                cout << "Nhap so sinh vien can tao du lieu: ";
                cin >> number;
                cout << "\n";
                for (int i = 1; i <= number; i++) {
                    sv.input();
                    dsSinhVien.push_back(sv);
                }
                break;
            case 'b':
                cout << "\nNhap ten file muon lay du lieu (bao gom ca file type): ";
                cin.ignore();
                getline(cin, fileName);
                myFile.open(fileName.c_str());
                if (!myFile) {
                    cout << "\nKhong the mo file de lay du lieu.\n";
                }
                else {
                    while (!myFile.eof()) {
                        sv.read_File(myFile);
                        dsSinhVien.push_back(sv);
                    }
                    cout << "\nDa lay du lieu thanh cong!!!\n";
                }
                myFile.close();
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
            }
            cout << "\n\n";  system("pause");
            break;
        }
        case 2: {
            system("cls");
            cout << setfill(' ') << setw(15) << left << "MSSV" << setw(20) << left << "Ho va ten" << setw(20) << left << "So buoi vang" << setw(15) << left << "Diem TH" << setw(15) << left << "Diem GK" << setw(15) << left << "Diem QT";
            cout << "\n" << setfill('-') << setw(100) << "-";
            for (SinhVien& sv : dsSinhVien) {
                sv.diemQT();
                sv.output();
            }
            luuDS(dsSinhVien, true);
            cout << "\n\n";  system("pause");
            break;
        }
        case 3: {
            system("cls");
            cout << "Danh sach sinh vien du dieu kien du thi (DiemQT >= 3):\n\n";
            cout << setfill(' ') << setw(15) << left << "MSSV" << setw(20) << left << "Ho va ten" << setw(20) << left << "So buoi vang" << setw(15) << left << "Diem TH" << setw(15) << left << "Diem GK" << setw(15) << left << "Diem QT";
            cout << "\n" << setfill('-') << setw(100) << "-";
            for (SinhVien& sv : dsSinhVien) {
                if (sv.diemQT() >= 3) {
                    sv.output();
                }
            }
            luuDS(dsSinhVien, false);
            cout << "\n\n";  system("pause");
            break;
        }
        case 4: {
            system("cls");
            string fn;
            cout << "Danh sach sinh vien co cung ho? ";
            cin.ignore();
            getline(cin, fn);
            cout << "\n" << setfill(' ') << setw(15) << left << "MSSV" << setw(20) << left << "Ho va ten" << setw(20) << left << "So buoi vang" << setw(15) << left << "Diem TH" << setw(15) << left << "Diem GK" << setw(15) << left << "Diem QT";
            cout << "\n" << setfill('-') << setw(100) << "-";
            for (SinhVien& sv : dsSinhVien) {
                sv.ho(fn);
            }
            cout << "\n\n";  system("pause");
            break;
        }
        case 5: {
            system("cls");
            sv.cungTen(dsSinhVien, sv);
            cout << "\n\n";  system("pause");
            break;
        }
        case 0: {
            cout << "Thoat chuong trinh.\n";
            break;
        }
        default: {
            cout << "Lua chon khong hop le.\n";
            cout << "\n\n";  system("pause");
            break;
        }
        }
        system("cls");
    } while (choice != 0);

    return 0;
}