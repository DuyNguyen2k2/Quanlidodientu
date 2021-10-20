#include <stdio.h>
#include <string.h>
#include<bits/stdc++.h>
#include <stdlib.h>
#include<time.h>
using namespace std;
struct NhanVien;
void hienThiDSNV(struct NhanVien*, int);
void hienThiTenCot();

struct HoTen {
	char ho[20];
	char dem[20];
	char ten[20];
};


struct NhanVien {
	char ma[8];
	struct HoTen hoVaTen;
	int namsinh;
	char gioiTinh[10];
	char Diachi[20];
	char Sodt[12];
//	char chucvu[20];
};


void rdMa(char ma[8]){
	ma[0] = 'N';
	ma[1]= 'V';
    time_t t;
	/* Intializes random number generator */
	srand((unsigned) time(&t));
	for(int i = 2; i < 5; i++){
		int num = rand() % 57;
		//cout << num << endl;
		if(num < 48){
			num += 48- num + (rand() % 10);
			//cout << num;
		}
		ma[i] = char(num);
	}
}

void nhapHoTen(struct HoTen* ten) {
	printf("Ho: ");
	scanf("%s", ten->ho);
	printf("Dem: ");
	getchar();
	gets(ten->dem);
	printf("Ten: ");
	scanf("%s", ten->ten);
}

struct NhanVien nhapNV() {
	struct NhanVien nv;
	rdMa(nv.ma);
	nhapHoTen(&nv.hoVaTen);
	printf("Nam sinh: ");
	scanf("%d", &nv.namsinh);
	printf("Gioi tinh: ");
	scanf("%s", nv.gioiTinh);
	printf("Dia chi: ");
	scanf("%s",nv.Diachi);
	printf("So dien thoai: ");
	scanf("%s",nv.Sodt);
//	printf("Chuc vu: ");
//	scanf("%s", nv.chucvu)
	return nv;
}

void hienThiTTNV(struct NhanVien nv) {
	printf("%-10s %-10s %-10s %-12s %-12d %-12s %-12s %-12s",
	nv.ma, nv.hoVaTen.ho, nv.hoVaTen.dem, nv.hoVaTen.ten, nv.namsinh, nv.gioiTinh,nv.Diachi,nv.Sodt);
	cout << endl;
}

