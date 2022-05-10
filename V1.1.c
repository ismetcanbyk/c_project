#include <stdio.h>
#include <stdlib.h>

void sezar(size_t x, char *a);

struct ogrenci{
    char name[20];
    char surname[12];
    int ogrNum;
}ogr;

void main()
{

    FILE *enc;

    enc = fopen("sifreleme.txt","w+");
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
    }


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



