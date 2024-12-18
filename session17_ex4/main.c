#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int *arrPtr,length;
void MENU();
void inputArray();
void evenNumber();
void primeNumbers();
void reverse();
void soft(char x);
int main()
{
    int menu,value;
    char x;
    while(1){
        MENU();
        scanf("%d",&menu);
        getchar();
        switch(menu){
            case 1:
                inputArray();
                printf("\n");
                break;
            case 2:
                evenNumber();
                printf("\n");
                break;
            case 3:
                primeNumbers();
                printf("\n");
                break;
            case 4:
                reverse();
                printf("\n");
                break;
            case 5:
                printf("a.tang dan.\n");
                printf("b.giam dam.\n");
                scanf(" %c",&x);
                if(x=='a' || x=='b'){
                    soft(x);
                }else{
                    printf("khong hop le!!\n");
                }
                printf("\n");
                break;
            case 6:
                printf("nhap gia tri muon tim. ");
                scanf("%d",&value);
                search(value);
                printf("\n");
                break;
            case 7:
                printf("\n");
                return 0;
            default:
                printf("khong hop le\n");
                break;
        }
    }
    printf("Hello world!\n");
    return 0;
}
void MENU(){
    printf("Options");
    printf("\n1.nhap vao so phan tu va gia tri.");
    printf("\n2.hien thi cac phan tu chan.");
    printf("\n3.hien thi cac phan tu la so nguyen to.");
    printf("\n4.dao nguoc mang.");
    printf("\n5.sap sep.");
    printf("\n6.nhap vao mot phan tu va tim kiem.");
    printf("\n7.thoat.");
    printf("\nlua chon cua ban: ");
}
void inputArray(){
    length=1;
    printf("nhap vao gia tri cua mang va -1 de ket thuc:\n");
    arrPtr=(int *)calloc(length,sizeof(int));
    if(arrPtr==NULL){
        printf("khong the cap phat bo nho.\n");
        free(arrPtr);
        return 0;
    }
    int temp,i=0;
    do{
        if(i==length){
            length++;
            arrPtr=realloc(arrPtr,length*sizeof(int));
            if(arrPtr==NULL){
                printf("khong the cap phat bo nho.\n");
                free(arrPtr);
                return 0;
            }
        }
        printf("Arr[%d]: ",i+1);
        scanf("%d",&temp);
        if(temp!=-1){
            *(arrPtr+i)=temp;
            i++;
        }
    }while(temp!=-1);
}
void evenNumber(){
    printf("cac phan tu la so chan la:\n");
    for(int i=0;i<length;i++){
        if(*(arrPtr+i)%2==0){
            printf("%d ",*(arrPtr+i));
        }
    }
}
void primeNumbers(){
    int dem=0;
    printf("cac phan tu la so nguyen to la:\n");
    for(int i=0;i<length;i++){
        dem=0;
        for(int j=2; j<=sqrt(*(arrPtr+i)); j++){
            if(*(arrPtr+i)%j==0){
                dem=1;
                break;
            }
        }
        if(dem==0 && *(arrPtr+i)>1){
            printf("%d ",*(arrPtr+i));
        }
    }
}
void reverse(){
    printf("mang truoc khi dao nguoc.\n");
    for(int i=0; i<length-1;i++){
        printf("%d ",*(arrPtr+i));
    }
    int start=0;
    int end=length-1;
    while(start<end){
        int temp=*(arrPtr+start);
        *(arrPtr+start)=*(arrPtr+end);
        *(arrPtr+end)=temp;
        start++;
        end--;
    }
    printf("mang sau khi dao nguoc.\n");
    for(int i=0; i<length-1;i++){
        printf("%d ",*(arrPtr+i));
    }
}
void soft(char x){
    if(x=='a'){
        for(int i=0;i<length-1;i++){
            for(int j=0; j<length-i-2; j++){
                if(*(arrPtr+j)>*(arrPtr+j+1)){
                    int temp=*(arrPtr+j);
                    *(arrPtr+j)=*(arrPtr+j+1);
                    *(arrPtr+j+1)=temp;
                }
            }
        }
    }else{
        for(int i=0;i<length-1;i++){
            for(int j=0; j<length-i-2; j++){
                if(*(arrPtr+j)<*(arrPtr+j+1)){
                    int temp=*(arrPtr+j);
                    *(arrPtr+j)=*(arrPtr+j+1);
                    *(arrPtr+j+1)=temp;
                }
            }
        }
    }
    printf("mang sau khi sap sep:\n");
    for(int i=0; i<length-1;i++){
        printf("%d ",*(arrPtr+i));
    }
}
void search(int value){
    int start=0;
    int end=length-1;
    int mid;
    while(start<=end){
        mid=(start+end)/2;
        if(*(arrPtr+mid)==value){
            printf("%d nam o vi tri %d trong mang.\n",value,mid+1);
            return -1;
        }
        if(value>mid){
            start=mid++;
        }else{
            end=mid--;
        }
    }
    printf("%d khong ton tai trong mang.\n");
}
