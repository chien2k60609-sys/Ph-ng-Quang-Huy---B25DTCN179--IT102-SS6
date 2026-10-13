#include <stdio.h>
#include <string.h>

int main() {
    char maPhieu[50][20] = {"PM101", "PM102", "PM103"};
    int ngayQuaHan[50] = {0, 3, 5};
    int soLuong = 3;

    int chon = -1;

    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");

        if (scanf("%d", &chon) != 1) {
            printf("Loi: Vui long nhap so nguyen hop le!\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (chon) {
            case 1: {
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("%-5s | %-12s | %-18s | %-15s\n", "STT", "Ma Phieu", "So Ngay Qua Han", "Tien Phat (VND)");
                printf("------------------------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    int tienPhat = ngayQuaHan[i] * 5000;
                    printf("%-5d | %-12s | %-2d ngay            | %-d VND\n", 
                           i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
                }
                printf("------------------------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);
                break;
            }

            case 2: {
                if (soLuong >= 50) {
                    printf("\nLoi: Danh sach phieu muon da day, khong the them!\n");
                    break;
                }

                printf("\nNhap ma phieu muon moi: ");
                scanf("%19s", maPhieu[soLuong]);
                while (getchar() != '\n');

                ngayQuaHan[soLuong] = 0;
                soLuong++;

                printf("Them moi phieu muon thanh cong!\n");
                break;
            }

            case 3: {
                char maTim[20];
                printf("\nNhap ma phieu muon can cap nhat: ");
                scanf("%19s", maTim);
                while (getchar() != '\n');

                int index = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTim) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Loi: Khong tim thay ma phieu muon '%s' trong he thong!\n", maTim);
                } else {
                    printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", maTim, index);
                    int ngayMoi;
                    do {
                        printf("Nhap so ngay qua han moi (>= 0): ");
                        if (scanf("%d", &ngayMoi) != 1) {
                            printf("Loi: Vui long nhap so nguyen!\n");
                            while (getchar() != '\n');
                            ngayMoi = -1;
                            continue;
                        }
                        while (getchar() != '\n');

                        if (ngayMoi < 0) {
                            printf("So ngay qua han khong duoc la so am. Vui long nhap lai!\n");
                        }
                    } while (ngayMoi < 0);

                    ngayQuaHan[index] = ngayMoi;
                    printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n", maTim, ngayMoi);
                }
                break;
            }

            case 0:
                printf("\nCam on ban da su dung HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS)!\n");
                break;

            default:
                printf("\nLoi: Chuc nang chon khong hop le! Vui long chon tu 0 den 3.\n");
                break;
        }

    } while (chon != 0);

    return 0;
}

