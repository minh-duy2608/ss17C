#include <stdio.h>
#include <string.h>

void inputString(char* str) {
    printf("Nhap vao chuoi: ");
    fgets(str, 1000, stdin);  
    str[strcspn(str, "\n")] = 0;  
}

void printReversedString(const char* str) {
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}

int countWords(const char* str) {
    int count = 0;
    int inWord = 0; 
    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            inWord = 0;  
        } else if (inWord == 0) {
            inWord = 1;  
            count++;
        }
        str++;
    }
    return count;
}

void compareStrings(const char* str1, const char* str2) {
    if (strlen(str1) < strlen(str2)) {
        printf("Chuoi thu 2 ngan hon chuoi ban dau.\n");
    } else if (strlen(str1) > strlen(str2)) {
        printf("Chuoi thu 2 dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void toUpper(char* str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 'a' + 'A';  
        }
        str++;
    }
    printf("Chuoi in hoa: %s\n", str);
}

void addString(char* str1) {
    char str2[1000];
    printf("Nhap vao chuoi de them vao chuoi ban dau: ");
    fgets(str2, 1000, stdin);
    str2[strcspn(str2, "\n")] = 0;  

    strcat(str1, str2);  
    printf("Chuoi sau khi them: %s\n", str1);
}

int main() {
    char str1[100];  
    char str2[100];  
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh do dai chuoi\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                inputString(str1);
                break;
            case 2:
                printReversedString(str1);
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", countWords(str1));
                break;
            case 4:
                inputString(str2);
                compareStrings(str1, str2);
                break;
            case 5:
                toUpper(str1);
                break;
            case 6:
                addString(str1);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}

