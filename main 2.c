#include <stdio.h>
#include <stdlib.h>

int sonNumara(int a);
void sezar(size_t x, char *a, int y);
void reSezar(size_t x, char *a, int y);
int sifreBul(int b);
void read();
void write();
int sNum;

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

    printf("\n");

    printf("Soyad girin:");
    scanf("%s",&ogr.surname);

    printf("\n");

    strcat(ogr.name,ogr.surname);

    printf("Ogrenci Numarasi Gir:");
    scanf("%d",&ogr.ogrNum);
    sonNumara(ogr.ogrNum);
    printf("\n");

    size_t sizeSurname = sizeof(ogr.surname)/2;

    sezar(sizeName, ogr.name, sNum);

    write();

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
    reSezar(sizeName, ogr.name, sNum);

    printf("\n\n");

    printf("Cozumlenmis Sifre:%s ",ogr.name);

    printf("\n\n");

    printf("Ogrenci Numarasi: %d",ogr.ogrNum);

    printf("\n\n");

}

void sezar(size_t x, char *a, int y)
{

    for(int i=0;i<x;i++){
        if(a[i]!='\0'){
                if(a[i]+y>122){
                   a[i]=a[i]-26;
                }
            a[i]=a[i]+y;
        }
    }
}

int sonNumara (int a){

    sNum=a%10;
    while(sNum==0){
        a=a/10;
        sNum=a%10;

    }
    return sNum;
}

void reSezar(size_t x, char *a, int y)
{
    for(int i=0;i<x;i++){

        if(a[i]!='\0'){
                a[i]=a[i]-y;
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
            c = fscanf(enc,"%s  ",ogr.name);
            if(c!=EOF)
                printf("Sifreli metin: %s ",ogr.name);
        }fclose(enc);
    }
}
