#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    PhanSo(int tuSo = 0, int mauSo = 1) : tuSo(tuSo), mauSo(mauSo) {}

    friend ostream& operator<<(ostream& os, const PhanSo& phanSo) {
        os << phanSo.tuSo << "/" << phanSo.mauSo;
        return os;
    }

    friend istream& operator>>(istream& is, PhanSo& phanSo) {
        is >> phanSo.tuSo >> phanSo.mauSo;
        return is;
    }

    PhanSo operator+(const PhanSo& other) const {
        return PhanSo(tuSo * other.mauSo + other.tuSo * mauSo, mauSo * other.mauSo);
    }

    PhanSo operator-(const PhanSo& other) const {
        return PhanSo(tuSo * other.mauSo - other.tuSo * mauSo, mauSo * other.mauSo);
    }

    PhanSo operator*(const PhanSo& other) const {
        return PhanSo(tuSo * other.tuSo, mauSo * other.mauSo);
    }

    PhanSo operator/(const PhanSo& other) const {
        return PhanSo(tuSo * other.mauSo, mauSo * other.tuSo);
    }
};

class BieuThucSoHoc {
protected:
    int a, b;
    char pheptoan;

public:
    BieuThucSoHoc() {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        pheptoan = generateOperator();
    }

    char generateOperator() {
        return (rand() % 3 == 0) ? '*' : (rand() % 2 == 0) ? '+' : '-';
    }

    friend ostream& operator<<(ostream& os, const BieuThucSoHoc& bieuThuc) {
        os << bieuThuc.a << " " << bieuThuc.pheptoan << " " << bieuThuc.b;
        return os;
    }

    friend istream& operator>>(istream& is, BieuThucSoHoc& bieuThuc) {
        is >> bieuThuc.a >> bieuThuc.pheptoan >> bieuThuc.b;
        return is;
    }

    virtual int tinhKetQua() const {
        switch (pheptoan) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return 0; // Không nên xảy ra
        }
    }
};

class BieuThucCong : public BieuThucSoHoc {
public:
    int tinhKetQua() const override {
        return a + b;
    }
};

class BieuThucTru : public BieuThucSoHoc {
public:
    int tinhKetQua() const override {
        return a - b;
    }
};

class BieuThucNhan : public BieuThucSoHoc {
public:
    int tinhKetQua() const override {
        return a * b;
    }
};

class BieuThucBacHai : public BieuThucSoHoc {
public:
    int tinhKetQua() const override {
        return a * a + b * b;
    }
};

class BieuThucPhucTap : public BieuThucSoHoc {
public:
    int tinhKetQua() const override {
        return (a + b) * (a + b);
    }
};

class BieuThucPhanSo : public BieuThucSoHoc {
public:
    PhanSo tinhKetQua() const override {
        PhanSo aFraction(a, 1);
        PhanSo bFraction(b, 1);
        switch (pheptoan) {
        case '+':
            return aFraction + bFraction;
        case '-':
            return aFraction - bFraction;
        case '*':
            return aFraction * bFraction;
        case '/':
            return aFraction / bFraction;
        default:
            return PhanSo(); // Không nên xảy ra
        }
    }
};

int main() {
    srand(time(nullptr));
    int level = 1;
    int score = 0;
    int n1 = 5; // Số lượng câu hỏi cộng
    int n2 = 5; // Số lượng câu hỏi trừ
    int n3 = 5; // Số lượng câu hỏi nhân

    while (true) {
        int totalQuestions = n1 + n2 + n3;
        cout << "Muc do kho: " << level << endl;
        cout << "Diem hien tai: " << score << "/" << totalQuestions << endl;

        for (int i = 0; i < n1; ++i) {
            BieuThucSoHoc* bieuThuc = new BieuThucCong();
            cout << "Cau " << (i + 1) << ": " << *bieuThuc << " = ?";
            int userAnswer;
            cin >> userAnswer;
            if (userAnswer == bieuThuc->tinhKetQua())
                score++;
            delete bieuThuc;
        }

        for (int i = 0; i < n2; ++i) {
            BieuThucSoHoc* bieuThuc = new BieuThucTru();
            cout << "Cau " << (i + 1) << ": " << *bieuThuc << " = ?";
            int userAnswer;
            cin >> userAnswer;
            if (userAnswer == bieuThuc->tinhKetQua())
                score++;
            delete bieuThuc;
        }

        for (int i = 0; i < n3; ++i) {
            BieuThucSoHoc* bieuThuc = new BieuThucNhan();
            cout << "Câu " << (i + 1) << ": " << *bieuThuc << " = ?";
            int userAnswer;
            cin >> userAnswer;
            if (userAnswer == bieuThuc->tinhKetQua())
                score++;
            delete bieuThuc;
        }

        if (score == totalQuestions) {
            level++;
            score = 0;
        }
        else {
            break;
        }
    }

    cout << "Tong diem: " << score << endl;
    return 0;
}
