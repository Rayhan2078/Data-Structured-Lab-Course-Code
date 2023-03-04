#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
};
void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
};
void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
};
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
};
int largest(int arr[], int n)
{
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
};
int main()
{
    int Boys[50],n,i,Girls[50];
    printf("Number:");
    scanf("%d",&n);
    printf("Boys:");
    for(i=0; i<n; i++)
        scanf("%d",&Boys[i]);
    printf("Girls:");
    for(i=0; i<n; i++)
        scanf("%d",&Girls[i]);
    selectionSort(Boys,n);
    printf("\n");
    printArray(Boys,n);
    insertionSort(Girls,n);
    printf("\n");
    printArray(Girls,n);
    if(largest(Boys,n)>largest(Girls,n)) printf("\nYES");
    else printf("\nNO");
    getch();
}
