#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20], surname[12];


    printf("Ad giriniz: ");
    scanf("%s",&name);
    printf("%s", name);
    printf("\n");
    size_t size = sizeof(name)/2;
    printf("%d",size);
    printf("\n");




    for(int i=0;i<size;i++){

        if(name[i]!='\0'){
                name[i]=name[i]+5;
                if(name[i]>=122){
                   name[i]=name[i]-26;
                }
        }

    }

    printf("sifreli name = %s",name);











    return 0;
}
