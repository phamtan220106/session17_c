#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void MENU();
void reverse(char *string);
void inputString(char *string,int size);
void countWords(char *string);
void compare(char *string);
void Capitalization(char *string);
void add(char *string);
int main()
{
    int menu;
    char string[50];
    while(1){
        MENU();
        scanf("%d",&menu);
        getchar();
        switch(menu){
            case 1:
                inputString(string,sizeof(string));
                printf("\n");
                break;
            case 2:
                reverse(string);
                printf("\n");
                break;
            case 3:
                printf("\n");
                countWords(string);
                printf("\n");
                break;
            case 4:
                printf("\n");
                compare(string);
                printf("\n");
                break;
            case 5:
                Capitalization(string);
                printf("\n");
                break;
            case 6:
                add(string);
                printf("\n");
                break;
            case 7:
                printf("\n");
                return 0;
            default:
                printf("khong hop le!!\n");
                break;
        }
    }
    printf("Hello world!\n");
    return 0;
}
void MENU(){
    printf("Options");
    printf("\n1.nhap vao chuoi.");
    printf("\n2.in ra chuoi dao nguoc.");
    printf("\n3.dem so luong tu trong chuoi.");
    printf("\n4.nhap vao chuoi khac va so sanh do dai voi chuoi ban dau.");
    printf("\n5.in ra tat ca chu cai trong chuoi.");
    printf("\n6.nhap vao chuoi khac va the vao chuoi ban dau.");
    printf("\n7.thoat.");
    printf("\nlua chon cua ban: ");
}
void inputString(char *string,int size){
    printf("nhap chuoi:\n");
    fgets(string,size,stdin);
    string[strcspn(string,"\n")]='\0';
}
void reverse(char *string){
    int length=strlen(string)-1;
    printf("chuoi dao nguoc la:\n");
    for(int i=length; i>=0; i--){
        printf("%c",string[i]);
    }
}
void countWords(char *string){
    int inword;
    int word=0;
    while(*string){
        if(isspace(*string)){
            inword=0;
        }else if (inword==0){
            inword=1;
            word++;
        }
        string++;
    }
    printf("chuoi cua ban co %d tu.\n",word);
}
void compare(char *string){
    char newStr[50];
    printf("nhap chuoi moi: \n");
    fgets(newStr,sizeof(newStr),stdin);
    newStr[strcspn(newStr,"\n")]='\0';
    printf("chuoi 1: %s\n",string);
    printf("chuoi 2: %s\n",newStr);
    if(strlen(newStr)>strlen(string)){
        printf("chuoi 2 dai hon.\n");
    }else if(strlen(newStr)<strlen(string)){
        printf("chuoi 1 dai hon.\n");
    }else{
        printf("hai chuoi bang nhau.\n");
    }
}
void Capitalization(char *string){
    int length=strlen(string);
    for(int i=0; i<length; i++){
        if(*(string+i)>='a' && *(string+i)<='z'){
            *(string+i)=*(string+i)-32;
        }
    }
        printf("%s",string);
}
void add(char *string){
    char newStr[50];
    printf("nhap chuoi moi: \n");
    fgets(newStr,sizeof(newStr),stdin);
    newStr[strcspn(newStr,"\n")]='\0';
    printf("chuoi 1: %s\n",string);
    printf("chuoi 2: %s\n",newStr);
    strcat(string,newStr);
    printf("chuoi sau khi noi la: %s\n",string);

}
