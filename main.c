#include <stdio.h>
#include <stdlib.h>

void sezar(size_t x, char *a);
void reSezar(size_t x, char *a);
int sifreBul(int b);
void read();
void write();


struct ogrenci{
    char name[35];
    char surname[35];
    int ogrNum;
    int sifre;
}ogr;

void main()
{

    int giriSifre;

    printf("isim girin:");
    scanf("%s",&ogr.name);

    size_t sizeName = sizeof(ogr.name)/2;

    sezar(sizeName, ogr.name);

    printf("\n");

    printf("Soyad girin:");
    scanf("%s",&ogr.surname);


    size_t sizeSurname = sizeof(ogr.surname)/2;

    sezar(sizeSurname, ogr.surname);


    write();

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

    printf("\n\n");

    read();
    reSezar(sizeName, ogr.name);
    reSezar(sizeSurname, ogr.surname);

    printf("\n\n");

    printf("Cozumlenmis Sifre:%s ",ogr.name,ogr.surname);

    printf("\n\n");

    printf("Ogrenci Numarasi: %d",ogr.ogrNum);

    printf("\n\n");

}

void sezar(size_t x, char *a)
{
    for(int i=0;i<x;i++){

        if(a[i]!='\0'){
                a[i]=a[i]+5;
                if(a[i]>122){
                   a[i]=a[i]-26;
                }
        }

    }
}


void reSezar(size_t x, char *a)
{
    for(int i=0;i<x;i++){

        if(a[i]!='\0'){
                a[i]=a[i]-5;
                if(a[i]<97){
                   a[i]=a[i]+26;
                }
        }
    }
}

int sifreBul(int b){
    int i;
    for(i=2;b>1;i++){
        while(b%i==0)
        {
            b=b/i;
        }

    }
    return i-1;
}



void write(){
    FILE *enc;
    enc = fopen("sifrelimetin.txt","w+");
    if(enc==NULL){
        printf("Dosya Acilamadi!");
    }else {
        fprintf(enc,ogr.name);
        fprintf(enc,ogr.surname);
        fclose(enc);

    }

}

void read(){
    int c;
    FILE *enc;
    enc = fopen("sifrelimetin.txt","r+");
    if(enc==NULL){
        printf("Dosya Acilamadi!");
    }else{
        while(c!=EOF){
            c = fscanf(enc,"%s  ",ogr.name,ogr.surname);
            if(c!=EOF)
                printf("Sifreli metin: %s ",ogr.name,ogr.surname);
        }fclose(enc);
    }
}

