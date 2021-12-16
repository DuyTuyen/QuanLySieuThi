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
// Hàm nhập danh sách n siêu thị với đầy đủ thông tin
void ghiNode(fstream& f, danhSachST list)
{
	string duoi[10];		// Khai báo biến kiểu string để lưu giá trị
	string giua[10];
	string tren[10];
	int duoiIndex = 0, giuaIndex = 0, trenIndex = 0;

	SieuThi* p = list.danhSachST;
	if (p != NULL) {
		while (p != NULL)
		{
			if (p->soLuongNhanVien < 100) {
				duoi[duoiIndex++] = p->tenST;
			}
			else if (p->soLuongNhanVien >= 100 && p->soLuongNhanVien <= 200) {
				giua[giuaIndex++] = p->tenST;
			}
			else {
				tren[trenIndex++] = p->tenST;
			}
			p = p->next;
		}
	}
	f << "So luong sieu thi duoi 100 la : " << duoiIndex << endl;
	for (int i = 0; i < duoiIndex; ++i)
		f << "\tsieu thi: " << duoi[i] << endl;
	f << "So luong sieu thi tu 100 den 200 la : " << giuaIndex << endl;
	for (int i = 0; i < giuaIndex; ++i)
		f << "\tsieu thi: " << giua[i] << endl;
	f << "So luong sieu thi tren 200 la : " << trenIndex << endl;
	for (int i = 0; i < trenIndex; ++i)
		f << "\tsieu thi: " << tren[i] << endl;
}
void ghifile(string filename, danhSachST list)
{
	fstream f;

	f.open(filename, ios::out);			// Mở file để ghi
	if (f.is_open()) {
		cout << "Da ghi duoc : \n";
		ghiNode(f, list);
	}
	else
		cout << "Khong mo duoc file";
	f.close();
}
void docfile(string filename)
{
	fstream f;		// Tạo đường dẫn đến file.txt
	f.open(filename, ios::in);// Mở file  để đọc
	string line;		// Để hứng từng dòng
	cin.ignore(1);	// Xóa kí tự enter
	int index = 0;
	if (f.is_open()) {// Mở file ra
		while (!f.eof())
		{
			getline(f, line);
			cout << line << endl;
		}
		f.close();
	}
	else		// Không mở được thì chạy xuống đây
		cout << "Khong mo duoc file";
}

void tinhDoanhThuTuNamThanhLap(danhSachST list) {

	SieuThi* p = list.danhSachST;
	int doanhSo = 0;
	if (p != NULL) {
		while (p != NULL)
		{
			doanhSo = p->doanhSoCoBan * (2021 - p->namThanhLap);  // Thuật toán tính doanh thu
			cout << "Doanh so cua sieu thi la: " << doanhSo << endl;
			}
	}
}
void lietKeCacSieuThiLonHonSoLoiNhuanDaNhap(danhSachST list) {
	int soLoiNhuan = 0;

	cout << "Nhap 1 so loi nhuan:";		// Cho người dùng nhập vào 1 số lợi nhuận
	cin >> soLoiNhuan;
	SieuThi* p = list.danhSachST;
	if (p != NULL) {
		while (p != NULL)
		{
			if (soLoiNhuan < tinhLoiNhuan1Nam(p)) {			// Điều kiện nếu lợi nhuận 1 năm lớn hơn thì liệt kê tên siêu thị
				cout << "Cac sieu thi co loi nhuan lon hon la: " << p->tenST;
			}
			p = p->next;
		}
	}
}
int tinhLoiNhuan1Nam(SieuThi* sieuthi) {
	int luongcb = 0;
	int loiNhuan = 0;
	cout << "Nhap luong co ban cua nhan vien: ";
	cin >> luongcb;
	loiNhuan = sieuthi->doanhSoCoBan - (luongcb * sieuthi->namThanhLap);		// Thuật toán tính lợi nhuận 
	cout << "Loi nhuan trong 1 nam la: " << loiNhuan<< endl;
	return loiNhuan;
	}
SieuThi* timNamThanhLapNhoNhat(SieuThi* list) {
	SieuThi* p = list->next;
	SieuThi* min = list;
	while (p != NULL) {			// Duyệt danh sách
		if (min->namThanhLap > p->namThanhLap)
			min = p;
		p = p->next;
	}
	return min;
}

