#include <stdio.h>

#define SRC_LEN 10

void quictSort(int arr[], int left, int right);

int main()
{
    // int input[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    int input[] = {6, 1, 2, 1, 10, 3, 5, 5, 10, 8};
    int tmp;

    // ���ԭʼ����
    printf("ԭʼ���飺");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%d ",input[i]);
    printf("\n");

    // ����
    quictSort(input, 0, SRC_LEN-1);

    // �������������
    printf("�����  ��");
    for (int i = 0; i < SRC_LEN; ++i)
        printf("%d ", input[i]);

    printf("\n");

    return 0;        
}

void quictSort(int arr[], int left, int right)
{
    // ���ֻ��һ��Ԫ�ػ�û��Ԫ�أ����������
    if (left >= right) return;

    // ��׼��
    int pviot = arr[left];    // pviot
    int tmp;
    int i = left, j = right;

    while(i != j)
    {
        // �ȴ�������ȷ�������pviot����ʱ��С�ڵ���pviot��ֵ
        // �ж�����>=��<=�������������ߵ�ֵ���п��ܵ���pviot��
        
        //��������Ѱ��С�ڻ�׼���ֵ
        while(arr[j] >= pviot && i < j)
            --j;
        //�������ң�Ѱ�Ҵ��ڻ�׼���ֵ
        while(arr[i] <= pviot && i < j)
            ++i;
        // ����
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