void sapXepTheoTenaz(struct NhanVien* ds, int slnv) {
	int i, j;
	for(i = 0; i < slnv - 1; i++) {
		for(j = slnv - 1; j > i; j --) {
			if(strcmp(ds[j].hoVaTen.ten, ds[j-1].hoVaTen.ten) < 0) {
				struct NhanVien nv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = nv;
			}
		}
	}
}
void sapXepTheoTenza(struct NhanVien* ds, int slnv) {
	int i, j;
	for(i = 0; i < slnv - 1; i++) {
		for(j = slnv - 1; j > i; j --) {
			if(strcmp(ds[j].hoVaTen.ten, ds[j-1].hoVaTen.ten) > 0) {
				struct NhanVien nv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = nv;
			}
		}
	}
}
void sapXepTheoHoaz(struct NhanVien* ds, int slnv) {
	int i, j;
	for(i = 0; i < slnv - 1; i++) {
		for(j = slnv - 1; j > i; j --) {
			if(strcmp(ds[j].hoVaTen.ho, ds[j-1].hoVaTen.ho) < 0) {
				struct NhanVien nv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = nv;
			}
		}
	}
}
void sapXepTheoHoza(struct NhanVien* ds, int slnv) {
	int i, j;
	for(i = 0; i < slnv - 1; i++) {
		for(j = slnv - 1; j > i; j --) {
			if(strcmp(ds[j].hoVaTen.ho, ds[j-1].hoVaTen.ho) > 0) {
				struct NhanVien nv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = nv;
			}
		}
	}
}
void sapXepTheoHoDemaz(struct NhanVien* ds, int slnv) {
	int i, j;
	for(i = 0; i < slnv - 1; i++) {
		for(j = slnv - 1; j > i; j --) {
			if(strcmp(ds[j].hoVaTen.dem, ds[j-1].hoVaTen.dem) < 0) {
				struct NhanVien nv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = nv;
			}
		}
	}
}
void sapXepTheoHoDemza(struct NhanVien* ds, int slnv) {
	int i, j;
	for(i = 0; i < slnv - 1; i++) {
		for(j = slnv - 1; j > i; j --) {
			if(strcmp(ds[j].hoVaTen.dem, ds[j-1].hoVaTen.dem) > 0) {
				struct NhanVien nv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = nv;
			}
		}
	}
}
void sapXepTheoNamSinhTD(struct NhanVien* ds, int slnv) {
	int i, j;
	for(i = 0; i < slnv - 1; i++) {
		for(j = slnv - 1; j > i; j --) {
			if(ds[j].namsinh< ds[i].namsinh) {
				struct NhanVien nv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = nv;
			}
		}
	}
}
void sapXepTheoNamSinhGD(struct NhanVien* ds, int slnv) {
	int i, j;
	for(i = 0; i < slnv - 1; i++) {
		for(j = slnv - 1; j > i; j --) {
			if(ds[j].namsinh> ds[i].namsinh) {
				struct NhanVien nv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = nv;
			}
		}
	}
}
void menuSX(struct NhanVien* dsnv, int slnv){
	while(true){
		printf("\t0. Huy.");
		printf("\n\t1. Sap xem theo ho nhan vien.");
		printf("\n\t2. Sap xem theo ho dem nhan vien.");
		printf("\n\t3. Sap xep theo ten nhan vien.");
		printf("\n\t4. Sap xep theo nam sinh nhan vien.\n");
		int luaChon;
		printf("Moi nhap lua chon: ");
		scanf("%d", &luaChon);
		if(luaChon == 3){
			while(true){
				printf("\t0. Huy");
				printf("\n\t1. Sap xep tu a-z.");
				printf("\n\t2. Sap xep tu z-a.\n");
				int luaChon;
				printf("Moi nhap lua chon: ");
				scanf("%d",&luaChon);
				if(luaChon==1){
					sapXepTheoTenaz(dsnv,slnv);
					printf("Sap xep thanh cong!!\n");
					break;
				}else if(luaChon==2){
					sapXepTheoTenza(dsnv,slnv);
					printf("Sap xep thanh cong!!\n");
					break;
				}else if(luaChon==0){
					break;
				}else{
					printf("Lua chon ko hop le. Hay nhap lai.\n");
				}
			}
			break;
		}else if(luaChon == 4){
			while(true){
				printf("\t0. Huy");
				printf("\n\t1. Sap xep theo nam sinh tang dan.");
				printf("\n\t2. Sap xep theo nam sinh giam dan");
				int luaChon;
				printf("\nMoi nhan lua chon: ");
				scanf("%d",&luaChon);
				if(luaChon==1){
					sapXepTheoNamSinhTD(dsnv,slnv);
					printf("Sap xep thanh cong!!\n");
					break;
				}else if(luaChon==2){
					sapXepTheoNamSinhGD(dsnv,slnv);
					printf("Sap xep thanh cong!!\n");
					break;
				}else if(luaChon==0){
					break;
				}else{
					printf("Lua chon ko hop le. Hay nhap lai.\n");
				}
			}
			break;
		}else if(luaChon==1){
			while(true){
				printf("\t0. Huy");
				printf("\n\t1. Sap xep tu a-z.");
				printf("\n\t2. Sap xep tu z-a.\n");
				int luaChon;
				printf("Moi nhap lua chon: ");
				scanf("%d",&luaChon);
				if(luaChon==1){
					sapXepTheoHoaz(dsnv,slnv);
					printf("Sap xep thanh cong!!\n");
					break;
				}else if(luaChon==2){
					sapXepTheoHoza(dsnv,slnv);
					printf("Sap xep thanh cong!!\n");
					break;
				}else if(luaChon==0){
					break;
				}else{
					printf("Lua chon ko hop le. Hay nhap lai.\n");
				}
			}
			break;
		}else if(luaChon==2){
			while(true){
				printf("\t0. Huy");
				printf("\n\t1. Sap xep tu a-z.");
				printf("\n\t2. Sap xep tu z-a.\n");
				int luaChon;
				printf("Moi nhap lua chon: ");
				scanf("%d",&luaChon);
				if(luaChon==1){
					sapXepTheoHoDemaz(dsnv,slnv);
					printf("Sap xep thanh cong!!\n");
					break;
				}else if(luaChon==2){
					sapXepTheoHoDemza(dsnv,slnv);
					printf("Sap xep thanh cong!!\n");
					break;
				}else if(luaChon==0){
					break;
				}else{
					printf("Lua chon ko hop le. Hay nhap lai.\n");
				}
			}
			break;
		}else if(luaChon == 0){
			break;
		}else{
			printf("Lua chon ko hop le. Hay nhap lai.\n");
		}
	}
}

