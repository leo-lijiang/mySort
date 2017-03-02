#include<stdio.h>

void selectSort(int arr[], int len)
{
    int i, j, temp, index;
    for(i = 0; i < len; i++){
        index = i;
        for(j = i + 1; j < len; j++){
            if(arr[j] > arr[index]){
                index = j;
            }
        }
        if(index != i){
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
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
    selectSort(arr, len);
    printArr(arr, len);
    return 0;
}
