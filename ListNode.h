#include <stdbool.h>
#include <stdlib.h>

#ifndef ListNode_h
#define ListNode_h


#endif /* ListNode_h */

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode* link;
}ListNode;

ListNode* create_node(element data,ListNode* link){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->link = NULL;
    return node;
}

void insert_node(ListNode** phead, ListNode* p, ListNode* node){
    if (*phead == NULL) { //공백 리스트일때
        *phead = node;
        node->link = NULL;
    }else if (p == NULL){ //이전 노드가없을때 첫번째 자리에 노드삽입
        node->link = (*phead);
        *phead = node;
    }else{
        node->link = p->link;
        p->link = node;
    }
}

void remove_node(ListNode** phead, ListNode* p, ListNode* node){
    if (p==NULL) {//첫번째 노드 삭제
        (*phead) = (*phead)->link;
    }else{
        p->link = node ->link;
    }
    free(node);
}

ListNode* search(ListNode* head, element x){
    ListNode* p = head;
    while (p != NULL) {
        if (p->data == x) {
            return p; //탐색 성공
        }
        p = p->link;
    }
    return p; //탐색 실패시 NULL 반환
}

ListNode* concat(ListNode* head1, ListNode* head2){
    ListNode* p = head1;
    if (head1 == NULL) {
        return head2;
    }else if (head2 == NULL){
        return head1;
    }else{
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = head2;
        return head1;
    }
}

ListNode* reverse(ListNode* head){ // 리스트를 역으로 뒤집기
    ListNode* p = head ,*q = head, *r = NULL;
    while (p != NULL) {
        p = p->link; // p: 다음 처리할 노드
        q->link = r; // q: 처리 중인 노드
        r = q;       // r: 처리 완료된 노드
        q = p;       // 다음 처리할 노드로 이동
    }
    return r; // 역순으로 변한 리스트의 첫번째 노드
}
