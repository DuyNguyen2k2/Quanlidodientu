//#include"Quanlinhanvien.h"
#include"Quanlisanpham.h"
void menu(){
	while(true){
		system("cls");
		printf("======== Chao mung den he thong quan li do dien tu ========");
		printf("\nVui long chon chuc vu: ");
		printf("\n\t0.Thoat");
		printf("\n\t1.Nhan vien.");
		printf("\n\t2.Quan li.");
		int luaChon;
		printf("\nMoi nhap lua chon: ");
		scanf("%d", &luaChon);
		if(luaChon == 0){
			break;
		}/*else if(luaChon == 2){
			int mk;
		//	system("cls");
			printf("Vui long nhap mat khau: ");
			scanf("%d",&mk);
			if(mk==44888888){
				while(true){
					printf("\t0. Thoat.");
					printf("\n\t1. Quan li san pham.");
					printf("\n\t2. Quan li nhan vien.");
					int lc;
					printf("\nMoi nhap lua chon: ");
					scanf("%d", &lc);
					if(lc==1){
						system("cls");
						menuSP();
					}else if (lc==2){
						system("cls");
						menuNV();
					}else if(lc==0){
						break;
					}else{
						printf("Lua chon khong hop le. Hay nhap lai.\n");
					}
				}
			}else{
				printf("Sai mat khau.\n");
				system("pause");
			}
		}else if(luaChon == 1){
			int mk;
			printf("Vui long nhap mat khau: ");
			scanf("%d",&mk);
			if(mk==2444){
				system("cls");
				menuSP();
			}else{
				printf("Sai mat khau!!!\n");
				system("pause");
			}
		}
	}
}
int main(){
	menu();
}
