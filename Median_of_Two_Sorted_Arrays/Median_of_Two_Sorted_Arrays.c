#include <stdlib.h>
#include <stdio.h>

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
        else if(flag1 == 0 && flag2 == 1){
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
        else {//flag1 == 1 && flag2 == 1

        }
    }
    if ((count % 2) != 0) return array[(count / 2)];
    else return ((double)(array[(count / 2)] + array[(count / 2) - 1])) / 2;


}

void main() {
    int nums1Size = 2;
    int* nums1 = (int*)malloc(sizeof(int) * nums1Size);

    int nums2Size = 2;
    int* nums2 = (int*)malloc(sizeof(int) * nums2Size);

    nums1[0] = 1;
    nums1[1] = 2;

    nums2[0] = 3;
    nums2[1] = 4;

    printf("%f\n",findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));



}