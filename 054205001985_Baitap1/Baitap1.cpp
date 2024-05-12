#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // xuat mssv-hoten
    cout << "054205001985-DoNgocLan" << endl;
    // ten File
    const string filename = "data.txt";

    // mo file de doc
    ifstream file(filename);

    // check neu file mo duoc
    if (!file.is_open()) {
        cout << "File khong mo duoc '" << filename << "'" << endl;
        return 1;
    }

    int line_count = 0;
    string line;

    // Doc tung dong cua file kiem tra xem co may dong
    while (getline(file, line)) {
        line_count++;

        // In ra man hinh cac dong bat dau bang "-"
        if (line.find_first_of('-') == 0) {
            cout << line << endl;
        }
     
    }

    // dong file
    file.close();

    // In ra tong so dong
    cout << "So luong dong trong file: " << line_count << endl;

    return 0;
}
