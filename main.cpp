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
SieuThi* nhapThongTinSieuThi() {		// Hàm nhập thông tin siêu thị
	SieuThi* tam = new SieuThi();
	cout << "Nhap ma sieu thi: ";
	cin.getline(tam->maST, 50);
	cout << "Nhap ten sieu thi: ";
	cin.getline(tam->tenST, 50);
	cout << "Nhap nam thanh lap: ";
	cin >> tam->namThanhLap;
	cout << "Nhap doanh so co ban: ";
	cin >> tam->doanhSoCoBan;
	cout << "Nhap so luong nhan vien: ";
	cin >> tam->soLuongNhanVien;
	cin.ignore();
	tam->next = NULL;
	return tam;
}
void nhap(danhSachST& list) {		
	SieuThi* p = list.danhSachST;		// Gán con trỏ p
	int k = 0;							// Biến k chứa số lượng siêu thị nhập vào
	cout << "Nhap so luong sieu thi trong danh sach:";
	cin >> k;
	cin.ignore();

	if (p != NULL) {
		while (p->next != NULL) {	// Duyệt danh sách
			p = p->next;
		}
	}
	else {
		list.danhSachST = nhapThongTinSieuThi();  // Nếu rỗng thì cho nhập thông tin
		p = list.danhSachST;
	}

	for (int i = 0; i < k - 1; i++) {		// Chạy for để nhập đủ số lượng k đã yêu cầu
		p->next = nhapThongTinSieuThi();
		p = p->next;
	}
}
// Hàm nhập danh sách n siêu thị với đầy đủ thông tin