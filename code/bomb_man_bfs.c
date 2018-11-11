/****************************************************************************
 * File name    : bomb_man_bfs.c
 * Author       : Alan Liang
 * Description  : ���������㷨��ը���ˣ�bfsʵ��
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

int main(void)
{
    int sum;
    int target_row, target_col;
    // ��ʼ������㣩
    head = tail = 0;
    queue[tail].row = start_row;
    queue[tail].col = start_col;
    ++tail;
    done[start_row][start_col] = 1;
    max = get_enemy(start_row, start_col);
    target_row = start_row;
    target_col = start_col;

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

            // δ�߹��ҿ�����
            if (map[next_row][next_col] == '.' &&
                done[next_row][next_col] == 0)
            {
                // �������
                done[next_row][next_col] = 1;
                queue[tail].row = next_row;
                queue[tail].col = next_col;
                ++tail;

                sum = get_enemy(next_row, next_col);
                // ����max
                if (sum > max) 
                {
                    max = sum;
                    target_row = next_row;
                    target_col = next_col;
                }
            }
        }
        // �Ƴ�ͷ���
        ++head;
    }

    printf("��ը��������(%d,%d)������������%d������\n",target_row, target_col, max);

    return 0;
}
