#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][15];
    char tenSach[MAX][50];
    int soNgayMuon[MAX];
    int tienPhat[MAX];
    int soLuong = 0;

    int luaChon = -1;

    do {
        printf("\n================ HET HONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat (Qua han > 14 ngay)\n");
        printf("6. Thoat chuong trinh\n");
        printf("==============================================================================\n");
        printf("Lua chon cua ban: ");

        if (scanf("%d", &luaChon) != 1) {
            printf("Lua chon khong hop le. Vui long thu lai!\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (luaChon) {
            case 1: {
                printf("\n=== THEM LUOT MUON SACH MOI ===\n");
                if (soLuong >= MAX) {
                    printf("He thong day, khong the them phieu muon moi!\n");
                    break;
                }

                char maTemp[15];
                int daTonTai = 0;
                do {
                    daTonTai = 0;
                    printf("Nhap ma phieu muon: ");
                    scanf("%14s", maTemp);
                    while (getchar() != '\n');

                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maTemp) == 0) {
                            daTonTai = 1;
                            break;
                        }
                    }

                    if (daTonTai) {
                        printf("Loi: Ma phieu '%s' da ton tai trong he thong! Vui long nhap lai.\n", maTemp);
                    }
                } while (daTonTai);

                strcpy(maPhieu[soLuong], maTemp);

                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], sizeof(tenSach[soLuong]), stdin);
                size_t len = strlen(tenSach[soLuong]);
                if (len > 0 && tenSach[soLuong][len - 1] == '\n') {
                    tenSach[soLuong][len - 1] = '\0';
                }

                int ngayTemp = 0;
                do {
                    printf("Nhap so ngay muon thuc te (> 0): ");
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
                tienPhat[soLuong] = (soNgayMuon[soLuong] > 14) ? (soNgayMuon[soLuong] - 14) * 5000 : 0;

                printf("\n--> Tien phat tu dong tinh: %d VND\n", tienPhat[soLuong]);
                printf("--> Them luot muon sach thanh cong!\n");

                soLuong++;
                break;
            }

            case 2: {
                printf("\n================================ DANH SACH MUON SACH ================================\n");
                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                    break;
                }

                printf("%-5s | %-12s | %-32s | %-10s | %-15s\n", 
                       "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat (VND)");
                printf("-------------------------------------------------------------------------------------\n");

                long long tongTienPhat = 0;
                for (int i = 0; i < soLuong; i++) {
                    printf("%-5d | %-12s | %-32s | %-10d | %-15d\n", 
                           i + 1, maPhieu[i], tenSach[i], soNgayMuon[i], tienPhat[i]);
                    tongTienPhat += tienPhat[i];
                }
                printf("-------------------------------------------------------------------------------------\n");
                printf("Tong tien phat toan he thong: %lld VND\n", tongTienPhat);
                break;
            }

            case 3: {
                printf("\n=== CAP NHAT SO NGAY MUON ===\n");
                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                    break;
                }

                char maTim[15];
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%14s", maTim);
                while (getchar() != '\n');

                int index = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTim) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maTim);
                } else {
                    printf("Tim thay phieu muon cua sach: %s (So ngay hien tai: %d)\n", 
                           tenSach[index], soNgayMuon[index]);
                    
                    int ngayMoi = 0;
                    do {
                        printf("Nhap so ngay muon thuc te moi (> 0): ");
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

                    soNgayMuon[index] = ngayMoi;
                    tienPhat[index] = (soNgayMuon[index] > 14) ? (soNgayMuon[index] - 14) * 5000 : 0;

                    printf("\n--> Tien phat moi: %d VND\n", tienPhat[index]);
                    printf("--> Cap nhat so ngay muon thanh cong!\n");
                }
                break;
            }

            case 4: {
                printf("\n=== XOA PHIEU MUON ===\n");
                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                    break;
                }

                char maTim[15];
                printf("Nhap ma phieu muon can xoa: ");
                scanf("%14s", maTim);
                while (getchar() != '\n');

                int index = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTim) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maTim);
                } else {
                    for (int i = index; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(tenSach[i], tenSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                        tienPhat[i] = tienPhat[i + 1];
                    }
                    soLuong--;
                    printf("Xoa phieu muon thanh cong!\n");
                }
                break;
            }

            case 5: {
                printf("\n=================== DANH SACH PHIEU MUON BI PHAT (> 14 NGAY) ===================\n");
                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                    break;
                }

                int demPhat = 0;
                printf("%-5s | %-12s | %-32s | %-10s | %-15s\n", 
                       "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat (VND)");
                printf("-------------------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    if (soNgayMuon[i] > 14) {
                        demPhat++;
                        printf("%-5d | %-12s | %-32s | %-10d | %-15d\n", 
                               demPhat, maPhieu[i], tenSach[i], soNgayMuon[i], tienPhat[i]);
                    }
                }

                if (demPhat == 0) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                }
                printf("-------------------------------------------------------------------------------------\n");
                break;
            }

            case 6:
                printf("\nCam on ban da su dung HET HONG QUAN LY MUON TRA SACH (LIBRARY_WMS)!\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                break;
        }

    } while (luaChon != 6);

    return 0;
}