void swap(SieuThi* st1, SieuThi* st2) {			// Hàm swap dùng để hoán đổi
	// shadow = st1
	SieuThi* shadow = new SieuThi();			// Tạo ra 1 con trỏ shadow như 1 biến tạm
	strncpy_s(shadow->maST, st1->maST, 50); 
	shadow->doanhSoCoBan = st1->doanhSoCoBan;
	shadow->namThanhLap = st1->namThanhLap;
	shadow->soLuongNhanVien = st1->soLuongNhanVien;
	strncpy_s(shadow->tenST, st1->tenST, 50);

	// st1 = st2
	strncpy_s(st1->maST, st2->maST, 50);
	st1->doanhSoCoBan = st2->doanhSoCoBan;
	st1->namThanhLap = st2->namThanhLap;
	st1->soLuongNhanVien = st2->soLuongNhanVien;
	strncpy_s(st1->tenST, st2->tenST, 50);

	//st2 = shadow
	strncpy_s(st2->maST, shadow->maST, 50);
	st2->doanhSoCoBan = shadow->doanhSoCoBan;
	st2->namThanhLap = shadow->namThanhLap;
	st2->soLuongNhanVien = shadow->soLuongNhanVien;
	strncpy_s(st2->tenST, shadow->tenST, 50);

}
void sapXepTangDanTheoNamThanhLap(danhSachST& list) {
	SieuThi* p = list.danhSachST;
	SieuThi* min = NULL;
	if (p != NULL) {
		try {
			while (p != NULL) {
				min = timNamThanhLapNhoNhat(p);
				if (min != p) {
					swap(p, min);
				}
				p = p->next;
			}
		}
		catch (int i) {
			cout << i;
		}

	}
}
void showMenu()
{
	cout << "-------------------------------------------------------------------" << endl;
	cout << " \t1:Nhap danh sach sieu thi" << endl;
	cout << " \t2:Xuat danh sach sieu thi" << endl;
	cout << " \t3:Kiem tra 1 ma sieu thi co ton tai khong" << endl;
	cout << " \t4:In thonng tin sieu thi co doanh thu lon nhat va nho nhat" << endl;
	cout << " \t5:In thonng tin sieu thi co so luong nhan vien thu lon nhat va nho nhat" << endl;
	cout << " \t6:Thong ke cac sieu thi co so luong nhan vien: duoi 100 , tu 100 den 200, tren 200" << endl;
	cout << " \t7:Xuat doanh so cua sieu thi tu nam thanh lap toi nay" << endl;
	cout << " \t8:Nhap luong co ban va tinh loi nhuan sieu thi trong 1 nam" << endl;
	cout << " \t9:Nhap vao 1 so loi nhuan va liet ke cac sieu thi so loi nhuan lon hon" << endl;
	cout << " \t10:Sap xep danh sach tang dan theo nam thanh lap" << endl;
	cout << "-------------------------------------------------------------------" << endl;
}
int main() {
	int luaChon = -1;
	danhSachST list;
	init(list);
	char n[50];
	do
	{
		showMenu();
		cout << "\n Nhap lua chon (nhap 0 de thoat) :";
		cin >> luaChon;
		switch (luaChon)
		{
		case 1:
			cin.ignore();
			nhap(list);
			break;
		case 2:
			xuat(list);
			break;
		case 3:
			cout << "Nhap ma sieu thi can tim: ";
			cin >> n;
			kiemTraSieuThiTonTai(list, n);
			break;
		case 4:
			inMaxMinDoanhSo(list);
			break;
		case 5:
			inMaxMinNhanVien(list);
			break;
		case 6:
			ghifile("sieuthi.txt", list);
			docfile("sieuthi.txt");
			break;
		case 7:
			tinhDoanhThuTuNamThanhLap(list);
			break;
		case 8:
			tinhLoiNhuan1Nam(list.danhSachST);
			break;
		case 9:
			lietKeCacSieuThiLonHonSoLoiNhuanDaNhap(list);
			break;
		case 10:
			sapXepTangDanTheoNamThanhLap(list);
			xuat(list);
			break;
		default:
			break;
		}
	} while (luaChon > 0 && luaChon < 11);
}