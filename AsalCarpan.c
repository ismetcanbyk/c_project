#include <stdio.h>
#include <string.h>
int main()
{

 int sayi;
 printf("Bir sayi degeri giriniz...\n");
 scanf("%d",&sayi);

 for(int i=2;sayi>1;i++)
 {
  while(sayi%i==0)
  {

   printf("%d\t",i);
   sayi=sayi/i;

  }
 }

 return 0;
}
