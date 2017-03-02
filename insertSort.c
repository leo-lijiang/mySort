#include<stdio.h>

void insertSort(int arr[], int len)
{
    int i, j, temp;
    for(i = 0; i< len - 1; i++){
        if(arr[i+1] > arr[i]){
            temp = arr[i+1];
            for(j = i + 1; j > 0&&temp > arr[j-1]; j--){
                arr[j] = arr[j-1];
            }
            arr[j] = temp;
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

int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, len);
    insertSort(arr, len);
    printArr(arr, len);
    return 0;
}
