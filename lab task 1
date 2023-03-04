#include<stdio.h>
int add(int a[ ],int size,int jog);
void main()
{
    int size;
    printf("Please Enter how many elements you want : ");
    scanf("%d",&size);
    int a[size];
    printf("Please Enter the elements : ");
    for (int  i = 0; i < size; i++)
    {
       scanf("%d",&a[i]);
    }
    int sum=10;

    add(a,size,sum);


}
int add(int a[ ],int size,int jog)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
          if(a[i]+a[j]==jog)
          {
            printf("%d+%d=%d\",a[i],a[j],jog);
          }
        }
    }
}
