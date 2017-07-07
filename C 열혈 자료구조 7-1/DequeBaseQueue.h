#pragma once
#ifndef __DEQ_BASE_QUE_H__
#define __DEQ_BASE_QUE_H__

#include "Deque.h"

typedef Deque Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);

Data QPeek(Queue * pq);

#endif