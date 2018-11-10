/****************************************************************************
 * File name    : permutation.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》全排列
 * History      :
 *                v0.1  Alan        2018/11/10 建立文件
 ****************************************************************************/

#include <stdio.h>

// 各位置上的数
int pos[100];
// 该数是否已经使用
int done[100];
// 全排列1~n
int n;

void permutation(int step)
{
    // 到达第n+1个位置，表示结束
    if (step == n + 1)
    {
        // 打印结果
        for (int i = 1; i <= n; ++i)
            printf("%2d ", pos[i]);
        printf("\n");
        return;
    }

    // 遍历1~n个可能的数
    for (int i = 1; i <= n; ++i)
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
    printf("请输入全排列的数(2~99):");
    scanf("%d", &n);
    permutation(1);

    return 0;
}
