#include <stdio.h>
int isPrime(int n) {
    if (n <= 1) return 0;  
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;  
    }
    return 1;  
}


void nhapMang(int* mang, int* soPhanTu) {
    printf("Nhap vao so phan tu: ");
    scanf("%d", soPhanTu);
    for (int i = 0; i < *soPhanTu; i++) {
        printf("Nhap vao phan tu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}

void inSoChan(int* mang, int soPhanTu) {
    printf("Cac phan tu chan trong mang: ");
    for (int i = 0; i < soPhanTu; i++) {
        if (mang[i] % 2 == 0) {
            printf("%d ", mang[i]);
        }
    }
    printf("\n");
}

void inSoNguyenTo(int* mang, int soPhanTu) {
    printf("Cac phan tu nguyen to trong mang: ");
    for (int i = 0; i < soPhanTu; i++) {
        if (isPrime(mang[i])) {
            printf("%d ", mang[i]);
        }
    }
    printf("\n");
}

void daoNguocMang(int* mang, int soPhanTu) {
    int tam;
    for (int i = 0; i < soPhanTu / 2; i++) {
        tam = mang[i];
        mang[i] = mang[soPhanTu - 1 - i];
        mang[soPhanTu - 1 - i] = tam;
    }
    printf("Mang sau khi dao nguoc: ");
    for (int i = 0; i < soPhanTu; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}

void sapXepTangDan(int* mang, int soPhanTu) {
    int tam;
    for (int i = 0; i < soPhanTu - 1; i++) {
        for (int j = i + 1; j < soPhanTu; j++) {
            if (mang[i] > mang[j]) {
                tam = mang[i];
                mang[i] = mang[j];
                mang[j] = tam;
            }
        }
    }
    printf("Mang sau khi sap xep tang dan: ");
    for (int i = 0; i < soPhanTu; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}

void sapXepGiamDan(int* mang, int soPhanTu) {
    int tam;
    for (int i = 0; i < soPhanTu - 1; i++) {
        for (int j = i + 1; j < soPhanTu; j++) {
            if (mang[i] < mang[j]) {
                tam = mang[i];
                mang[i] = mang[j];
                mang[j] = tam;
            }
        }
    }
    printf("Mang sau khi sap xep giam dan: ");
    for (int i = 0; i < soPhanTu; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}

void timKiemPhanTu(int* mang, int soPhanTu) {
    int x, timThay = 0;
    printf("Nhap vao phan tu can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < soPhanTu; i++) {
        if (mang[i] == x) {
            printf("Phan tu %d duoc tim thay tai vi tri %d.\n", x, i);
            timThay = 1;
            break;
        }
    }
    if (!timThay) {
        printf("Phan tu %d khong co trong mang.\n", x);
    }
}

int main() {
    int mang[1000], soPhanTu, luaChon, luaChonSapXep;
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   a. Tang dan\n");
        printf("   b. Giam dan\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                nhapMang(mang, &soPhanTu);
                break;
            case 2:
                inSoChan(mang, soPhanTu);
                break;
            case 3:
                inSoNguyenTo(mang, soPhanTu);
                break;
            case 4:
                daoNguocMang(mang, soPhanTu);
                break;
            case 5:
                printf("Lua chon phuong thuc sap xep:\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &luaChonSapXep);
                if (luaChonSapXep == 1) {
                    sapXepTangDan(mang, soPhanTu);
                } else if (luaChonSapXep == 2) {
                    sapXepGiamDan(mang, soPhanTu);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 6:
                timKiemPhanTu(mang, soPhanTu);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 7);

    return 0;
}

