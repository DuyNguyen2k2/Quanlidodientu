#include<bits/stdc++.h>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include <string.h>
using namespace std;
struct SanPham{
	char ma_sp[8];
	char ten_sp[50];
	char don_vi_tinh[10];
	int sl;
};
//ham random ma san pham 8 ki tu
void rdMaSp(char ma[8]){
	ma[0] = 'S';
	ma[1]= 'P';
    time_t t;
// reset moi lan random
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
//ham nhap san pham
struct SanPham nhapSP() {
	struct SanPham sp;
	rdMaSp(sp.ma_sp);
	printf("Ten San Pham: ");
	fflush(stdin);
	gets(sp.ten_sp);
	printf("Don vi tinh: ");
	gets(sp.don_vi_tinh);
	printf("So luong: ");
	scanf("%d", &sp.sl);
	return sp;
}
void hienThiTenCotSP() {
	printf("=================================================================\n");
	printf("%-10s %-30s %-20s %-10s\n", 
		"Ma SP", "Ten San Pham", "Don vi tinh", "So Luong"
		);
}
//hien thi thong tin 1 san pham
void hienThiTTSP(struct SanPham sp){
	printf("%-10s ", sp.ma_sp);
	printf("%-30s ", sp.ten_sp);
	printf("%-20s ",sp.don_vi_tinh);
	printf("%-10d\n", sp.sl);
}

//doc file danh sach san pham
void docFileSP(struct SanPham* dssp, int* slsp) {
	FILE* fOut = fopen("sanpham.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct SanPham sp;
			fscanf(fOut, "%10s", &sp.ma_sp);
			char s[100];
			fscanf(fOut, "%s", sp.ten_sp);
			fscanf(fOut, "%s", sp.don_vi_tinh);
			fscanf(fOut, "%10d\n", &sp.sl);
			dssp[i++] = sp;
			if(feof(fOut)) { // thoat chuong trinh
				break;
			}
		}
	}
	
	fclose(fOut);
	*slsp = i;
}
//ghi file dssp
void ghiFileSP(struct SanPham* dssp, int slsp) {
	getchar();
	FILE* fOut = fopen("sanpham.txt", "w");
	int i;
	for(i = 0; i < slsp; i++) {
		struct SanPham sp = dssp[i];
		fprintf(fOut, "%-10s %-30s %-20s %-10d\n",
		sp.ma_sp, sp.ten_sp, sp.don_vi_tinh, sp.sl);
	}
	fclose(fOut);
}
void hienThiDSSP(struct SanPham* dssp, int slsp) {
	hienThiTenCotSP();
	int i;
	for(i = 0; i < slsp; i++) {
		hienThiTTSP(dssp[i]);
	}
	cout << endl;
	printf("=========================================================\n");
}
void sapXep(struct SanPham* dssp, int slsp) {
	int i, j;
	for(i = 0; i < slsp - 1; i++) {
		for(j = slsp - 1; j > i; j --) {
			if(strcmp(dssp[j].ten_sp, dssp[j-1].ten_sp) < 0) {
				struct SanPham sp = dssp[j];
				dssp[j] = dssp[j - 1];
				dssp[j - 1] = sp;
			}
		}
	}
}
// Ham tim theo ten
void tim_Theo_Ten(struct SanPham* dssp, int slsp) {
	char ten[20];
	printf("Nhap ten: ");
	scanf("%s", ten);
	hienThiTenCotSP();
	int i, timSp = 0;
	for(i = 0; i < slsp; i++) {
		if(strcmp(ten, dssp[i].ten_sp) == 0) {
			hienThiTTSP(dssp[i]);
			timSp = 1;
		}
	}
	if(timSp == 0) {
		printf("\nKhong co san pham %s trong danh sach!\n", ten);
	}
}
// Ham tim theo ma sp
void tim_Theo_Ma(struct SanPham* dssp, int slsp) {
	char ma[20];
	printf("Nhap ma: ");
	scanf("%s", ma);
	hienThiTenCotSP();
	int i, timSp = 0;
	for(i = 0; i < slsp; i++) {
		if(strcmp(ma, dssp[i].ma_sp) == 0) {
			hienThiTTSP(dssp[i]);
			timSp = 1;
		}
	}
	if(timSp== 0) {
		printf("\nKhong co san pham co ma %s trong danh sach!\n", ma);
	}
}
// Ham tim kiem
int searchSp(struct SanPham* dssp, char* ma_Search, int slsp){
	for(int i = 0; i < slsp; i++){
		if(strcmp(dssp[i].ma_sp, ma_Search) == 0){
			return i;
		}
	}
	return -1;
}
// Menu tim kiem sp
void menu_TK_SP(struct SanPham* dssp, int slsp){
	while(true){
		printf("\n\t0. Thoat.");
		printf("\n\t1. Tim kiem theo ma san pham.");
		printf("\n\t2. Tim kiem theo ten san pham.");
		int luaChon;
		printf("\nMoi nhap lua chon: ");
		scanf("%d", &luaChon);
		if(luaChon == 1){
			tim_Theo_Ma(dssp, slsp);
			printf("-----------------------------------------------------"
			"----------------------------------------------------------------\n");
			break;
		}else if(luaChon == 2){
			tim_Theo_Ten(dssp, slsp);
			printf("-----------------------------------------------------"
			"----------------------------------------------------------------\n");
			break;
		}else if(luaChon == 0){
			break;
		}else{
			printf("Lua chon ko hop le. Hay nhap lai.\n");
		}
	}
}
// Cap nhat/sua thong tin sp
void updateSp(struct SanPham* dssp, int slsp){
	char ma[8];
	printf("Nhap ma san pham can sua: ");
	scanf("%s", ma);
	if(searchSp(dssp, ma, slsp) > -1){
		int i = searchSp(dssp, ma, slsp);
		printf("Nhap ten san pham can sua\n");
		printf("Ten san pham truoc do: %s: ", dssp[i].ten_sp);
		getchar();
		scanf("%s",  &dssp[i].ten_sp);
		printf("Don vi tinh truoc do: %s: ", dssp[i].don_vi_tinh);
		scanf("%s", &dssp[i].don_vi_tinh);
		printf("So luong truoc do: %d : ", dssp[i].sl);
		scanf("%d", &dssp[i].sl);
		printf("Danh sach san pham sau khi sua:\n");
		hienThiDSSP(dssp, slsp);
		ghiFileSP(dssp, slsp);
	}else{
		printf("Khong co san pham nao mang ma la %s.\n", ma);
	}
}
// Ham xoa sp
void xoaSP(SanPham* dssp, int &slsp){
	char ma[8];
	printf("Nhap ma san pham can xoa: ");
	scanf("%s", ma);
	if(searchSp(dssp, ma, slsp) > -1){
		int i = searchSp(dssp, ma, slsp);
		for(int pos = i; pos < slsp-1; pos++) {
			SanPham temp = dssp[pos];
			dssp[pos] = dssp[pos+1];
			dssp[pos+1] = temp;
		}
		slsp--;
	//	printf("Danh sach san pham sau khi xoa:\n");
	//	hienThiDSSP(dssp, slsp);
		ghiFileSP(dssp, slsp);
	}else{
		printf("Khong co san pham nao mang ma la %s.\n", ma);
	}
}
// Menu lua chon
void menuSP(){
	struct SanPham dssp[100];
	int slsp = 0;
	while(true) {
		int luaChon;
		system("cls");
		docFileSP(dssp, &slsp);
		printf("DANH SACH CAC SAN PHAM HIEN CO:\n");
		hienThiDSSP(dssp, slsp);
		printf("=============== MENU ===============");
		printf("\n\t1. Them 1 san pham moi vao danh sach.");
		printf("\n\t2. Hien thi danh sach san pham.");
		printf("\n\t3. Sap xep.");
		printf("\n\t4. Xoa san pham.");
		printf("\n\t5. Tim kiem.");
		printf("\n\t6. Sua thong tin san pham.");
		printf("\n\t0. Thoat.");
		printf("\nBan chon: ");
		scanf("%d", &luaChon);
		struct SanPham sp;
		if(luaChon == 0){
			break;
		}else if(luaChon == 1){
			sp = nhapSP();
			dssp[slsp++] = sp;
			ghiFileSP(dssp, slsp);
			printf("Them san pham thanh cong!!\n");
			system("pause");
		}else if(luaChon == 2){
			hienThiDSSP(dssp, slsp);
			system("pause");
		}else if(luaChon == 3){
			sapXep(dssp,slsp);
		//	hienThiDSSP(dssp, slsp);
			ghiFileSP(dssp, slsp);
			printf("Sap xep san pham thanh cong!!\n");
			system("pause");
		}else if(luaChon == 4){
			xoaSP(dssp,slsp);
			ghiFileSP(dssp, slsp);
			printf("Xoa thanh cong!!!\n");
			system("pause");
		}else if(luaChon == 5){
			menu_TK_SP(dssp,slsp);
			system("pause");
		}else if(luaChon == 6){
			updateSp(dssp,slsp);
			ghiFileSP(dssp, slsp);
			printf("Sua thanh cong!!\n");
			system("pause");
		}else{
			printf("Sai chuc nang, vui long chon lai!\n");
			system("pause");
		}
	}
}
