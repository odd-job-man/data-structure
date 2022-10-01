//
//  Stack - LinkedList.h
//  C
//
//  Created by seungjin oh on 2022/10/01.
//

#ifndef Stack___LinkedList_h
#define Stack___LinkedList_h


#endif /* Stack___LinkedList_h */
#include <stdbool.h>
#include <stdlib.h>
typedef int element;
typedef struct StackNode{
    element item;
    struct StackNode* link;
}StackNode;

typedef struct{
    StackNode* top;
} LinkedStack;

void init(LinkedStack* s){
    s->top = NULL;
}

bool is_empty(LinkedStack* s){
    return s->top == NULL;
}

bool is_full(LinkedStack* s){ // 연결리스트로 구현하면 꽉찰수가 없음
    return false;
}

void push(LinkedStack* s, element item){
    StackNode* t = (StackNode*)malloc(sizeof(StackNode));
    if (t == NULL) {
        exit(1);
    }
    t->item = item;
    t->link = s->top; s->top = t;
}

element pop(LinkedStack* s){
    if (is_empty(s) == true) {
        exit(1);
    }
    StackNode* t = s->top;
    element item = t->item;
    s->top = s->top->link;     free(t);
    return item;
}
