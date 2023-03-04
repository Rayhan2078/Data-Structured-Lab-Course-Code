#include<stdio.h>
int duplicate(int arr[ ],int size,int number);
int main()
{
    int size;
    printf("Please enter the size of the array : ");
    scanf("%d",&size);
    int a[size];
    printf("Please enter the elemets : ");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&a[i]);
    }
    int value;
    printf("Which value you want to search : ");
    scanf("%d",&value);
    int how;
    how=duplicate(a,size,value);
    printf("%d occur %d times",value,how);

}
int duplicate(int arr[ ],int size,int number)
{
    int count=0;
     for(int i=0;i<size;i++)
     {
         if(arr[i]==number)
         count++;
     }
     return count;

}
