#include <stdio.h>
#include <stdlib.h>




int main()
{
    int ogrNum, giriSifre, s, x, y=0;

    printf("Ogrenci Numarasi:");
    scanf("%d",&ogrNum);

    printf("\n");

    printf("Sifre Gir:");
    scanf("%d",&giriSifre);

    for(int i=0;i<=9;i++){
        x = (ogrNum % 10);
        ogrNum= ogrNum/10;
        if(x==7){s=7;}
        else if(x==5){s=5;}
        else if(x==3){s=3;}
        else if(x==2){s=2;}else
        if(s>y){
        y=s;
         }

    }


    if(y==giriSifre){
        printf("Giris Basarili");
    }else{
    printf("Basarisiz");
    }


    return 0;
}



