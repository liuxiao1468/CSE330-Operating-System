// Author: Xiao Liu (asu  id: 1211522751) & Siyu Liu (asu id: 1217399495)

#include "threads.h"

#include <stdio.h>
#include <unistd.h>

struct semaphore{
    int count;
    struct TCB_t * Q;
};

void init_sem(struct semaphore * semaphore, int value){
    semaphore->count = value;
    semaphore->Q = InitQueue();
}

void P(struct semaphore * semaphore){
    semaphore->count--;
    if (semaphore->count<0){
        struct TCB_t * temp;
        temp = DelQueue(runQ);
        AddQueue(semaphore->Q, runQ);
        swapcontext(&(temp->context),&(runQ->context));
    }
}

void v(struct semaphore * semaphore){
    semaphore->count++;
    if (semaphore->count<=0){
        struct TCB_t * temp;
        temp = DelQueue(semaphore->Q);
        AddQueue(runQ,temp);
    }
    yield();
}