//====================Tim kiem====================//
void timTheoTen(struct NhanVien* ds, int slnv) {
	char ten[20];
	printf("Nhap ten: ");
	scanf("%s", &ten);
	hienThiTenCot();
	int i, timNV = 0;
	for(i = 0; i < slnv; i++) {
		if(strcmp(ten, ds[i].hoVaTen.ten) == 0) {
			hienThiTTNV(ds[i]);
			timNV = 1;
		}
	}
	if(timNV == 0) {
		printf("\nKhong co nhan vien co ten %s trong danh sach!\n", ten);
	}
}
void timTheoHo(struct NhanVien* ds, int slnv) {
	char Ho[20];
	printf("Nhap Ho: ");
	scanf("%s", &Ho);
	hienThiTenCot();
	int i, timNV = 0;
	for(i = 0; i < slnv; i++) {
		if(strcmp(Ho, ds[i].hoVaTen.ho) == 0) {
			hienThiTTNV(ds[i]);
			timNV = 1;
		}
	}
	if(timNV == 0) {
		printf("\nKhong co nhan vien co ho %s trong danh sach!\n", Ho);
	}
}
void timTheoHoDem(struct NhanVien* ds, int slnv) {
	char Dem[20];
	printf("Nhap Ho dem: ");
	scanf("%s", &Dem);
	hienThiTenCot();
	int i, timnV = 0;
	for(i = 0; i < slnv; i++) {
		if(strcmp(Dem, ds[i].hoVaTen.dem) == 0) {
			hienThiTTNV(ds[i]);
			timnV = 1;
		}
	}
	if(timnV == 0) {
		printf("\nKhong co nhan vien co ho dem %s trong danh sach!\n", Dem);
	}
}
void timTheodc(struct NhanVien* ds, int slnv){
	char dc[20];
	printf("Nhap dia chi: ");
	scanf("%s",&dc);
	hienThiTenCot();
	int i, timNV=0;
	for(int i=0;i<slnv;i++){
		if(strcmp(dc, ds[i].Diachi) == 0){
			hienThiTTNV(ds[i]);
			timNV = 1;
		}
	}
	if(timNV == 0) {
		printf("\nKhong co nhan vien co dia chi %s trong danh sach!\n", dc);
	}
}
void timTheoMa(struct NhanVien* ds, int slnv) {
	char ma[20];
	printf("Nhap ma: ");
	scanf("%s", &ma);
	hienThiTenCot();
	int i, timNV = 0;
	for(i = 0; i < slnv; i++) {
		if(strcmp(ma, ds[i].ma) == 0) {
			hienThiTTNV(ds[i]);
			timNV = 1;
		}
	}
	if(timNV == 0) {
		printf("\nKhong co nhan vien co ma %s trong danh sach!\n", ma);
	}
}
void timTheons(struct NhanVien* ds, int slnv){
	int nam;
	printf("Nhap Nam sinh: ");
	scanf("%d",&nam);
	hienThiTenCot();
	int i, timNV = 0;
	for(i = 0; i < slnv; i++){
		if(ds[i].namsinh==nam){
			hienThiTTNV(ds[i]);
			timNV = 1;
		}
	}
	if(timNV == 0) {
		printf("\nKhong co nhan vien co nam sinh %d trong danh sach!\n", nam);
	}
}
void timTheoGT(struct NhanVien* ds, int slnv){
	char gt[10];
	printf("Nhap Gioi tinh: ");
	scanf("%s",&gt);
	hienThiTenCot();
	int timNV=0;
	for(int i=0;i<slnv;i++){
		if(strcmp(gt, ds[i].gioiTinh) == 0){
			hienThiTTNV(ds[i]);
			timNV = 1;
		}
	}if(timNV == 0) {
		printf("\nKhong co nhan vien co gioi tinh %d trong danh sach!\n", gt);
	}
}
void menuTK(struct NhanVien* dsnv, int slnv){
	while(true){
		printf("\t0. Huy.");
		printf("\n\t1. Tim kiem theo Ma nhan vien.");
		printf("\n\t2. Tim kiem theo Ho ten nhan vien.");
		printf("\n\t3. Tim kiem theo Dia chi nhan vien.");
		printf("\n\t4. Tim kiem theo Nam sinh nhan vien.");
		printf("\n\t5. Tim kiem theo Gioi tinh nhan vien.");
		int luaChon;
		printf("\nMoi nhap lua chon: ");
		scanf("%d", &luaChon);
		if(luaChon == 1){
			timTheoMa(dsnv, slnv);
			printf("-----------------------------------------------------"
			"----------------------------------------------------------------\n");
			break;
		}else if(luaChon == 2){
			while(true){
				printf("\t0. Huy.");
				printf("\n\t1. Tim kiem theo Ho nhan vien.");
				printf("\n\t2. Tim kiem theo Ho dem nhan vien.");
				printf("\n\t3. Tim kiem theo Ten nhan vien.");
				int luaChon;
				printf("\nMoi nhap lua chon: ");
				scanf("%d", &luaChon);
				if(luaChon==1){
					timTheoHo(dsnv, slnv);
					printf("-----------------------------------------------------"
					"----------------------------------------------------------------\n");
					break;	
				}else if(luaChon==2){
					timTheoHoDem(dsnv,slnv);
					printf("-----------------------------------------------------"
					"----------------------------------------------------------------\n");
					break;
				}else if(luaChon==3){
					timTheoTen(dsnv,slnv);
					printf("-----------------------------------------------------"
					"----------------------------------------------------------------\n");
					break;
				}else if(luaChon==0){
					break;
				}else{
					printf("Lua chon ko hop le. Hay nhap lai.\n");
				}
			}
			
			break;
		}else if(luaChon==3){
			timTheodc(dsnv,slnv);
			printf("-----------------------------------------------------"
			"----------------------------------------------------------------\n");
			break;
		}else if(luaChon==4){
			timTheons(dsnv,slnv);
			printf("-----------------------------------------------------"
			"----------------------------------------------------------------\n");
			break;
		}else if(luaChon==5){
			timTheoGT(dsnv,slnv);
			printf("-----------------------------------------------------"
			"----------------------------------------------------------------\n");
			break;
		}
		else if(luaChon == 0){
			break;
		}else{
			printf("Lua chon ko hop le. Hay nhap lai.\n");
		}
	}
}
//====================Tim kiem====================//


