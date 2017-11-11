/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int l1_val = 0;
    int l2_val = 0;
    if(l1 != NULL){
        l1_val = l1->val;
    }
    if(l2 != NULL){
        l2_val = l2->val;
    }
    int res = l1_val + l2_val;
    struct ListNode * newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = res %10;
    int rest_num = (res - newNode->val) /10;
    newNode->next = NULL;
    if(l1 != NULL){
        if(l1->next != NULL){
            struct ListNode * NodePtr = l1->next;
            NodePtr->val = NodePtr->val + rest_num;
            if(l2 != NULL && l2->next != NULL){
                newNode->next = addTwoNumbers(l1->next, l2->next);
            }else{
                newNode->next = addTwoNumbers(l1->next, NULL);
            }
        }else if(l2 != NULL && l2->next != NULL){
            struct ListNode * NodePtr = l2->next;
            NodePtr->val = NodePtr->val + rest_num;
            newNode->next = addTwoNumbers(NULL, l2->next);
        }else if(rest_num != 0){
            struct ListNode * NodePtr = (struct ListNode *)malloc(sizeof(struct ListNode));
            NodePtr->val = rest_num;
            NodePtr->next = NULL;
            newNode->next = NodePtr;
        }
    }else if(l2 != NULL && l2->next != NULL){
        struct ListNode * NodePtr = l2->next;
        NodePtr->val = NodePtr->val + rest_num;
        newNode->next = addTwoNumbers(NULL, l2->next);
    }else if(rest_num != 0){
        struct ListNode * NodePtr = (struct ListNode *)malloc(sizeof(struct ListNode));
        NodePtr->val = rest_num;
        NodePtr->next = NULL;
        newNode->next = NodePtr;
    }
    return newNode;
}
