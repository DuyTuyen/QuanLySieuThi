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
void xuat(danhSachST list) {
	SieuThi* p = list.danhSachST;
	if (p != NULL) {
		while (p != NULL) {
			cout << "Danh sach cac sieu thi:";
			cout << "Ma sieu thi: " << p->maST << endl;
			cout << "Ten sieu thi: " << p->tenST << endl;
			cout << "Nam thanh lap: " << p->namThanhLap << endl;
			cout << "Doanh so co ban: " << p->doanhSoCoBan << endl;
			cout << "So luong nhan vien: " << p->soLuongNhanVien << endl;
			p = p->next;
		};
	}
	else {
		cout << "Danh sach rong !";
	}
	cout << "Ma khong ton tai! ";		
	}
}
// Hàm nhập danh sách n siêu thị với đầy đủ thông tin
