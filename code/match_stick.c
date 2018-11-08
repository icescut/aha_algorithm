/****************************************************************************
 * File name    : match_stick.c
 * Author       : Alan Liang
 * Description  : ���������㷨��������ʽ
 *                A + B = C
 *                +��=�����������
 * History      :
 *                v0.1  Alan        2018/11/08 �����ļ�
 ****************************************************************************/

#include <stdio.h>

int sticks = 0;
// 0~9���ö��ٸ����
int stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int get_sticks(int x)
{
    sticks = 0;

    // �ۼӸ�λ�����õĻ����
    while (x / 10 != 0)
    {
        sticks += stick[x % 10];
        x /= 10;
    }
    sticks += stick[x];
    return sticks;
}

int main(void)
{
    int num, sum = 0;
    printf("�����������Ŀ��С�ڵ���24����");
    scanf("%d", &num);
    // 1���������ռ�����٣�20�����20-4��������10��1��������һ������������1111��1+1111=1111
    for(int a = 0; a <= 1111; a++)
    {
        for (int b = 0; b <= 1111; b++)
        {
            int c = a + b;
            if(get_sticks(a) + get_sticks(b) + get_sticks(c) == num - 4)
            {
                printf("%3d+%3d=%3d\n", a, b, c);
                sum++;
            }
        }
    }
    printf("һ������ƴ��%d����ͬ�ĵ�ʽ", sum);

    return 0;
}
