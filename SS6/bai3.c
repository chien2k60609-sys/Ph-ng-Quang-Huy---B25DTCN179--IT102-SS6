#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][20];
    char maSach[MAX][20];
    int soNgayMuon[MAX];
    int soLuong = 0;

    int luaChon = -1;

    do {
        printf("\n================ HET HONG QUAN LY MUON TRA SACH (LOGISTICS) ================\n");
        printf("1. Them moi phieu muon sach (Create)\n");
        printf("2. Hien thi danh sach phieu muon & Tien phat qua han (Read)\n");
        printf("3. Cap nhat so ngay muon sach (Update)\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon (Delete)\n");
        printf("5. Thoat chuong trinh\n");
        printf("===========================================================================\n");
        printf("Lua chon cua ban (1-5): ");

        if (scanf("%d", &luaChon) != 1) {
            printf("Lua chon khong hop le, vui long chon lai!\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (luaChon) {
            case 1: {
                printf("\n--- THEM MOI PHIEU MUON ---\n");
                if (soLuong >= MAX) {
                    printf("Bo nho danh sach da day, khong the them moi!\n");
                    break;
                }

                char maPhieuTemp[20];
                int tonTai = 0;

                printf("Nhap ma phieu: ");
                scanf("%19s", maPhieuTemp);
                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maPhieuTemp) == 0) {
                        tonTai = 1;
                        break;
                    }
                }

                if (tonTai) {
                    printf("Loi: Ma phieu da ton tai trong he thong!\n");
                    break;
                }

                strcpy(maPhieu[soLuong], maPhieuTemp);

                printf("Nhap ma sach: ");
                scanf("%19s", maSach[soLuong]);
                while (getchar() != '\n');

                int ngayTemp = 0;
                do {
                    printf("Nhap so ngay muon: ");
                    if (scanf("%d", &ngayTemp) != 1) {
                        printf("Loi: Vui long nhap so nguyen hop le!\n");
                        while (getchar() != '\n');
                        ngayTemp = 0;
                        continue;
                    }
                    while (getchar() != '\n');

                    if (ngayTemp <= 0) {
                        printf("So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                    }
                } while (ngayTemp <= 0);

                soNgayMuon[soLuong] = ngayTemp;
                soLuong++;

                printf("Them moi phieu muon thanh cong!\n");
                break;
            }

            case 2: {
                printf("\n================================ DANH SACH PHIEU MUON ================================\n");
                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                    break;
                }

                printf("%-5s %-12s %-15s %-15s %-20s %-15s\n", 
                       "STT", "MA PHIEU", "MA SACH", "SO NGAY", "TRANG THAI", "TIEN PHAT (VND)");
                printf("-------------------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    int tienPhat = 0;
                    char trangThai[20];

                    if (soNgayMuon[i] > 14) {
                        int ngayQuaHan = soNgayMuon[i] - 14;
                        tienPhat = ngayQuaHan * 5000;
                        strcpy(trangThai, "QUA HAN");
                    } else {
                        tienPhat = 0;
                        strcpy(trangThai, "DUNG HAN");
                    }

                    printf("%-5d %-12s %-15s %-15d %-20s %-15d\n", 
                           i + 1, maPhieu[i], maSach[i], soNgayMuon[i], trangThai, tienPhat);
                }
                printf("======================================================================================\n");
                break;
            }

            case 3: {
                if (soLuong == 0) {
                    printf("\nDanh sach phieu muon hien dang rong!\n");
                    break;
                }

                char maTim[20];
                printf("\nNhap ma phieu can cap nhat: ");
                scanf("%19s", maTim);
                while (getchar() != '\n');

                int pos = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTim) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim th?y ma phieu trong he thong!\n");
                } else {
                    printf("So ngay muon hien tai cua phieu %s la: %d\n", maPhieu[pos], soNgayMuon[pos]);
                    int ngayMoi = 0;
                    do {
                        printf("Nhap so ngay muon moi: ");
                        if (scanf("%d", &ngayMoi) != 1) {
                            printf("Loi: Vui long nhap so nguyen!\n");
                            while (getchar() != '\n');
                            ngayMoi = 0;
                            continue;
                        }
                        while (getchar() != '\n');

                        if (ngayMoi <= 0) {
                            printf("So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                        }
                    } while (ngayMoi <= 0);

                    soNgayMuon[pos] = ngayMoi;
                    printf("Cap nhat so ngay muon thanh cong!\n");
                }
                break;
            }

            case 4: {
                if (soLuong == 0) {
                    printf("\nDanh sach phieu muon hien dang rong!\n");
                    break;
                }

                char maTim[20];
                printf("\nNhap ma phieu xac nhan tra/xoa: ");
                scanf("%19s", maTim);
                while (getchar() != '\n');

                int pos = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTim) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu can xoa!\n");
                } else {
                    for (int i = pos; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(maSach[i], maSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                    }
                    soLuong--;
                    printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");
                }
                break;
            }

            case 5:
                printf("\nCam on ban da su dung HET HONG QUAN LY MUON TRA SACH (LOGISTICS)!\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
                break;
        }

    } while (luaChon != 5);

    return 0;
}

