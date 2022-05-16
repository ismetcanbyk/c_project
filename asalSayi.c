int main()
{
    int num,x;
    printf("numara:");
    scanf("%d",&num);
    printf("\n");


    x=num%10;

    while(x==0){
        num=num/10;
        x=num%10;
    }


    printf("x=%d",x);



    return 0;
}

