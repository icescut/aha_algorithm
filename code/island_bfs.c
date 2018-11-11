/****************************************************************************
 * File name    : island_bfs.c
 * Author       : Alan Liang
 * Description  : ���������㷨������̽��
 *                  0   - ����
 *                  1~9 - ½��
 * History      :
 *                v0.1  Alan        2018/11/11 �����ļ�
 ****************************************************************************/

#include <stdio.h>

#define NEXT_NO 4
#define MAX_ROW 50
#define MAX_COL 50

// ��¼һ������Ϣ
typedef struct node
{
    int row;    // ��
    int col;    // ��
} node;

// ����
node queue[MAX_ROW*MAX_COL];

int head;   // ��¼��ͷ
int tail;   // ��¼��β����һ������λ�ã�

// ��ͼ
int map[MAX_ROW][MAX_COL] = {
//   0  1  2  3  4  5  6  7  8  9
    {1, 2, 1, 0, 0, 0, 0, 0, 2, 3}, // 0
    {3, 0, 2, 0, 1, 2, 1, 0, 1, 2}, // 1
    {4, 0, 1, 0, 1, 2, 3, 2, 0, 1}, // 2
    {3, 2, 0, 0, 0, 1, 2, 4, 0, 0}, // 3
    {0, 0, 0, 0, 0, 0, 1, 5, 3, 0}, // 4
    {0, 1, 2, 1, 0, 1, 5, 4, 3, 0}, // 5
    {0, 1, 2, 3, 1, 3, 6, 2, 1, 0}, // 6
    {0, 0, 3, 4, 8, 9, 7, 5, 0, 0}, // 7
    {0, 0, 0, 3, 7, 8, 6, 0, 1, 2}, // 8
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 9
};

// �õ��Ƿ��Ѿ��жϹ�
int done[MAX_ROW][MAX_COL];

// ��ʼλ��
int start_row = 5, start_col = 7;

// ���䵺������
int sum;

// �����ߵķ�����������
int next[NEXT_NO][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

// �߽�(��)
int bound_left = 0;
int bound_right = 9;
int bound_top = 0;
int bound_bottom = 9;

int main(void)
{
    // ��ʼ������㣩
    head = tail = 0;
    queue[tail].row = start_row;
    queue[tail].col = start_col;
    ++tail;
    done[start_row][start_col] = 1;
    sum = 1;

    // ��δ�������ͼ�еĵ�
    while(head < tail)
    {
        // ����4������
        for (int i = 0; i < NEXT_NO; ++i)
        {
            int next_row = queue[head].row + next[i][0];
            int next_col = queue[head].col + next[i][1];

            // ��������߽�
            if (next_row < bound_top ||
                next_row > bound_bottom ||
                next_col < bound_left ||
                next_col > bound_right)
                continue;

            // δ�߹��Ҳ��Ǻ���
            if (map[next_row][next_col] > 0 &&
                done[next_row][next_col] == 0)
            {
                // �������
                done[next_row][next_col] = 1;
                queue[tail].row = next_row;
                queue[tail].col = next_col;
                ++tail;

                ++sum;
            }
        }
        // �Ƴ�ͷ���
        ++head;
    }

    printf("����ĵ�������Ϊ%d\n",sum);

    return 0;
}
