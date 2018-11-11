/****************************************************************************
 * File name    : maze_bfs.c
 * Author       : Alan Liang
 * Description  : ���������㷨�����Թ��н��С��
 *                  �Թ�����һ��һ����ɵģ�ÿ��ֻ����һ���������������ĸ�����
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
    int step;   // ����
} node;

// ����
node queue[MAX_ROW*MAX_COL];

int head;   // ��¼��ͷ
int tail;   // ��¼��β����һ������λ�ã�

// �Թ��ϵĵ�(�У���)
int maze[MAX_ROW][MAX_COL] = {
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 1},
};

// �õ��Ƿ��Ѿ��߹�
int done[MAX_ROW][MAX_COL];

// ��ʼλ��
int start_row = 0, start_col = 0;
// Ŀ��λ��
int target_row = 3, target_col = 2;

// ��С����
int min = 9999;

// �����ߵķ�����������
int next[NEXT_NO][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

// �߽�(��)
int bound_left = 0;
int bound_right = 3;
int bound_top = 0;
int bound_bottom = 4;

int main(void)
{
    // ��ʼ������㣩
    head = tail = 0;
    queue[tail].row = start_row;
    queue[tail].col = start_col;
    queue[tail].step = 0;
    ++tail;
    done[start_row][start_col] = 1;

    // �Ƿ񵽴�Ŀ����
    int flag = 0;   

    // ��δ�������Թ��еĵ�
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

            // δ�߹��ҿ�����
            if (maze[next_row][next_col] == 0 &&
                done[next_row][next_col] == 0)
            {
                done[next_row][next_col] = 1;
                queue[tail].row = next_row;
                queue[tail].col = next_col;
                queue[tail].step = queue[head].step+1;
                ++tail;
            }
            // ����Ŀ��㣿
            if (next_row == target_row && next_col == target_col)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
        // �Ƴ�ͷ���
        ++head;
    }

    printf("��С����Ϊ%d\n", queue[tail-1].step);

    return 0;
}
