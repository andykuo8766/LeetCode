#include <stdlib.h>
#include <stdio.h>

#define LeetCode 7


#if LeetCode == 1
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

#elif LeetCode == 2
//2. Add Two Numbers
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* root = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = root;
    struct ListNode* NewNode = NULL;
    int temp, v1, v2, carry = 0;
    while (l1 || l2) {
        if (l1) { v1 = l1->val; }
        else { v1 = 0; }
        if (l2) { v2 = l2->val; }
        else { v2 = 0; }
        temp = v1 + v2 + carry;
        if (temp > 9) {
            carry = 1;
            temp = (temp % 10);
        }
        else {
            carry = 0;
        }
        NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        NewNode->val = temp;
        current->next = NewNode;
        current = current->next;

        if (l1)l1 = l1->next;
        if (l2)l2 = l2->next;
    }
    if (carry == 1) {
        NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        NewNode->val = carry;
        NewNode->next = NULL;
        current->next = NewNode;
    }
    NewNode->next = NULL;
    current = root->next;
    free(root);
    return current;
}
#elif LeetCode == 3
//3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(char* s) {
    int max = 0;
    int temp_max = 0;
    int current = 0;
    int repeating_char = 0;
    int new_start = 0;
    int flag = 0;
    if (s[current] == '\0') return 0;
    while (s[current] != '\0') {
        for (repeating_char = current - 1; repeating_char >= new_start; repeating_char--) {
            if (s[repeating_char] == s[current]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            temp_max++;
        }
        else {
            new_start = repeating_char + 1;
            temp_max = current - new_start + 1;
            flag = 0;
        }
        if (temp_max > max)	max = temp_max;
        current++;
    }
    return max;
}
#elif LeetCode == 4
//4. Median of Two Sorted Arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int count = nums1Size + nums2Size;
    if (nums2Size == 0 && nums1Size == 1) return (double)nums1[0];
    if (nums1Size == 0 && nums2Size == 1) return (double)nums2[0];
    int* array = (int*)malloc(sizeof(int) * count);
    int num1, num2;
    int current_num1 = 0;
    int current_num2 = 0;
    int total = 0;
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < count; i++) {
        if (nums1Size == 0) {
            num1 = 0;
            flag1 = 1;
        }
        else {
            num1 = nums1[current_num1];
            flag1 = 0;
        }
        if (nums2Size == 0) {
            num2 = 0;
            flag2 = 1;
        }
        else {
            num2 = nums2[current_num2];
            flag2 = 0;
        }
        if (flag1 == 0 && flag2 == 0) {
            if (num1 <= num2) {

                total += num1;
                array[i] = num1;
                current_num1++;
                if (nums1Size != 0)nums1Size--;
            }
            else {
                total += num2;
                array[i] = num2;
                current_num2++;
                if (nums2Size != 0)nums2Size--;
            }
        }
        else if (flag1 == 0 && flag2 == 1) {
            total += num1;
            array[i] = num1;
            current_num1++;
            if (nums1Size != 0)nums1Size--;
        }
        else if (flag1 == 1 && flag2 == 0) {
            total += num2;
            array[i] = num2;
            current_num2++;
            if (nums2Size != 0)nums2Size--;
        }
        else {//flag1 == 1 & flag2 == 1
        }
    }
    if ((count % 2) != 0) return array[(count / 2)];
    else return ((double)(array[(count / 2)] + array[(count / 2) - 1])) / 2;
}

#elif LeetCode == 5
//5. Longest Palindromic Substring
char* longestPalindrome(char* s) {
    char* start;
    char* end;
    char* p = s;
    char* new_start = s;
    int maxLen = 1;

    while (*p) {
        start = p; end = p;

        while (*(end + 1) && *(end + 1) == *end) {
            end++;
        }
        p = end + 1;

        while (*(end + 1) && (start > s) && *(end + 1) == *(start - 1)) {
            start--;
            end++;
        }

        if (end - start + 1 > maxLen) {
            maxLen = end - start + 1;
            new_start = start;
        }
    }

    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, new_start, maxLen);
    result[maxLen] = '\0';
    return result;
}
#elif LeetCode == 7
// 7. Reverse Integer
int reverse(int x) {
    long long output = 0;
    do
    {
        output = output * 10 + x % 10;
        x /= 10;
    } while (x);

    return (output > INT_MAX || output < INT_MIN) ? 0 : output;
}


#endif
void main() {

#if LeetCode == 1
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

#elif LeetCode == 2
    //2. Add Two Numbers
    struct ListNode l1[3];
    struct ListNode l2[3];

    struct ListNode* ptr = l1;
    ptr->val = 1;
    ptr->next = ptr + 1;
    ptr = ptr->next;
    ptr->val = 2;
    ptr->next = ptr + 1;
    ptr = ptr->next;
    ptr->val = 3;
    ptr->next = NULL;

    ptr = l2;
    ptr->val = 4;
    ptr->next = ptr + 1;
    ptr = ptr->next;
    ptr->val = 5;
    ptr->next = ptr + 1;
    ptr = ptr->next;
    ptr->val = 6;
    ptr->next = NULL;

    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("[");
    while (result->next != NULL) {
        printf("%d", result->val);
        if (result->next != NULL) printf(",");
        result = result->next;
        if (result->next == NULL) {
            printf("%d", result->val);
            break;
        }
    }
    printf("]\n");

#elif LeetCode == 3
    //3. Longest Substring Without Repeating Characters
    char* s = (char*)malloc(sizeof(char) * 10);
    s = "abccabcdees";
    //printf("%s\n", s);
    printf("%d\n", lengthOfLongestSubstring(s));



#elif LeetCode == 4
    //4. Median of Two Sorted Arrays
    int nums1Size = 2;
    int* nums1 = (int*)malloc(sizeof(int) * nums1Size);
    int nums2Size = 2;
    int* nums2 = (int*)malloc(sizeof(int) * nums2Size);
    nums1[0] = 1;
    nums1[1] = 2;
    nums2[0] = 3;
    nums2[1] = 4;
    printf("%f\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));

#elif LeetCode == 5
    //5. Longest Palindromic Substring
    int input_size = 6;
    char* input = (char*)malloc(sizeof(char) * input_size);
    //input = "forgeeksskeegfor";
    input = "babad";

    printf("%s", longestPalindrome(input));
#elif LeetCode == 7
    // 7. Reverse Integer
    int input = 123456;
    printf("%d", reverse(input));
#endif
}