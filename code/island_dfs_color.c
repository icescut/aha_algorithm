/****************************************************************************
 * File name    : island_dfs.c
 * Author       : Alan Liang
 * Description  : ���������㷨������̽��, ��ɫ�ڽ��ĵ�
 *                  0   - ����
 *                  1~9 - ½��
 * History      :
 *                v0.1  Alan        2018/11/11 �����ļ�
 ****************************************************************************/

#include <stdio.h>

#define NEXT_NO 4
#define MAX_ROW 50
#define MAX_COL 50

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

void go(int row, int col, int color)
{
    // ��ɫ
    map[row][col] = color;
    // ����4������
    for (int i = 0; i < NEXT_NO; ++i)
    {
        int next_row = row + next[i][0];
        int next_col = col + next[i][1];

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
            ++sum;
            done[next_row][next_col] = 1;
            go(next_row, next_col, color);
        }
    }
    return;
}

void print_map()
{
    for (int i = bound_top; i <= bound_bottom; ++i)
    {
        for (int j = bound_left; j <= bound_right; ++j)
        {
            printf("%3d ", map[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    printf("��ɫ֮ǰ��\n");
    print_map();

    int color = -1;
    done[start_row][start_col] = 1;
    sum = 1;
    go(start_row, start_col, color);

    printf("��ɫ֮��\n");
    print_map();
    return 0;
}
