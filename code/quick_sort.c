#include <stdio.h>

#define SRC_LEN 10

void quictSort(int arr[], int left, int right);

int main()
{
    // int input[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    int input[] = {6, 1, 2, 1, 10, 3, 5, 5, 10, 8};
    int tmp;

    // 输出原始数组
    printf("原始数组：");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%d ",input[i]);
    printf("\n");

    // 排序
    quictSort(input, 0, SRC_LEN-1);

    // 输出排序后的数组
    printf("排序后  ：");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%d ", input[i]);

    printf("\n");

    return 0;        
}

void quictSort(int arr[], int left, int right)
{
    // 如果只有一个元素或没有元素，则是有序的
    if (left >= right) return;

    // 基准点
    int pviot = arr[left];    // pviot
    int tmp;
    int i = left, j = right;

    while(i != j)
    {
        // 先从右往左，确保最后与pviot交换时是小于等于pviot的值
        // 判断是用>=和<=，所以左右两边的值都有可能等于pviot。
        
        //从右往左，寻找小于基准点的值
        while(arr[j] >= pviot && i < j)
            --j;
        //从左往右，寻找大于基准点的值
        while(arr[i] <= pviot && i < j)
            ++i;
        // 交换
        if (i < j)
        {
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    arr[left] = arr[i];
    arr[i] = pviot;

    quictSort(arr, left, i-1);
    quictSort(arr, i+1, right);
}
