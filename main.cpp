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