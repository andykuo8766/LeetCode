#include <stdlib.h>
#include <stdio.h>

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


void main() {


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
        printf("%d",result->val);
        if(result->next != NULL) printf(",");
        result = result->next;
        if (result->next == NULL) {
            printf("%d", result->val);
            break;
        }
    }
    printf("]\n");

}