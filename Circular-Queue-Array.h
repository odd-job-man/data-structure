//
//  Circular-Queue-Array.h
//  C
//
//  Created by seungjin oh on 2022/10/02.
//

#ifndef Circular_Queue_h
#define Circular_Queue_h


#endif /* Circular_Queue_h */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 20
typedef int element;
typedef struct{
    element queue[MAX_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType* q){
    q->front = q->rear = 0;
}

bool is_empty(QueueType* q){
    return (q->rear == q->front);
}

bool is_full(QueueType* q){
    return ((q->rear + 1) % MAX_SIZE == q->front); // 포화상태와 공백상태를 구분하기위해 한칸을 무조건 비워야하기때문에
}

void enqueue(QueueType* q, element item){
    if (is_full(q)==true) {
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType* q){
    if (is_empty(q) == true) {
        exit(1);
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->queue[q->front];
}