void ghiFile(struct NhanVien* ds, int slnv) {
	getchar();
	FILE* fOut = fopen("Nhanvien.txt", "w");
	int i;
	for(i = 0; i < slnv; i++) {
		struct NhanVien nv = ds[i];
		fprintf(fOut, "%-10s %-10s %-10s %-12s %-12d %-12s %-12s %-12s\n",
		nv.ma, nv.hoVaTen.ho, nv.hoVaTen.dem, nv.hoVaTen.ten, nv.namsinh, nv.gioiTinh,nv.Diachi,nv.Sodt);
	}
	fclose(fOut);
}

void docFile(struct NhanVien* ds, int* slnv) {
	FILE* fOut = fopen("nhanvien.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct NhanVien nv;
			fscanf(fOut, "%10s %10s %10[^\n] %12s %12d %12s %12s %12s\n",
			&nv.ma, nv.hoVaTen.ho, nv.hoVaTen.dem, nv.hoVaTen.ten, &nv.namsinh, nv.gioiTinh,nv.Diachi,nv.Sodt);
			ds[i++] = nv;
			if(feof(fOut)) { // thoat chuong trinh
				break;
			}
		}
	}
	
	fclose(fOut);
	*slnv = i;
}

void hienThiTenCot() {
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
	printf("%-10s %-10s %-10s %-12s %-12s %-12s %-12s %-12s\n", 
		"Ma NV", "Ho", "Dem", "Ten", "Nam sinh", "Gioi Tinh","Dia chi","So dien thoai\n"
		);
}

