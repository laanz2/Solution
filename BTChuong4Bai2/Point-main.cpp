#include <iostream>
#include <algorithm>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>
#include "Point.h"
using namespace std;


Point objects() {
	float x_a, y_a;
	cout << "Nhap hoanh do va tung do cua diem:\n";
	cout << "\t- Hoanh do: ";
	cin >> x_a;
	cout << "\t- Tung do: ";
	cin >> y_a;
	Point p(x_a, y_a);
	return p;
}

void readFile(ifstream& f, vector<Point>& list, Point& p) {
	int numPoints;
	f >> numPoints;
	cout << "\nSo diem co trong tep la: " << numPoints;
	for (int i = 0; i < numPoints; ++i) {
		f >> p;
		list.push_back(p);
	}
}

void input(vector<Point>& list, int i) {
	if (i == 1) {
		list.clear();
		int point;
		cout << "Nhap so diem: ";
		cin >> point;
		for (int j = 1; j <= point; j++) {
			cout << "\n" << j << ". ";
			list.push_back(objects());
		}
	}
	else if (i == 2) {
		string fileName;
		cout << "Nhap ten file muon lay (bao gom ca file type): ";
		cin.ignore();
		getline(cin, fileName);
		ifstream myFile(fileName.c_str());
		if (!myFile) {
			cout << "\nKhong the mo file de doc.\n";
		}
		else {
			list.clear();
			Point p(0, 0);
			readFile(myFile, list, p);
			cout << "\n\nDa lay du lieu thanh cong!!!\n";
		}
	}
}

void insert(vector<Point>& list) {
	int insert;
	cout << "Nhap so diem muon them: ";
	cin >> insert;
	for (int i = 1; i <= insert; i++) {
		cout << "\n" << i << ". ";
		list.push_back(objects());
	}
}

void sort_Output(vector<Point>& list, int i) {
	if (i == 4) {
		cout << "Cac diem da co:\n\n";
		for (Point& p : list) {
			cout << p << "     ";
		}
	}
	else if (i == 5 || i == 6) {
		sort(list.begin(), list.end());
		if (i == 5) {
			cout << "Cac diem duoc sap xep tang dan theo khoang cach den goc toa do:\n\n";
			for (vector<Point>::iterator it = list.begin(); it != list.end(); ++it) {
				cout << *it << "     ";
			}
		}
		else if (i == 6) {
			cout << "Cac diem duoc sap xep giam dan theo khoang cach den goc toa do:\n\n";
			for (vector<Point>::reverse_iterator it = list.rbegin(); it != list.rend(); ++it) {
				cout << *it << "     ";
			}
		}
	}
}

int menu() {
	int choice;
	cout << "Chuc nang he thong ho tro:\n";
	cout << "\t1. Tao moi du lieu tu ban phim\n";
	cout << "\t2. Tao moi du lieu tu file\n";
	cout << "\t3. Them diem moi\n";
	cout << "\t4. In ra man hinh cac diem da co\n";
	cout << "\t5. In ra man hinh cac diem duoc sap xep tang dan theo khoang cach den goc toa do\n";
	cout << "\t6. In ra man hinh cac diem duoc sap xep giam dan theo khoang cach den goc toa do\n";
	cout << "\t0. Thoat chuong trinh\n";
	cout << "\nNhap lua chon cua ban: ";
	cin >> choice;
	return choice;
}

int main() {
	cout << "054205001985 - Do Ngoc Lan\n\n\n";
	vector<Point> pointList;
	int choice;
	do {
		choice = menu();
		switch (choice) {
		case 1:
			system("cls");
			input(pointList, 1);
			cout << "\n\n"; system("pause");
			break;
		case 2:
			system("cls");
			input(pointList, 2);
			cout << "\n\n"; system("pause");
			break;
		case 3:
			system("cls");
			insert(pointList);
			cout << "\n\n"; system("pause");
			break;
		case 4:
			system("cls");
			sort_Output(pointList, 4);
			cout << "\n\n"; system("pause");
			break;
		case 5:
			system("cls");
			sort_Output(pointList, 5);
			cout << "\n\n"; system("pause");
			break;
		case 6:
			system("cls");
			sort_Output(pointList, 6);
			cout << "\n\n"; system("pause");
			break;
		case 0:
			break;
		default:
			system("cls");
			cout << "!!!Lua chon khong hop le. Moi chon lai.\n\n";
			cout << "\n\n"; system("pause");
			break;
		}
		system("cls");
	} while (choice != 0);
}