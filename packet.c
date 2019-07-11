//
// Created by me_touch on 19-7-10.
// 生成回型数组
//

#include <stdio.h>

/**
 * 一个num * num 长的数组，环绕生成的次数为 2 * num - 1，
 * 可以把每一次的环绕看成一条边，
 * 抽象成每条边的长度就是对数组的部分赋值
 * 每条边的环绕长度取决于环绕次数m，m / 4, m % 4
 * @param num 生成的数组长度num * num
 *  1   2   3   4   5
 *  16  17  18  19  6
 *  15  24  25  20  7
 *  14  23  22  21  8
 *  13  12  11  10  9
 */
void makePacketArray(int num)
{
    int arr[num][num];
    int count = 2 * num - 1;
    int i = 0, j = 0;
    for (int n = 1; n <= count; n++)
    {
        if (n == 1)
        {
            for (j = 0; j < num; j++)
            {
                arr[0][j] = j + 1;
            }
            i = 1;
            j = num - 1;
        } else
// 每条边的环绕长度取决于环绕次数m，m / 4, m % 4, 通过取余， 取模运算计算边上的每个节点的值
// 例如当 m%4 = 2时，则计算对应数组arr[a +1][num -a -1]...arr[num -a -1][num -a -1]的值
        {
            int a = n / 4;
            int b = n % 4;
            if (b == 2)
            {
                j = num - a - 1;
                for (int k = a + 1; k < num - a; k++)
                {
                    arr[k][j] = arr[k - 1][j] + 1;
                }
            } else if (b == 3)
            {
                i = num - a - 1;
                for (int k = j - 1; k >= a; k--)
                {
                    arr[i][k] = arr[i][k + 1] + 1;
                }
            } else if (b == 0)
            {
                j = a - 1;
                for (int k = i - 1; k >= a; k--)
                {
                    arr[k][j] = arr[k + 1][j] + 1;
                }
            } else if (b == 1)
            {
                i = a;
                for (int k = j + 1; k < num - a; k++)
                {
                    arr[i][k] = arr[i][k - 1] + 1;
                }
            }
        }
    }
    for (int l = 0; l < num; ++l)
    {
        for (int k = 0; k < num; ++k)
        {
            printf("\t%d", arr[l][k]);
        }
        printf("\n");
    }
}

int main()
{
    makePacketArray(5);
    return 0;
}