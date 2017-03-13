
template<class T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template<class T>
void heapAdjust(T arr[], int i, int len, bool (*compare)(const T&,const T&))
{
    int lchild = 2*i + 1;//左孩子下标
    int rchild = 2*i + 2;//右孩子下标
    int min = i;//min记录根，左，右孩子里最小的数的下标
    if(i <= (len - 1) / 2){
        if((lchild <= len - 1)&&(compare(arr[lchild], arr[min]))){
            min = lchild;
        }
        if((rchild <= len - 1)&&(compare(arr[rchild], arr[min]))){
            min = rchild;
        }
        if(min != i){
            swap(arr[i], arr[min]);
            heapAdjust(arr, min, len, compare);//重新排列调整后的子树
        }
    }
}

template<class T>
void buildHeap(T arr[], int len, bool (*compare)(const T&, const T&))
{
    int i;
    //非叶结点最大下标为(len-1)/2
    for(i = (len-1) / 2; i >= 0; i--){
        heapAdjust(arr, i, len, compare);
    }
}

template<class T>
void heapSort(int arr[], int len, bool (*compare)(const T&, const T&))
{
    //建立最小堆
    buildHeap(arr, len, compare);
    //循环从堆中取最小值(堆顶元素)
    int i, temp;
    for(i = len - 1; i >= 0; i--){
        //将最后一个元素与第一个元素交换
        swap(arr[i], arr[0]);
        //重新调整堆
        heapAdjust(arr, 0, i, compare);
    }
}
