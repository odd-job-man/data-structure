//
//  LinkedList.h
//  C
//
//  Created by seungjin oh on 2022/09/28.
//

#ifndef LinkedList_h
#define LinkedList_h


#endif /* LinkedList_h */
#include <stdio.h>
#include "ListNode.h"

typedef struct LinkedList{
    ListNode* head;
    int length;
}LinkedList;


bool is_empty(LinkedList* list){ // 비었는지 검사
    if (list->head == NULL) {
        return true;
    }else{
        return false;
    }
}

int get_length(LinkedList* list){ // 리스트의 길이 반환
    return list->length;
}

ListNode* get_nodeptr(LinkedList* list, int pos){ //첫번째 리스트노드는 pos = 0
    ListNode* ptr = list->head;
    if (pos<0) {
        return NULL;
    }
    for (int i=0; i<pos; i++) {
        ptr = ptr->link;
    }
    return ptr;
}

void add(LinkedList* list, int pos, element data){
    ListNode* p; //추가하려는 자리 이전노드
    if ((0<=pos) && (pos<= list->length)) {
        ListNode* node = create_node(data, NULL);
        if (node == NULL) {
            exit(1);
        }
        p = get_nodeptr(list, pos-1);
        insert_node(&(list->head), p, node);
        list->length++;
    }
}

void add_last(LinkedList* list, element data){
    int length = get_length(list);
    add(list, length, data);
}

void add_first(LinkedList* list, element data){
    add(list, 0, data);
}

void delete(LinkedList* list, int pos){
    if (is_empty(list) == false && (0 <= pos) && (pos < get_length(list)) ) {
        ListNode* p = get_nodeptr(list, pos-1); //삭제하고자 하는 노드의 이전노드
        remove_node(&(list->head), p, (p == NULL) ? list->head : p->link);
    }
    list->length--;
}

void clear_list(LinkedList* list){
    int length = get_length(list);
    for (int i=0; i<length; i++) {
        delete(list, i);
    }
}

void display(LinkedList* list){
    int length = get_length(list);
    ListNode* node = list->head;
    for (int i=0; i<length; i++) {
        printf("%d->",node->data);
        node = node->link;
    }
}

bool is_in_list(LinkedList* list, element item){
    ListNode* p = search(list->head, item);
    if (p !=NULL) {
        return true;
    }else{
        return false;
    }
}

element get_entry(LinkedList* list, int pos){
    ListNode* p = get_nodeptr(list, pos); // 지정한 위치의 주소
    return p->data;
}
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
