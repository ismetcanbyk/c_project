#include <stdio.h>
#include <stdlib.h>

void sezar(size_t x, char *a);
int sifreBul(int b);

struct ogrenci{
    char name[20];
    char surname[12];
    int ogrNum;
    int sifre;
}ogr;

void main()
{
    int giriSifre;
    FILE *enc;

    enc = fopen("sifrelimetin.txt","w+");
    if(enc==NULL){
        printf("Dosya Acilamadi!");
    }else{

    printf("isim girin:");
    scanf("%s",&ogr.name);

    size_t sizeName = sizeof(ogr.name)/2;

    sezar(sizeName, ogr.name);


    printf("\n");

    printf("Soyad girin:");
    scanf("%s",&ogr.surname);


    size_t sizeSurname = sizeof(ogr.surname)/2;

    sezar(sizeSurname, ogr.surname);

    fprintf(enc,ogr.name);
    fprintf(enc,ogr.surname);
    fclose(enc);
    printf("\n");
    printf("Ogrenci Numarasi Gir:");
    scanf("%d",&ogr.ogrNum);
    printf("\n");
    TRY:
    printf("Sifre Gir:");
    scanf("%d",&giriSifre);
    printf("\n");

    ogr.sifre = sifreBul(ogr.ogrNum);

    if(ogr.sifre==giriSifre){
        printf("giris basarili");
    }else{printf("Hatali Parola"); printf("\n"); goto TRY;}
    }
    printf("\n");
    printf("sifre:%d",ogr.sifre);


}

void sezar(size_t x, char *a)
{
    for(int i=0;i<x;i++){

        if(a[i]!='\0'){
                a[i]=a[i]+5;
                if(a[i]>=122){
                   a[i]=a[i]-26;
                }
        }

    }
}

int sifreBul(int b){
    int key=0;
    int x, y;
    for(int i=0;i<=9;i++){


            x = (b % 10);
        b= b/10;
        if(x==7){y=7;}
        else if(x==5){y=5;}
        else if(x==3){y=3;}
        else if(x==2){y=2;}
        else if(y>key){
        key=y;
         }


    }
    return key;
}


