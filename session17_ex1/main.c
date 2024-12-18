#include <stdio.h>
#include <stdlib.h>

void MENU();
void inputArray(int **arrPtr, int *length);
void displayArray(int *arrPtr, int length);
void arrayLength(int *length);
void sumArray(int *arrPtr, int length);
void maxElement(int *arrPtr, int length);

int main() {
    int menu;
    int *arrPtr = NULL;
    int length = 0;

    while (1) {
        MENU();
        scanf("%d", &menu);
        getchar();

        switch (menu) {
            case 1:
                inputArray(&arrPtr, &length);
                printf("\n");
                break;
            case 2:
                displayArray(arrPtr, length);
                printf("\n");
                break;
            case 3:
                arrayLength(&length);
                printf("\n");
                break;
            case 4:
                sumArray(arrPtr, length);
                printf("\n");
                break;
            case 5:
                maxElement(arrPtr, length);
                printf("\n");
                break;
            case 6:
                free(arrPtr);
                printf("\n");
                return 0;
            default:
                printf("Không hợp lệ\n");
                break;
        }
    }

    return 0;
}

void MENU() {
    printf("MENU\n");
    printf("1. Nhập vào số phần tử và từng phần tử\n");
    printf("2. Hiển thị các phần tử trong mảng\n");
    printf("3. Tính độ dài mảng\n");
    printf("4. Tính tổng các phần tử trong mảng\n");
    printf("5. Hiển thị phần tử lớn nhất\n");
    printf("6. Thoát\n");
    printf("Lựa chọn của bạn: ");
}

void inputArray(int **arrPtr, int *length) {
    printf("Nhập vào số phần tử của mảng: ");
    scanf("%d", length);
    *arrPtr = (int *)malloc(*length * sizeof(int));
    if (*arrPtr == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        return 0;;
    }
    for (int i = 0; i < *length; i++) {
        printf("Nhập phần tử thứ %d: ", i + 1);
        scanf("%d", (*arrPtr + i));
    }
}

void displayArray(int *arrPtr, int length) {
    printf("Các phần tử trong mảng là: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", *(arrPtr + i));
    }
    printf("\n");
}

void arrayLength(int *length) {
    printf("Độ dài của mảng là: %d\n", *length);
}

void sumArray(int *arrPtr, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += *(arrPtr + i);
    }
    printf("Tổng các phần tử trong mảng là: %d\n", sum);
}

void maxElement(int *arrPtr, int length) {
    if (length <= 0) {
        printf("Mảng trống.\n");
        return;
    }
    int max = *arrPtr;
    for (int i = 1; i < length; i++) {
        if (*(arrPtr + i) > max) {
            max = *(arrPtr + i);
        }
    }
    printf("Phần tử lớn nhất trong mảng là: %d\n", max);
}
