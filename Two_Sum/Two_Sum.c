#include <stdlib.h>
#include <stdio.h>

//1. Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = (int*)malloc(2 * sizeof(int));
    int temp;
    for (int i = 0; i < numsSize; i++) {
        temp = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (temp == nums[j]) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return ret;
}
void main() {

    //1. Two Sum
    int numsSize = 3;
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    nums[0] = 2;
    nums[1] = 3;
    nums[2] = 4;
    int target = 6;
    int* returnSize = (int*)malloc(sizeof(int) * 2);
    returnSize = twoSum(nums, numsSize, target, returnSize);
    printf("[%d,%d]\n", returnSize[0], returnSize[1]);

}