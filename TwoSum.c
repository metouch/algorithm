//
// Created by me_touch on 19-7-11.
//
/**给定一个整数数组 nums 和一个目标值 target，
请你在该数组中找出和为目标值的那 两个 整数，
并返回他们的数组下标

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
 */
#include <stdlib.h>
#include <stdio.h>

int *twoSum(const int *nums, int numsSize, int target, int *returnSize)
{
    int maxNum = numsSize;
    int *p = (int *)malloc( maxNum * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize - 1; i ++)
    {
        for (int j = i + 1; j < numsSize; j ++)
        {
            if(nums[i] + nums[j] == target)
            {
                p[*returnSize] = i;
                *returnSize += 1;
                p[*returnSize] = j;
                *returnSize += 1;
            }
        }
    }
    if(*returnSize == 0){
        free(p);
        return NULL;
    } else
    {
        if(*returnSize < maxNum){
            p = realloc(p, (unsigned int)*returnSize);
        }
        return p;
    }
}

int main(){
    int num[4] = {2, 7, 11, 15};
    int size = 0;
    int *p = twoSum(num, 4, 9, &size);
    for (int i = 0; i < size; ++i)
    {
        printf("\t%d", p[i]);
    }
}
