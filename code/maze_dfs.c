/****************************************************************************
 * File name    : maze_dfs.c
 * Author       : Alan Liang
 * Description  : ���������㷨�����Թ��н��С��
 *                  �Թ�����һ��һ����ɵģ�ÿ��ֻ����һ���������������ĸ�����
 * History      :
 *                v0.1  Alan        2018/11/10 �����ļ�
 ****************************************************************************/

#define NEXT_NO 4
#define MAX_ROW 50
#define MAX_COL 50

#include <stdio.h>

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

/*
 * Function     : ������ǰλ�����п����ߵķ��򣬽�����һ��
 * Description  :
 * In           : ��ǰλ�ã���ǰ�ǵڼ���
 * Out          : void
 */
void go(int row, int col, int step)
{
    // printf("��%d���ߵ�(%d,%d)\n", step, row, col);  // DEBUG
    // ����С����λ��
    if (row == target_row && col == target_col)
    {
        // printf("����Ŀ�ĵ�\n"); // DEBUG
        if(step < min)
            min = step;
        return;
    }

    // ����4������
    for (int i = 0; i < NEXT_NO; ++i)
    {
        // ��һ��λ��
        int next_row = row + next[i][0];
        int next_col = col + next[i][1];

        // ��������߽�
        if (next_row < bound_top ||
            next_row > bound_bottom ||
            next_col < bound_left ||
            next_col > bound_right)
            continue;

        // ������
        if (maze[next_row][next_col] == 0 &&
            done[next_row][next_col] == 0)
        {
            done[next_row][next_col] = 1;
            // ��һ��
            go(next_row, next_col, step+1);
            // �ָ�δ�߹�
            done[next_row][next_col] = 0;
        }
    }
    // printf("�ص���%d��\n", step-1);  // DEBUG
    return;
}

int main(void)
{
    done[start_row][start_col] = 1;
    go(start_row, start_col, 0);

    printf("��С����Ϊ%d\n", min);

    return 0;
}