void hienThiDSNV(struct NhanVien* ds, int slnv) {
	hienThiTenCot();
	int i;
	for(i = 0; i < slnv; i++) {
		hienThiTTNV(ds[i]);
	}
	cout << endl;
	printf("\n-----------------------------------------------------"
	"----------------------------------------------------------------\n");
}
int searchNV(struct NhanVien* ds, char* maSearch, int slnv){
	for(int i = 0; i < slnv; i++){
		if(strcmp(ds[i].ma, maSearch) == 0){
			return i;
		}
	}
	return -1;
}
void updateNV(struct NhanVien* ds, int slnv){
	char ma[8];
	printf("Nhap ma nhan vien can sua: ");
	scanf("%s", ma);
	if(searchNV(ds, ma, slnv) > -1){
		hienThiTenCot();
		int i = searchNV(ds, ma, slnv);
		hienThiTTNV(ds[i]);
		while(true){
			printf("\n\t0. Huy");
			printf("\n\t1. Sua ho ten Nhan vien.");
			printf("\n\t2. Sua nam sinh Nhan vien.");
			printf("\n\t3. Sua gioi tinh Nhan vien.");
			printf("\n\t4. Sua dia chi Nhan vien.");
			printf("\n\t5. Sua so dien thoai Nhan vien.");
			int luaChon;
			printf("\nNhap lua chon: ");
			scanf("%d",&luaChon);
			if(luaChon==1){
				while(true){
					printf("\t0. Huy");
					printf("\n\t1. Sua Ho Nhan vien.");
					printf("\n\t2. Sua Ho Dem Nhan vien.");
					printf("\n\t3. Sua Ten Nhan vien.");
					int luaChon;
					printf("Nhap lua chon: ");
					scanf("%d",&luaChon);
					if(luaChon==1){
						printf("Ho truoc do: %s: ", ds[i].hoVaTen.ho);
						getchar();
						scanf("%s",  &ds[i].hoVaTen.ho);
						printf("Sua thanh cong!!\n");
						break;
					}else if(luaChon==2){
						printf("Ten dem truoc do: %s: ", ds[i].hoVaTen.dem);
						getchar();
						scanf("%s", &ds[i].hoVaTen.dem);
						printf("Sua thanh cong!!\n");
						break;
					}else if(luaChon==3){
						printf("Ten truoc do: %s: ", ds[i].hoVaTen.ten);
						getchar();
						scanf("%s",  &ds[i].hoVaTen.ten);
						printf("Sua thanh cong!!\n");
						break;
					}else if(luaChon==0){
						break;
					}else{
						printf("Lua chon khong hop le. Hay nhap lai!!");
					}
				}
				break; 
			}else if(luaChon==2){
				printf("Nam sinh truoc do: %d: ", ds[i].namsinh);
				scanf("%d", &ds[i].namsinh);
				printf("Sua thanh cong!!\n");
				break;
			}else if(luaChon==3){
				printf("Gioi tinh truoc do: %s : ", ds[i].gioiTinh);
				getchar();
				scanf("%s", &ds[i].gioiTinh);
				printf("Sua thanh cong!!\n");
				break;
			}else if(luaChon==4){
				printf("Dia chi truoc do: %s: ",ds[i].Diachi);
				getchar();
				scanf("%s",&ds[i].Diachi);
				printf("Sua thanh cong!!\n");
				break;
			}else if(luaChon==5){
				printf("So dien thoai truoc do: %s: ",ds[i].Sodt);
				getchar();
				scanf("%s",&ds[i].Sodt);
				printf("Sua thanh cong!!\n");
				break;
			}else if(luaChon==0){
				break;
			}else{
				printf("Lua chon khong hop le. Hay nhap lai!!");
			}
		}
	//	printf("Danh sach nhan vien sau khi sua:\n");
		//hienThiDSNV(ds, slnv);
		ghiFile(ds, slnv);
	}else{
		printf("Khong co nhan vien nao mang ma la %s.\n", ma);
	}
}

