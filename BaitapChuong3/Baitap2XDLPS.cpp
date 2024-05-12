#include <iostream>
#include <string> //Thêm thư viện string vào đây
using namespace std;

class Student {
private:
    string studentID;
    string name;
    float averMark;

public:
    void input() {
        cout << "Nhap ma sinh vien: ";
        cin >> studentID;
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap diem trung binh: ";
        cin >> averMark;
    }

    void print() {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Average Mark: " << averMark << endl;
    }

    float getAverageMark() {
        return averMark;
    }
};

class Fraction {
private:
    int numerator;
    int denominator;

public:
    void input() {
        cout << "Nhap tu so: ";
        cin >> numerator;
        cout << "Nhap mau so: ";
        cin >> denominator;
    }

    void print() {
        cout << "Fraction: " << numerator << "/" << denominator << endl;
    }

    Fraction add(const Fraction& f) {
        Fraction result;
        result.numerator = numerator * f.denominator + f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        return result;
    }
};

int main() {
    cout << "054205001985_DoNgocLan" << endl;
    Student student;
    Fraction fraction1, fraction2, sum;

    cout << "Nhap thong tin sinh vien:" << endl;
    student.input();
    cout << endl;

    cout << "Nhap phan so dau tien:" << endl;
    fraction1.input();
    cout << endl;

    cout << "Nhap phan so thu hai:" << endl;
    fraction2.input();
    cout << endl;

    sum = fraction1.add(fraction2);

    cout << "Thong tin sinh vien:" << endl;
    student.print();
    cout << endl;

    cout << "Tong cac phan so:" << endl;
    sum.print();

    return 0;
}