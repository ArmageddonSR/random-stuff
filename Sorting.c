#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int n);
void swap(int* x , int* y);
void printArr(int arr[], int n);

int main(int argc , char* argv[])
{
    printf("argc = %d\n",argc);
    
    int* arr;
    
    arr = (int*)malloc((argc-1)*sizeof(int)); 
    
    for(int i = 0 ; i<argc-1 ; i++)
    {
        arr[i] = atoi(argv[i+1]);
        printf("%d ",arr[i]);
    }
    printf("\n");

    BubbleSort(arr,argc-1);

    free(arr);

    return 0;
}

void swap(int* x , int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int arr[], int n)
{
    int i , j , swapped;
    for(int i =0 ; i<n-1 ; i++)
    {
        for(int j = 0; j<n-i-1 ; j++)
        {
            swapped = 0;
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapped = 1;
                printf("swapped %d with %d : ",arr[j],arr[j+1]);
                printArr(arr,n);
                
            }
        }
        if(swapped == 0) break;
    }
}

void printArr(int arr[], int n)
{
    for(int i = 0 ; i <n ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}