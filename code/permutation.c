/****************************************************************************
 * File name    : permutation.c
 * Author       : Alan Liang
 * Description  : ���������㷨��ȫ����
 * History      :
 *                v0.1  Alan        2018/11/10 �����ļ�
 ****************************************************************************/

#include <stdio.h>

// ��λ���ϵ���
int pos[100];
// �����Ƿ��Ѿ�ʹ��
int done[100];
// ȫ����1~n
int n;

void permutation(int step)
{
    // �����n+1��λ�ã���ʾ����
    if (step == n + 1)
    {
        // ��ӡ���
        for (int i = 1; i <= n; ++i)
            printf("%2d ", pos[i]);
        printf("\n");
        return;
    }

    // ����1~n�����ܵ���
    for (int i = 1; i <= n; ++i)
    {
        // δʹ��
        if (done[i] == 0)
        {
            // �ŵ�λ��
            pos[step] = i;
            done[i] = 1;
            // ��һ��
            permutation(step+1);
            // �ָ�δʹ��
            done[i] = 0;
        }
    }
    return;
}

int main(void)
{
    printf("������ȫ���е���(2~99):");
    scanf("%d", &n);
    permutation(1);

    return 0;
}
