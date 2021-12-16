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
void inMaxMinDoanhSo(danhSachST list) {
	SieuThi* p = list.danhSachST;
	int max = 0, min = 9999;		
	SieuThi* q = list.danhSachST;
	SieuThi* w = list.danhSachST;
	if (p != NULL) {
		while (p != NULL) {
			//
			if (p->doanhSoCoBan > max) {			// Thuật toán tìm max doanh số
				max = p->doanhSoCoBan;
				q = p;
			}
			if (p->doanhSoCoBan < min) {			// Thuật toán tìm min doanh số
				min = p->doanhSoCoBan;
				w = p;
			}
			p = p->next;
		};
		cout << "Danh sach cac sieu thi co doanh thu lon nhat:";
		cout << "Ma sieu thi: " << q->maST << endl;
		cout << "Ten sieu thi: " << q->tenST << endl;
		cout << "Nam thanh lap: " << q->namThanhLap << endl;
		cout << "Doanh so co ban: " << q->doanhSoCoBan << endl;
		cout << "So luong nhan vien: " << q->soLuongNhanVien << endl;

		cout << "Danh sach cac sieu thi co doanh thu nho nhat:";
		cout << "Ma sieu thi: " << w->maST << endl;
		cout << "Ten sieu thi: " << w->tenST << endl;
		cout << "Nam thanh lap: " << w->namThanhLap << endl;
		cout << "Doanh so co ban: " << w->doanhSoCoBan << endl;
		cout << "So luong nhan vien: " << w->soLuongNhanVien << endl;
	}
}