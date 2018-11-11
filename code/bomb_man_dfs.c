/****************************************************************************
 * File name    : bomb_man_dfs.c
 * Author       : Alan Liang
 * Description  : ���������㷨��ը���ˣ�dfsʵ��
 *                  # ǽ
 *                  G ����
 *                  . ƽ��
 * History      :
 *                v0.1  Alan        2018/11/11 �����ļ�
 ****************************************************************************/

#include <stdio.h>

#define NEXT_NO 4
#define MAX_ROW 50
#define MAX_COL 50

// ��ͼ
char map[MAX_ROW][MAX_COL] = {
//    0   1   2   3   4   5   6   7   8   9   10  11  12
    {'#','#','#','#','#','#','#','#','#','#','#','#','#'}, // 0
    {'#','G','G','.','G','G','G','#','G','G','G','.','#'}, // 1
    {'#','#','#','.','#','G','#','G','#','G','#','G','#'}, // 2
    {'#','.','.','.','.','.','.','.','#','.','.','G','#'}, // 3
    {'#','G','#','.','#','#','#','.','#','G','#','G','#'}, // 4
    {'#','G','G','.','G','G','G','.','#','.','G','G','#'}, // 5
    {'#','G','#','.','#','G','#','.','#','.','#',' ','#'}, // 6
    {'#','#','G','.','.','.','G','.','.','.','.','.','#'}, // 7
    {'#','G','#','.','#','G','#','#','#','.','#','G','#'}, // 8
    {'#','.','.','.','G','#','G','G','G','.','G','G','#'}, // 9
    {'#','G','#','.','#','G','#','G','#','.','#','G','#'}, // 10
    {'#','G','G','.','G','G','G','#','G','.','G','G','#'}, // 11
    {'#','#','#','#','#','#','#','#','#','#','#','#','#'}, // 12
};

// �õ��Ƿ��Ѿ��жϹ�
int done[MAX_ROW][MAX_COL];

// ��ʼλ��
int start_row = 3, start_col = 3;

// ������������
int max = 0;
int sum;
int target_row, target_col;

// �����ߵķ�����������
int next[NEXT_NO][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

// �߽�(��)
int bound_left = 1;
int bound_right = 11;
int bound_top = 1;
int bound_bottom = 11;

// ��ȡĳ�����Ϸ���ը����������ĵ�����
int get_enemy(int row, int col)
{
    int sum = 0;
    int x, y;

    // ���Ϸ���
    x = row;
    y = col;
    while(map[x][y] != '#') //����ǽ
    {
        if(map[x][y] == 'G') ++sum;
        --x;
    }

    // ���·���
    x = row;
    y = col;
    while(map[x][y] != '#') //����ǽ
    {
        if(map[x][y] == 'G') ++sum;
        ++x;
    }

    // ������
    x = row;
    y = col;
    while(map[x][y] != '#') //����ǽ
    {
        if(map[x][y] == 'G') ++sum;
        --y;
    }

    // ���ҷ���
    x = row;
    y = col;
    while(map[x][y] != '#') //����ǽ
    {
        if(map[x][y] == 'G') ++sum;
        ++y;
    }

    return sum;
}

// ��ǰ����ж�
void go(int row, int col)
{
    sum = get_enemy(row, col);
    // ����max
    if (sum > max) 
    {
        max = sum;
        target_row = row;
        target_col = col;
    }

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

        // δ�߹��ҿ�����
        if (map[next_row][next_col] == '.' &&
            done[next_row][next_col] == 0)
        {
            // ���Ϊ���߹�
            done[next_row][next_col] = 1;
            // �ж���һ����
            go(next_row, next_col);
            // ע���������±��Ϊδ�߹�
        }
    }
    return;
}

int main(void)
{
    // ��ʼ������㣩
    done[start_row][start_col] = 1;

    go(start_row, start_col);

    printf("��ը��������(%d,%d)������������%d������\n",target_row, target_col, max);

    return 0;
}
