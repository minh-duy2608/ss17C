#include <stdio.h>
#include <string.h>
void inputString(char* str) {
    printf("Nhap vao chuoi: ");
    fgets(str, 1000, stdin);  
    str[strcspn(str, "\n")] = 0;  
}

void printString(const char* str) {
    printf("Chuoi ban da nhap: %s\n", str);
}

int countLetters(const char* str) {
    int count = 0;
    while (*str) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
            count++;
        }
        str++;
    }
    return count;
}

int countDigits(const char* str) {
    int count = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            count++;
        }
        str++;
    }
    return count;
}

int countSpecialChars(const char* str) {
    int count = 0;
    while (*str) {
        if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || (*str >= '0' && *str <= '9') || (*str == ' '))) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char input[1000];  
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                inputString(input);
                break;
            case 2:
                printString(input);
                break;
            case 3:
                printf("So luong chu cai trong chuoi: %d\n", countLetters(input));
                break;
            case 4:
                printf("So luong chu so trong chuoi: %d\n", countDigits(input));
                break;
            case 5:
                printf("So luong ky tu dac biet trong chuoi: %d\n", countSpecialChars(input));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);

    return 0;
}

