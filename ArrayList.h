//
//  ArrayList.h
//  C
//
//  Created by seungjin oh on 2022/09/26.
//

#ifndef ArrayList_h
#define ArrayList_h


#endif /* ArrayList_h */


#include <stdio.h>
#include <stdbool.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct arrayList{
    element array[MAX_LIST_SIZE]; //배열 정의
    int size;   //현재 리스트에 저장된 항목들의 개수
}ArrayList;

void init(ArrayList* L);                          //리스트를 초기화
void printList(ArrayList* L);                     //리스트의 요소를 출력
void insertLast(ArrayList* L, element item);      //리스트의 마지막에 요소를 추가
void insert(ArrayList* L, element item, int pos); //리스트의 임의의 위치에 요소를 추가
void replace(ArrayList* L, int pos, element item);//지정된 위치의 요소를 입력한 요소로 변경
void clearList(ArrayList* L);
int getLength(ArrayList* L);                      //리스트의 길이를 반환
element delete(ArrayList* L, int pos);            //리스트의 임의의 위치에 요소를 삭제
element getEntry(ArrayList* L,int pos);           //입력한 위치의 요소를 반환
bool isEmpty(ArrayList* L);                       //리스트가 비엇는지 검사
bool isFull(ArrayList* L);                        //리스트가 꽉 찻는지 검사
void init(ArrayList* L){
    L->size = 0;
}

bool isEmpty(ArrayList* L){
    if (L->size == 0) {
        return true;
    }else{
        return false;
    }
}

bool isFull(ArrayList* L){
    if (L->size == MAX_LIST_SIZE) {
        return true;
    }else{
        return false;
    }
}

void printList(ArrayList* L){
    for (int i=0; i<L->size; i++) {
        printf("%d->",L->array[i]);
    }
    printf("\n");
}

element getEntry(ArrayList* L,int pos){
    if (!(0 <= pos && pos < L->size)) {
        printf("위치 에러입니다.\n");
    }
    return L->array[pos];
}

void insertLast(ArrayList* L, element item){
    if (L->size >= MAX_LIST_SIZE) {
        printf("리스트 오버플로우");
    }
    L->array[L->size++] = item;
}

void insert(ArrayList* L, element item, int pos){
    if (isFull(L) == false && (0 <= pos) && (pos < L->size)) {
        for (int i = L->size - 1; i >= pos; i--) {
            L->array[i+1] = L->array[i];
        }
        L->array[pos] = item;
        L->size++;
    }
}

void clearList(ArrayList* L){
    L->size = 0;
}
element delete(ArrayList* L, int pos){
    element item;
    if (!(0 <= pos && pos < L->size) == true){
        printf("위치 에러입니다.\n");
    }
        item = L->array[pos];
        for (int i = pos + 1; i <= L->size - 1; i++) {
            L->array[i-1] = L->array[i];
        }
        L->size--;
        return item;
}


void replace(ArrayList* L, int pos, element item){
    if (0<= pos && pos < L->size) {
        L->array[pos] = item;
    }
}

int getLength(ArrayList* L){
    return L->size;
}

