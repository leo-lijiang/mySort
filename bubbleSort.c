#include<stdio.h>

void sortArr(int arr[], int len)
{
    int i, j, temp;
    for(i = 1; i < len; i++){
        for(j = 0; j < len - i; j++){
            if(arr[j] < arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArr(int arr[], int len)
{
    int i;
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
/*
int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, len);
    bubbleSort(arr, len);
    printArr(arr, len);
    return 0;
}
*/
