#include<stdio.h>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapAdjust(int arr[], int i, int len)
{
    int lchild = 2*i + 1;//左孩子下标
    int rchild = 2*i + 2;//右孩子下标
    int min = i;//min记录根，左，右孩子里最小的数的下标
    if(i <= (len - 1) / 2){
        if((lchild <= len - 1)&&(arr[lchild] < arr[min])){
            min = lchild;
        }
        if((rchild <= len - 1)&&(arr[rchild] < arr[min])){
            min = rchild;
        }
        if(min != i){
            swap(arr[i], arr[min]);
            heapAdjust(arr, min, len);//重新排列调整后的子树
        }
    }
}

void buildHeap(int arr[], int len)
{
    int i;
    //非叶结点最大下标为(len-1)/2
    for(i = (len-1) / 2; i >= 0; i--){
        heapAdjust(arr, i, len);
    }
}

void heapSort(int arr[], int len)
{
    //建立最小堆
    buildHeap(arr, len);
    //循环从堆中取最小值(堆顶元素)
    int i, temp;
    for(i = len - 1; i >= 0; i--){
        //将最后一个元素与第一个元素交换
        swap(arr[i], arr[0]);
        //重新调整堆
        heapAdjust(arr, 0, i);
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
    int arr[] = {1,8,10,4,6,5,7,2,9,3,3,3};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, len);
    heapSort(arr, len);
    printArr(arr, len);
    return 0;
}
