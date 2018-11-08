/****************************************************************************
 * File name    : match_stick.c
 * Author       : Alan Liang
 * Description  : 《啊哈，算法》火柴棍等式
 *                A + B = C
 *                +和=各用两根火柴
 * History      :
 *                v0.1  Alan        2018/11/08 建立文件
 ****************************************************************************/

#include <stdio.h>

int sticks = 0;
// 0~9各用多少根火柴
int stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int get_sticks(int x)
{
    sticks = 0;

    // 累加各位数字用的火柴数
    while (x / 10 != 0)
    {
        sticks += stick[x % 10];
        x /= 10;
    }
    sticks += stick[x];
    return sticks;
}

int main(void)
{
    int num, sum = 0;
    printf("请输入火柴棍数目（小于等于24）：");
    scanf("%d", &num);
    // 1用两根火柴，占用最少，20根火柴（20-4）最多组成10个1，所以任一个数都不大于1111。1+1111=1111
    for(int a = 0; a <= 1111; a++)
    {
        for (int b = 0; b <= 1111; b++)
        {
            int c = a + b;
            if(get_sticks(a) + get_sticks(b) + get_sticks(c) == num - 4)
            {
                printf("%3d+%3d=%3d\n", a, b, c);
                sum++;
            }
        }
    }
    printf("一共可以拼出%d个不同的等式", sum);

    return 0;
}
