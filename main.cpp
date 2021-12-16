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
void inMaxMinNhanVien(danhSachST list) {
	SieuThi* p = list.danhSachST;
	int max1 = 0, min1 = 9999;
	SieuThi* k = list.danhSachST;
	SieuThi* l = list.danhSachST;
	if (p != NULL) {
		while (p != NULL) {
			if (p->soLuongNhanVien > max1) {			// Thuat toan tim so luong nhan vien max
				max1 = p->soLuongNhanVien;
				k = p;
			}
			if (p->soLuongNhanVien < min1) {			// Thuat toan tim so luong nhan vien min
				min1 = p->soLuongNhanVien;
				l = p;
			}
			p = p->next;
		};
		cout << "Danh sach cac sieu thi co so luong nhan vien lon nhat:";
		cout << "Ma sieu thi: " << k->maST << endl;
		cout << "Ten sieu thi: " << k->tenST << endl;
		cout << "Nam thanh lap: " << k->namThanhLap << endl;
		cout << "Doanh so co ban: " << k->doanhSoCoBan << endl;
		cout << "So luong nhan vien: " << k->soLuongNhanVien << endl;

		cout << "Danh sach cac sieu thi co so luong nhan vien nho nhat:";
		cout << "Ma sieu thi: " << l->maST << endl;
		cout << "Ten sieu thi: " << l->tenST << endl;
		cout << "Nam thanh lap: " << l->namThanhLap << endl;
		cout << "Doanh so co ban: " << l->doanhSoCoBan << endl;
		cout << "So luong nhan vien: " << l->soLuongNhanVien << endl;
	}
}