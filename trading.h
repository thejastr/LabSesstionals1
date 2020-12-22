
#include <stdint.h>
#include "appconst.h"
#ifndef TRADING_H_INCLUDED
#define TRADING_H_INCLUDED
typedef struct _data_ Data;
typedef struct _queue_ Queue;
struct _data_{
    char     share_name[32];
    char     date[10];
    int32_t  prize;
    int32_t  quantity;
};


struct _queue_ {
    uint32_t size;
    uint32_t count;
    uint32_t rear;
    uint32_t front;
    Data d[NO_OF_SHARES];

};


typedef struct  _queue_result_ QueueResult;

struct _queue_result_ {
    Data data;
    uint32_t status;
};
Queue queue_new (uint32_t size);
uint8_t queue_full(Queue *q);
uint8_t queue_empty(Queue *q);
Queue* buy(Queue *q,char name[], char date[], int32_t prize,int32_t quantity, QueueResult *res);
Queue* sell(Queue *q, QueueResult *res);
uint32_t queue_length(Queue *q);
int lookup(Queue *q,char com_name[]);
Queue topup(Queue*q,QueueResult *res,int32_t quant,char com_name[]);

#endif
