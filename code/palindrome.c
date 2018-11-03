/****************************************************************************
 * File name    : card_game.c
 * Author       : Alan Liang
 * Description  : ���������㷨������
 * History      :
 *                v0.1  Alan        2018/11/03 �����ļ�
 ****************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100], stack[100];
    int top = 0, next;

    // ��������
    printf("������һ���ַ�����");
    gets(input);

    int len = strlen(input);
    int mid = len / 2 - 1;

    // ǰ�벿����ջ
    for (int i = 0; i <= mid; ++i)
        stack[top++] = input[i];

    // �õ����е����һ��λ��
    if (len % 2 == 0)
        next = mid + 1;
    else
        next = mid + 2;

    // ���αȽ�
    for (int i = next; i < len; ++i)
    {
        if(stack[--top] != input[i])
        {
            printf("FALSE\n");
            return 0;
        }
    }
    printf("TRUE\n");
    return 0;
}
