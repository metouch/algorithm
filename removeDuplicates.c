//
// Created by me_touch on 19-7-15.
//

/*给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
  不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/

/*
  示例 2:

  给定 nums = [0,0,1,1,1,2,2,3,3,4],
  函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
  你不需要考虑数组中超出新长度后面的元素。
 */
#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){
    if (nums == NULL) return 0;
    if(numsSize < 2) return numsSize;
    int i = 0, count = 1;
    while (++ i < numsSize){
        if(nums[i] == nums[i - 1]){
            continue;
        } else {
            nums[count] = nums[i];
            count ++;
        }
    }
    return count;
}

int main(){
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int count = removeDuplicates(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", count);
    for (int i = 0; i < count; ++i)
    {
        printf("\t%d", *(nums + i));
    }
    return 0;
}