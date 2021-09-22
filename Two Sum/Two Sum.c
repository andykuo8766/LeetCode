/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *ret=(int *)malloc(*returnSize*sizeof(int));
    int temp;
    for(int i = 0 ; i < numsSize ; i++){
        temp=target-nums[i];
        for(int j = i + 1 ; j < numsSize ; j++){
            if(temp == nums[j]){
                ret[0] = i;
                ret[1] = j;
                return ret;
            }        
        }
    }
    return ret;
}