//
//  Circular Queue - LinkedList.h
//  C
//
//  Created by seungjin oh on 2022/10/02.
//

#ifndef Circular_Queue___LinkedList_h
#define Circular_Queue___LinkedList_h


#endif /* Circular_Queue___LinkedList_h */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int element;
typedef struct QueueNode{
    element item;
    struct QueueNode* link;
}QueueNode;

typedef struct LinkedQueue{
    QueueNode* front, *rear;
}LinkedQueue;

void init_queue(LinkedQueue* q){
    q->front = q->rear = NULL;
}

bool is_empty(LinkedQueue* q){
    return (q->front == NULL);
}

bool is_full(LinkedQueue* q){
    return false;
}

void enqueue(LinkedQueue* q, element item){
    QueueNode* t = (QueueNode*)malloc(sizeof(QueueNode));
    if (t == NULL) {
        exit(1);
    }
    t->item = item; t->link = NULL;
    
    if (is_empty(q)) {
        q->rear = q->front = t;
    }else{
        q->rear->link = t;
        q->rear = t;
    }
}

element dequeue(LinkedQueue* q){
    if (is_empty(q)) {
        exit(1);
    }
    QueueNode* t = q->front;
    element item = t->item;
    q->front = q->front->link;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(t);
    return item;
}

void print_queue(LinkedQueue* q){
    if (is_empty(q)) { exit(1); }
    QueueNode* t = q->front;
    do {
        printf("%d ",t->item);
        t = t->link;
    } while (t != NULL);
    printf("\n");
}
