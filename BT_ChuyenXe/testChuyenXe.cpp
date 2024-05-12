#include<iostream>
#include"ChuyenXe.h"
#include"NgoaiThanh.h"
#include"NoiThanh.h"
#include<string>
using namespace std;
string chuanHoaTen2(string& ten)
{
	ten[0] = toupper(ten[0]);
	for (int i = 1; i < ten.size(); i++)
	{
		ten[i] = tolower(ten[i]);
	}
	return ten;
}
void chuanHoaTen1(string& hoTenTaiXe)
{
	string tenTamThoi; string ten = "";
	vector<string> chuoiTen;
	while (hoTenTaiXe[0] == ' ')
	{
		hoTenTaiXe.erase(hoTenTaiXe.begin() + 0);
	}
	for (int i = 0; i < hoTenTaiXe.size(); i++)
	{
		if (hoTenTaiXe[i] != 0)
		{
			tenTamThoi = "";
			int j = i;
			while (j < hoTenTaiXe.size())
			{
				if (hoTenTaiXe[j] == ' ')
				{
					break;
				}
				else
				{
					tenTamThoi = tenTamThoi + hoTenTaiXe[j];
					j++;
				}
			}
			chuoiTen.push_back(tenTamThoi);
			i = j;
		}
	}
	for (int i = 0; i < chuoiTen.size(); i++)
	{
		ten = ten + " " + chuanHoaTen2(chuoiTen[i]);
	}
	ten.erase(ten.begin() + 0);
	hoTenTaiXe = ten;
}
void nhapCung(vector<ChuyenXe*>& danhSachXeNC)
{
	/*	danhSachXeNC.push_back(new NoiThanh("2005A", "Tang Thi Thu Hien", "A2-777", 500000, 10, 30));
		danhSachXeNC.push_back(new NoiThanh("2005A", "Dinh Quoc Dat", "A2-777", 500000, 12, 32));
		danhSachXeNC.push_back(new NoiThanh("2005A", "Tang Thi Thu Hien", "A2-777", 500000, 14, 36));
		danhSachXeNC.push_back(new NgoaiThanh("2904T", "Tang Thi Thu Hien", "A2-089", 200000, "Thai Lan", 2));
		danhSachXeNC.push_back(new NgoaiThanh("2904T", "Dinh QUoc Dat", "A2-089", 200000, "China", 2));
		danhSachXeNC.push_back(new NgoaiThanh("2904T", "Vo Cao Tan Ngoc", "A2-089", 200000, "France", 2));*/
}
void nhapdanhSachChuyenXe(vector<ChuyenXe*>& danhSachXe)
{
	int xeNgoaiThanh, xeNoiThanh, doanhThu;
	string hoTenTaiXe, soXe, maChuyenXe;
	int soTuyen;// noi thanh
	int soKmDiDuoc;// noi thanh
	string noiDen;// ngoai thanh
	int soNgayDi;// ngoai thanh

	cout << "Nhap so chuyen xe noi thanh: ";
	cin >> xeNoiThanh;
	cout << "Nhap so chuyen xe ngoai thanh: ";
	cin >> xeNgoaiThanh;
	cout << "* Chuyen xe noi thanh *" << endl;
	for (int i = 0; i < xeNoiThanh; i++)
	{
		cout << "_______________________" << endl;
		cin.ignore();
		cout << "Ma so chuyen xe: ";
		getline(cin, maChuyenXe);
		cout << "Ho ten tai xe: ";
		getline(cin, hoTenTaiXe);
		chuanHoaTen1(hoTenTaiXe);
		cout << "So xe: ";
		getline(cin, soXe);
		cout << "So tuyen: ";
		cin >> soTuyen;
		cout << "So km di duoc: ";
		cin >> soKmDiDuoc;
		cout << "Doanh thu: ";
		cin >> doanhThu;
		danhSachXe.push_back(new NoiThanh(maChuyenXe, hoTenTaiXe, soXe, doanhThu, soTuyen, soKmDiDuoc));
	}
	cout << endl;
	cout << "* Chuyen xe ngoai thanh *" << endl;
	for (int i = 0; i < xeNoiThanh; i++)
	{
		cout << "_______________________" << endl;
		cin.ignore();
		cout << "Ma so chuyen xe: ";
		getline(cin, maChuyenXe);
		cout << "Ho ten tai xe: ";
		getline(cin, hoTenTaiXe);
		chuanHoaTen1(hoTenTaiXe);
		cout << "So xe: ";
		getline(cin, soXe);
		cout << "Noi den: ";
		getline(cin, noiDen);
		cout << "So ngay di duoc: ";
		cin >> soNgayDi;
		cout << "Doanh thu: ";
		cin >> doanhThu;
		danhSachXe.push_back(new NgoaiThanh(maChuyenXe, hoTenTaiXe, soXe, doanhThu, noiDen, soNgayDi));
	}
}
int  sumNoiThanh(vector<ChuyenXe*> danhSachXe)
{
	int sum = 0;
	for (int i = 0; i < danhSachXe.size(); i++)
	{
		if (danhSachXe[i]->isChuyenXeGi())
		{
			sum = sum + danhSachXe[i]->getDoanhThu();
		}
	}
	return sum;
}
int  sumNgoaiThanh(vector<ChuyenXe*> danhSachXe)
{
	int sum = 0;
	for (int i = 0; i < danhSachXe.size(); i++)
	{
		if (!(danhSachXe[i]->isChuyenXeGi()))
		{
			sum = sum + danhSachXe[i]->getDoanhThu();
		}
	}
	return sum;
}
void xuatDanhSachNC(vector<ChuyenXe*> danhSachXeNC)
{
	cout << setfill('=') << setw(31) << left << "=" << "* Chuyen xe noi thanh *" << setw(31) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma xe" << setw(25) << left << "Ho ten tai xe";
	cout << setw(15) << left << "So xe" << setw(10) << right << "So tuyen" << setw(10) << right << "So km";
	cout << setw(15) << right << "Doanh thu" << endl;
	cout << setfill('_') << setw(85) << "_" << endl;
	for (int i = 0; i < danhSachXeNC.size(); i++)
	{
		if (danhSachXeNC[i]->isChuyenXeGi())
		{
			danhSachXeNC[i]->thongTinChuyenXe();
		}
	}
	cout << endl;
	cout << "Tong doanh thu cua chuyen xe noi thanh: " << sumNoiThanh(danhSachXeNC) << endl;
	cout << endl;
	cout << setfill('=') << setw(30) << left << "=" << "* Chuyen xe ngoai thanh *" << setw(30) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma xe" << setw(25) << left << "Ho ten tai xe";
	cout << setw(15) << left << "So xe" << setw(10) << left << "Noi den" << setw(10) << right << "So ngay di";
	cout << setw(15) << right << "Doanh thu" << endl;
	cout << setfill('_') << setw(85) << "_" << endl;
	for (int i = 0; i < danhSachXeNC.size(); i++)
	{
		if (!(danhSachXeNC[i]->isChuyenXeGi()))
		{
			danhSachXeNC[i]->thongTinChuyenXe();
		}
	}
	cout << endl;
	cout << "Tong doanh thu cua chuyen xe ngoai thanh: " << sumNgoaiThanh(danhSachXeNC) << endl;
	cout << "\n\n\n";
	cout << "\t\t\t\t Tong danh thu cua Noi Thanh va Ngoai Thanh: " << sumNoiThanh(danhSachXeNC) + sumNgoaiThanh(danhSachXeNC) << endl;
}
void xuatDanhSach(vector<ChuyenXe*> danhSachXe)
{
	cout << setfill('=') << setw(31) << left << "=" << "* Chuyen xe noi thanh *" << setw(31) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma xe" << setw(25) << left << "Ho ten tai xe";
	cout << setw(15) << left << "So xe" << setw(10) << right << "So tuyen" << setw(10) << right << "So km";
	cout << setw(15) << right << "Doanh thu" << endl;
	cout << setfill('_') << setw(85) << "_" << endl;
	for (int i = 0; i < danhSachXe.size(); i++)
	{
		if (danhSachXe[i]->isChuyenXeGi())
		{
			danhSachXe[i]->thongTinChuyenXe();
		}
	}
	cout << endl;
	cout << "Tong doanh thu cua chuyen xe noi thanh: " << sumNoiThanh(danhSachXe) << endl;
	cout << endl;
	cout << setfill('=') << setw(30) << left << "=" << "* Chuyen xe ngoai thanh *" << setw(30) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma xe" << setw(25) << left << "Ho ten tai xe";
	cout << setw(15) << left << "So xe" << setw(10) << left << "Noi den" << setw(10) << right << "So ngay di";
	cout << setw(15) << right << "Doanh thu" << endl;
	cout << setfill('_') << setw(85) << "_" << endl;
	for (int i = 0; i < danhSachXe.size(); i++)
	{
		if (!(danhSachXe[i]->isChuyenXeGi()))
		{
			danhSachXe[i]->thongTinChuyenXe();
		}
	}
	cout << endl;
	cout << "Tong doanh thu cua chuyen xe ngoai thanh: " << sumNgoaiThanh(danhSachXe) << endl;
	cout << "\n\n\n";
	cout << "\t\t\t\t Tong danh thu cua Noi Thanh va Ngoai Thanh: " << sumNoiThanh(danhSachXe) + sumNgoaiThanh(danhSachXe) << endl;
}
void menu()
{
	cout << "=========================* Menu *=======================" << endl;
	cout << "1. Xuat danh sach xe nhap cung                                           *\n";
	cout << "2. Nhap mem                                            *\n";
	cout << "3. Xuat danh sach xe nhap mem                            *\n";
	cout << "0. Thoat                                               *\n";
	cout << "=========================================================" << endl;
}
int main()
{
	vector<ChuyenXe*> danhSachXe;
	vector<ChuyenXe*>danhSachXeNC;
	danhSachXeNC.push_back(new NoiThanh("2005A", "Tang Thi Thu Hien", "A2-777", 500000, 10, 30));
	danhSachXeNC.push_back(new NoiThanh("2005A", "Dinh Quoc Dat", "A2-777", 500000, 12, 32));
	danhSachXeNC.push_back(new NoiThanh("2005A", "Tang Thi Thu Hien", "A2-777", 500000, 14, 36));
	danhSachXeNC.push_back(new NgoaiThanh("2904T", "Tang Thi Thu Hien", "A2-089", 200000, "Thai Lan", 2));
	danhSachXeNC.push_back(new NgoaiThanh("2904T", "Dinh QUoc Dat", "A2-089", 200000, "China", 2));
	danhSachXeNC.push_back(new NgoaiThanh("2904T", "Vo Cao Tan Ngoc", "A2-089", 200000, "France", 2));

	int luaChon;
	do
	{
		system("cls");
		menu();

		int chon;
		cout << "Nhap lua chon: ";
		cin >> chon;
		switch (chon)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			//				nhapCung(danhSachXeNC);
			xuatDanhSachNC(danhSachXeNC);
			break;
		}
		case 2:
		{
			nhapdanhSachChuyenXe(danhSachXe);
			break;
		}
		case 3:
		{
			xuatDanhSach(danhSachXe);
			break;
		}

		default:
		{
			luaChon = 0;
		}
		}
		cout << "----------------------" << endl;
		cout << "1. Tiep tuc    0.Thoat" << endl;
		cout << "Chon:";
		do
		{
			cin >> luaChon;
			if (luaChon != 1 && luaChon != 0)
				cout << "Khong hop le, moi chon lai" << endl;
		} while (luaChon != 1 && luaChon != 0);
	} while (luaChon == 1);


}
