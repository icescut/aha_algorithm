/****************************************************************************
 * File name    : permutation.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》编号为1~9的9张扑克牌，使符合A+B=C，A/B/C分别
 *                 为3位数
 * History      :
 *                v0.1  Alan        2018/11/10 建立文件
 ****************************************************************************/

#include <stdio.h>

// 各位置上的数
int pos[10];
// 该数是否已经使用
int done[10];
int total;

void permutation(int step)
{
    // 到达第10个位置，表示结束
    if (step == 10)
    {
        if((pos[1]+pos[4])*100 + (pos[2]+pos[5])*10 + pos[3] + pos[6] == pos[7]*100 + pos[8]*10+pos[9])
        {
            total++;
            // 打印结果
            printf("%d%d%d+%d%d%d=%d%d%d", pos[1], pos[2], pos[3], pos[4], pos[5], pos[6], pos[7], pos[8], pos[9]);
            printf("\n");
        }
        return;
    }

    // 遍历1~9个可能的数
    for (int i = 1; i <= 9; ++i)
    {
        // 未使用
        if (done[i] == 0)
        {
            // 放到位置
            pos[step] = i;
            done[i] = 1;
            // 下一步
            permutation(step+1);
            // 恢复未使用
            done[i] = 0;
        }
    }
    return;
}

int main(void)
{
    permutation(1);
    printf("共%d种可能\n", total);

    return 0;
}
