#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void MENU();
void inputString(char *string,int size);
void word(char *string);
void number(char *string);
int main()
{
    int menu,length;
    char string[30];
    while(1){
        MENU();
        printf("\n");
        scanf("%d",&menu);
        getchar();
        switch(menu){
            case 1:
                inputString(string,sizeof(string));
                printf("\n\n");
                break;
            case 2:
                printf("chuoi dang lam viec la: %s",string);
                printf("\n\n");
                break;
            case 3:
                length=strlen(string);
                printf("do dai chuoi la: %d\n",length);
                printf("\n");
                break;
            case 4:
                printf("\n");
                word(string);
                break;
            case 5:
                printf("\n");
                number(string);
                break;
            case 6:
                return 0;
                break;
            default:
                printf("khong hop le!!!\n");
                break;
        }

    }
    printf("Hello world!\n");
    return 0;
}

void MENU(){
    printf("Options");
    printf("\n1.nhap vao chuoi.");
    printf("\n2.in ra chuoi.");
    printf("\n3.tinh do dai mang.");
    printf("\n4.dem so luong chu cai va in ra.");
    printf("\n5.dem so luong so va in ra.");
    printf("\n6.thoat.");
    printf("\nlua chon cua ban: ");
}

void inputString(char *string,int size){
    fgets(string,size,stdin);
    string[strcspn(string, "\n")] = '\0';
}

void word(char *string){
    int length=strlen(string);
    int dem=0;
    for(int i=0; i<length; i++){
        if(string[i]>='a' && string[i]<='z' || string[i]>='A' && string[i]<='Z'){
            dem++;
        }
    }
    printf("chuoi cua ban co %d chu cai.\n",dem);
}
void number(char *string){
    int length=strlen(string);
    int dem=0;
    for(int i=0; i<length; i++){
        if(string[i]>='0' && string[i]<='9'){
            dem++;
        }
    }
    printf("chuoi cua ban co %d chu so.\n",dem);
}
