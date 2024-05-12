#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class CauhoiTN {
private:
    string noi_dung;
    string tra_loiA;
    string tra_loiB;
    char cau_tra_loi_chinh_xac;

public:
    void nhap() {
        cin.ignore();
        cout << "Nhap noi dung: ";
        getline(cin, noi_dung);
        cout << "Nhap noi dung tra loi cau A: ";
        getline(cin, tra_loiA);
        cout << "Nhap noi dung tra loi cau B: ";
        getline(cin, tra_loiB);
        cout << "Nhap noi dung tra loi cau (A/B): ";
        cin >> cau_tra_loi_chinh_xac;
        cau_tra_loi_chinh_xac = toupper(cau_tra_loi_chinh_xac);
    }

    void docfile(ifstream& f) {
        getline(f, noi_dung);
        getline(f, tra_loiA);
        getline(f, tra_loiB);
        f >> cau_tra_loi_chinh_xac;
        f.ignore();
    }

    void recordingfile(ofstream& f) {
        f << noi_dung << endl;
        f << tra_loiA << endl;
        f << tra_loiB << endl;
        f << cau_tra_loi_chinh_xac << endl;
    }

    void kiemtra() {
        cout << "cau hoi: " << noi_dung << endl;
        cout << "A. " << tra_loiA << endl;
        cout << "B. " << tra_loiB << endl;
        char nguoi_dung_tra_loi;
        cout << "cau tra loi cua ban (A/B): ";
        cin >> nguoi_dung_tra_loi;
        nguoi_dung_tra_loi = toupper(nguoi_dung_tra_loi);
        if (nguoi_dung_tra_loi == cau_tra_loi_chinh_xac) {
            cout << "cau tra loi chinh xac!" << endl;
        }
        else {
            cout << "cau tra loi chua chinh xac!" << endl;
        }
    }

    void xuat() {
        cout << "cau hoi: " << noi_dung << endl;
        cout << "A. " << tra_loiA << endl;
        cout << "B. " << tra_loiB << endl;
        cout << "cau tra loi chinh xac: " << cau_tra_loi_chinh_xac << endl;
    }

    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};

bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
    return (cau1.noi_dung == cau2.noi_dung &&
        cau1.tra_loiA == cau2.tra_loiA &&
        cau1.tra_loiB == cau2.tra_loiB &&
        cau1.cau_tra_loi_chinh_xac == cau2.cau_tra_loi_chinh_xac);
}

int main() {
    vector<CauhoiTN> cau_hoi;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. tao bai kiem tra trac nghiem va luu tap tin (*.TTN)" << endl;
        cout << "2. doc noi dung*.TTN file de thu nghiem" << endl;
        cout << "3. Doc file TTN va xoa dau cach thua trong cau hoi dap, ghi de len file cu" << endl;
        cout << "4. Kiem tra xem hai cau hoi co giong nhau khong" << endl;
        cout << "5. loi ra" << endl;
        cout << "nhap_lua_chon_cua_ban: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            CauhoiTN question;
            question.nhap();
            cau_hoi.push_back(question);
            ofstream file("exam.TTN", ios::app);
            question.recordingfile(file);
            file.close();
            break;
        }
        case 2: {
            ifstream file("exam.TTN");
            if (file.is_open()) {
                CauhoiTN question;
                while (!file.eof()) {
                    question.docfile(file);
                    question.xuat();
                }
                file.close();
            }
            else {
                cout << "Khong tim thay tep hoac khong the mo đuoc!" << endl;
            }
            break;
        }
        case 3: {
            ifstream fileIn("exam.TTN");
            ofstream fileOut("exam.TTN.temp");
            if (fileIn.is_open() && fileOut.is_open()) {
                string line;
                while (getline(fileIn, line)) {
                    if (!line.empty()) {
                        fileOut << line << endl;
                    }
                }
                fileIn.close();
                fileOut.close();
                remove("exam.TTN");
                rename("exam.TTN.temp", "exam.TTN");
                cout << "Da xoa thanh cong khoang trang thua." << endl;
            }
            else {
                cout << "Khong tim thay tep hoac khong the mo duoc!" << endl;
            }
            break;
        }
        case 4: {
            CauhoiTN question1, question2;
            cout << "Nhap chi tiet cau hoi dau tien: " << endl;
            question1.nhap();
            cout << "Nhap chi tiet cau hoi thu hai: " << endl;
            question2.nhap();
            if (giongnhau(question1, question2)) {
                cout << "Cac cau hoi đeu giong nhau." << endl;
            }
            else {
                cout << "Cac cau hoi deu khac nhau." << endl;
            }
            break;
        }
        case 5:
            cout << "Thoat khoi chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap so tu 1 den 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
