/****************************************************************************
 * File name    : permutation.c
 * Author       : Alan Liang
 * Description  : ���������㷨�����Ϊ1~9��9���˿��ƣ�ʹ����A+B=C��A/B/C�ֱ�
 *                 Ϊ3λ��
 * History      :
 *                v0.1  Alan        2018/11/10 �����ļ�
 ****************************************************************************/

#include <stdio.h>

// ��λ���ϵ���
int pos[10];
// �����Ƿ��Ѿ�ʹ��
int done[10];
int total;

void permutation(int step)
{
    // �����10��λ�ã���ʾ����
    if (step == 10)
    {
        if((pos[1]+pos[4])*100 + (pos[2]+pos[5])*10 + pos[3] + pos[6] == pos[7]*100 + pos[8]*10+pos[9])
        {
            total++;
            // ��ӡ���
            printf("%d%d%d+%d%d%d=%d%d%d", pos[1], pos[2], pos[3], pos[4], pos[5], pos[6], pos[7], pos[8], pos[9]);
            printf("\n");
        }
        return;
    }

    // ����1~9�����ܵ���
    for (int i = 1; i <= 9; ++i)
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
    permutation(1);
    printf("��%d�ֿ���\n", total);

    return 0;
}