void xoaNV(NhanVien* dsnv, int slnv){
	char ma[8];
	printf("Nhap ma nhan vien can xoa: ");
	scanf("%s", ma);
	if(searchNV(dsnv, ma, slnv) > -1){
		int i = searchNV(dsnv, ma, slnv);
		for(int pos = i; pos < slnv-1; pos++) {
			NhanVien temp = dsnv[pos];
			dsnv[pos] = dsnv[pos+1];
			dsnv[pos+1] = temp;
		}
		slnv--;
	//	printf("Danh sach nhan vien sau khi xoa:\n");
	//	hienThiDSNV(dsnv, slnv);
		ghiFile(dsnv, slnv);
	}else{
		printf("Khong co nhan vien nao mang ma la %s.\n", ma);
	}
}
void menuNV(){
	struct NhanVien dsnv[100];
	int slnv = 0;
	while(true) {
		int luaChon;
		system("cls");
		docFile(dsnv, &slnv);
		printf("DANH SACH NHAN VIEN HIEN THOI:\n");
		hienThiDSNV(dsnv, slnv);
		printf("=============== MENU ===============");
		printf("\n\t1. Them Nhan vien vao danh sach.");
		printf("\n\t2. Hien thi danh sach Nhan vien.");
		printf("\n\t3. Sap xep.");
		printf("\n\t4. Xoa nhan vien.");
		printf("\n\t5. Tim kiem.");
		printf("\n\t6. Sua thong tin nhan vien.");
		printf("\n\t0. Thoat.");
		printf("\nBan chon: ");
		scanf("%d", &luaChon);
		struct NhanVien nv;
		if(luaChon == 0){
			break;
		}else if(luaChon == 1){
			nv = nhapNV();
			dsnv[slnv++] = nv;
			ghiFile(dsnv, slnv);
			system("pause");
		}else if(luaChon == 2){
			hienThiDSNV(dsnv, slnv);
			system("pause");
		}else if(luaChon == 3){
			menuSX(dsnv, slnv);
			ghiFile(dsnv, slnv);
			system("pause");
		}else if(luaChon == 4){
			xoaNV(dsnv, slnv);
			system("pause");
		}else if(luaChon == 5){
			menuTK(dsnv, slnv);
			system("pause");
		}else if(luaChon == 6){
			updateNV(dsnv, slnv);
			system("pause");	
		}else{
			printf("Sai chuc nang, vui long chon lai!\n");
			system("pause");
		}
	}
}
