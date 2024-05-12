#include <iostream>
#include <string>
#include <vector>

class DiemHocVien {
private:
    std::string hoTen;
    int namSinh;
    float diemMon1;
    float diemMon2;
    float diemMon3;

public:
    DiemHocVien() : hoTen(""), namSinh(0), diemMon1(0), diemMon2(0), diemMon3(0) {}

    DiemHocVien(std::string ten, int nam, float diem1, float diem2, float diem3)
        : hoTen(ten), namSinh(nam), diemMon1(diem1), diemMon2(diem2), diemMon3(diem3) {}

    ~DiemHocVien() {}

    // Getter và setter
    void setHoTen(std::string ten) { hoTen = ten; }
    std::string getHoTen() const { return hoTen; }

    void setNamSinh(int nam) { namSinh = nam; }
    int getNamSinh() const { return namSinh; }

    void setDiemMon1(float diem) { diemMon1 = diem; }
    float getDiemMon1() const { return diemMon1; }

    void setDiemMon2(float diem) { diemMon2 = diem; }
    float getDiemMon2() const { return diemMon2; }

    void setDiemMon3(float diem) { diemMon3 = diem; }
    float getDiemMon3() const { return diemMon3; }

    // Phương thức tính điểm trung bình
    float diemTrungBinh() const {
        return (diemMon1 + diemMon2 + diemMon3) / 3;
    }

    // Phương thức kiểm tra xem học viên có làm luận văn tốt nghiệp hay không
    bool lamLuanVanTotNghiep() const {
        return (diemTrungBinh() > 7 && diemMon1 >= 5 && diemMon2 >= 5 && diemMon3 >= 5);
    }

    // Phương thức kiểm tra xem học viên đã thi tốt nghiệp hay không
    bool thiTotNghiep() const {
        return (diemTrungBinh() <= 7 && diemMon1 >= 5 && diemMon2 >= 5 && diemMon3 >= 5);
    }

    // Phương thức kiểm tra xem học viên cần thi lại hay không và trả về tên các môn thi lại
    std::vector<std::string> monThiLai() const {
        std::vector<std::string> monThiLai;
        if (diemMon1 < 5) monThiLai.push_back("Mon 1");
        if (diemMon2 < 5) monThiLai.push_back("Mon 2");
        if (diemMon3 < 5) monThiLai.push_back("Mon 3");
        return monThiLai;
    }

    // Toán tử xuất
    friend std::ostream& operator<<(std::ostream& os, const DiemHocVien& hocVien) {
        os << "Ho ten: " << hocVien.hoTen << std::endl;
        os << "Nam sinh: " << hocVien.namSinh << std::endl;
        os << "Diem Mon 1: " << hocVien.diemMon1 << std::endl;
        os << "Diem Mon 2: " << hocVien.diemMon2 << std::endl;
        os << "Diem Mon 3: " << hocVien.diemMon3 << std::endl;
        return os;
    }
};

class Test {
public:
    void menu() {
        int choice;
        std::vector<DiemHocVien> danhSachHocVien;
        do {
            std::cout << "-------------------------------------------\n";
            std::cout << "MENU QUAN LI HOC VIEN\n";
            std::cout << "1. Tao diem hoc vien\n";
            std::cout << "2. Xem thong tin hoc vien\n";
            std::cout << "3. Kiem tra lam luan van tot nghiep\n";
            std::cout << "4. Kiem tra thi tot nghiep\n";
            std::cout << "5. Kiem tra thi lai\n";
            std::cout << "6. Thong ke\n";
            std::cout << "0. Thoat\n";
            std::cout << "--------------------------------------------\n";
            std::cout << "Lua chon cua ban: ";
            std::cin >> choice;
            switch (choice) {
            case 1: {
                // Thêm học viên mới vào danh sách
                std::string ten;
                int namSinh;
                float diem1, diem2, diem3;
                std::cout << "Nhap ho ten: ";
                std::cin.ignore();
                std::getline(std::cin, ten);
                std::cout << "Nhap nam sinh: ";
                std::cin >> namSinh;
                std::cout << "Nhap diem Mon 1: ";
                std::cin >> diem1;
                std::cout << "Nhap diem Mon 2: ";
                std::cin >> diem2;
                std::cout << "Nhap diem Mon 3: ";
                std::cin >> diem3;
                danhSachHocVien.push_back(DiemHocVien(ten, namSinh, diem1, diem2, diem3));
                break;
            }
            case 2: {
                // Xem thông tin của học viên
                for (const auto& hocVien : danhSachHocVien) {
                    std::cout << hocVien << std::endl;
                }
                break;
            }
            case 3: {
                // Kiểm tra học viên làm luận văn tốt nghiệp
                int LamLuanVan = 0;
                for (const auto& hocVien : danhSachHocVien) {
                    if (hocVien.lamLuanVanTotNghiep()) {
                        std::cout << hocVien.getHoTen() << " lam luan van tot nghiep." << std::endl;
                        LamLuanVan++;
                    }
                }
                std::cout << "So luong hoc vien lam luan van tot nghiep: " << LamLuanVan << std::endl;
                break;
            }
            case 4: {
                // Kiểm tra học viên thi tốt nghiệp
                int ThiTotNghiep = 0;
                for (const auto& hocVien : danhSachHocVien) {
                    if (hocVien.thiTotNghiep()) {
                        std::cout << hocVien.getHoTen() << " thi tot nghiep." << std::endl;
                        ThiTotNghiep++;
                    }
                }
                std::cout << "So luong hoc vien thi tot nghiep: " << ThiTotNghiep << std::endl;
                break;
            }
            case 5: {
                // Kiểm tra học viên thi lại
                int ThiLai = 0;
                for (const auto& hocVien : danhSachHocVien) {
                    auto monThiLai = hocVien.monThiLai();
                    if (!monThiLai.empty()) {
                        std::cout << hocVien.getHoTen() << " phai thi lai mon: ";
                        for (const auto& mon : monThiLai) {
                            std::cout << mon << ", ";
                        }
                        std::cout << std::endl;
                        ThiLai++;
                    }
                }
                std::cout << "So luong hoc vien phai thi lai: " << ThiLai << std::endl;
                break;
            }
            case 6: {
                // Thống kê
                int LamLuanVan = 0;
                int ThiTotNghiep = 0;
                int ThiLai = 0;
                for (const auto& hocVien : danhSachHocVien) {
                    if (hocVien.lamLuanVanTotNghiep()) {
                        LamLuanVan++;
                    }
                    if (hocVien.thiTotNghiep()) {
                        ThiTotNghiep++;
                    }
                    if (!hocVien.monThiLai().empty()) {
                        ThiLai++;
                    }
                }
                std::cout << "So luong hoc vien lam luan van tot nghiep: " << LamLuanVan << std::endl;
                std::cout << "So luong hoc vien thi tot nghiep: " << ThiTotNghiep << std::endl;
                std::cout << "So luong hoc vien phai thi lai: " << ThiLai << std::endl;
                break;
            }
            case 0:
                std::cout << "Thoat chuong trinh.\n";
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai.\n";
            }
        } while (choice != 0);
    }
};


int main() {
    std::cout << "054205001985 - Do Ngoc Lan\n\n\n";
    Test test;
    test.menu();
    return 0;
}