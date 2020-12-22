#include <assert.h>
#include "trading.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>


Queue queue_new(uint32_t size){

    Queue q1 = {size, 0, 0, 0, {NULL}};
    return q1;
}
uint8_t queue_full(Queue *q){
    assert(q != NULL);
    return (q->count == q->size);
}

uint8_t queue_empty(Queue *q){
    assert(q != NULL);
    return (q->count == 0);

}
uint32_t queue_length(Queue *q) {
    assert(q != NULL);
    return q->count;
}

Queue* buy(Queue *q,char name[], char date[], int32_t prize,int32_t quantity, QueueResult *res) {
    assert(q != NULL);
    if (q->count < q->size){
        strcpy(q->d[q->rear].share_name,name);
        strcpy(q->d[q->rear].date,date);
        q->d[q->rear].prize = prize;
        q->d[q->rear].quantity = quantity;
        q->rear = (q->rear + 1) % q->size;
        ++q->count;
        res->status = QUEUE_OK;
    } else {
        res->status = QUEUE_FULL;
    }

    return q;
}
int lookup(Queue *q,char com_name[]){
    assert(q != NULL);
    int i;
    for(i=0;i<q->count;i++){
        if(!strcmp(q->d[i].share_name,com_name)){
        return 1;
        }
    }
    return 0;
}
Queue* sell(Queue *q, QueueResult *res){
    assert( q != NULL );
    if (q->count != 0){
        res->data = q->d[q->front];
        q->front = (q->front+1)%q->size;
        --q->count;
        res->status = QUEUE_OK;
    }else{
        res->status = QUEUE_EMPTY;
    }
    return q;
}


Queue topup(Queue*q,QueueResult *res,int32_t quant,char com_name[]){
    assert(q!=NULL);
    for(i=q->front;i<=Q_LEN;i++)
    {
        if(if(!strcmp(q->d[i].share_name,com_name)))
            q->d[i].quantity+=quant;
    }
    return q;
}
