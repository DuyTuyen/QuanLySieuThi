#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SieuThi {		// Khai báo struct siêu thị
	char maST[50];
	char tenST[100];
	int namThanhLap;
	int doanhSoCoBan;
	int soLuongNhanVien;
	SieuThi* next;
};
struct danhSachST {			// Khai báo danh sách siêu thị 
	SieuThi* danhSachST;
	int soLuong;
};
void init(danhSachST& list) {		// Hàm khởi tạo init
	list.danhSachST = NULL;
	list.soLuong = 0;
}
void kiemTraSieuThiTonTai(danhSachST& list, char n[]) {
	SieuThi* p = list.danhSachST;

	if (p != NULL) {
		while (p != NULL) {
			if (strcmp(n, p->maST) == 0) {		// Dung ham strcmp de so sanh 2 ma voi nhau
				cout << "Ma sieu thi ton tai! " << endl;
				return;
			}
			p = p->next;
		};
	}
	cout << "Ma khong ton tai! ";		
}