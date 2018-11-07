/****************************************************************************
 * File name    : linked_list2.c
 * Author       : Alan Liang
 * Description  : ���������㷨��ģ������
 * History      :
 *                v0.1  Alan        2018/11/07 �����ļ�
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // ����
    int data[100] = {0, 2, 3, 5, 8, 9, 10, 18, 26, 32};
    // ��λ�õ���һ��Ԫ�ص�λ��
    int right[100] = {0};
    for (int i = 1; i < 9; ++i)
    {
        right[i] = i+1;
    }
    int head = 1;
    int tail = 10;
    int a = 6;

    // ����6�����ʵ�λ��
    int t = head;
    while(t != 0)
    {
        // �����⣬δ���ǲ���ͷ��������
        if (data[right[t]] > a)
        {
            data[tail] = a;
            right[tail] = right[t];
            right[t] = tail++;
            break;
        }
        t = right[t];
    }

    // ��������
    t = head;
    while(t != 0)
    {
        printf("%d ", data[t]);
        t = right[t];
    }
    printf("\n");
    return 0;
}
