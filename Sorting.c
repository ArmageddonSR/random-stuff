#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int n);
void swap(int* x , int* y);
void printArr(int arr[], int n);
void SelectionSort(int arr[],int n );
void InsertionSort(int arr[], int n);

int main(int argc , char* argv[])
{
    printf("argc = %d\n",argc);
    
    int* arr;
    
    arr = (int*)malloc((argc-1)*sizeof(int)); 
    
    for(int i = 0 ; i<argc-1 ; i++)
    {
        arr[i] = atoi(argv[i+1]);
    }

    //BubbleSort(arr,argc-1);
    //SelectionSort(arr,argc-1);
    InsertionSort(arr,argc-1);
    

    free(arr);

    return 0;
}

void swap(int* x , int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArr(int arr[], int n)
{
    for(int i = 0 ; i <n ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
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

void SelectionSort(int arr[],int n )
{   
    int swapped = 0;
    for(int i = 0 ; i < n-1 ; i++ )
    {
        int min = i;
        for(int j = i+1 ; j<n ; j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
                swapped = 1;
            }
        }
        if(swapped == 1)
        {
            swap(&arr[i],&arr[min]);
            printArr(arr,n);
        }
    }
}

void InsertionSort(int arr[], int n)
{
    for(int i = 1; i<n ; i++)
    {
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
        printArr(arr,n);
    }
}
