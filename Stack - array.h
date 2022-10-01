//
//  Stack - array.h
//  C
//
//  Created by seungjin oh on 2022/10/01.
//

#ifndef Stack___array_h
#define Stack___array_h


#endif /* Stack___array_h */
#define MAX_SIZE 100
#define MAX_STRING 20
#include <stdbool.h>
#include <stdlib.h>
typedef struct{
    int student_no;
    char name[MAX_STRING];
}element;

typedef struct StackType{
    element stack[MAX_SIZE];
    int top;
}StackType;

bool init(StackType* s){ // 스택을 초기화
    return s->top = -1;
}

bool is_empty(StackType* s){ // 스택이 비었는지 확인
    return s->top == -1;
}

bool is_full(StackType* s){ // 스택이 꽉 찻는지 확인
    return (s->top == MAX_SIZE - 1);
}

void push(StackType* s, element item){ // 스택에 아이템을 삽입
    if (is_full(s)==true) {
        exit(1);
    }
    s->stack[++(s->top)] = item;
}

element pop(StackType* s, element item){ // 스택의 맨위의 아이템을 반환후 삭제
    if (is_empty(s) == true) {
        exit(1);
    }
    return s->stack[(s->top)--];
}
