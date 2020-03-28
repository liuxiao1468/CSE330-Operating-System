// Author: Xiao Liu (asu  id: 1211522751) & Siyu Liu (asu id: 1217399495)

#include "threads.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

struct semaphore{
    int count;
    struct TCB_t * Q;
};

struct semaphore * init_sem(int value){
    struct semaphore * s = (struct semaphore *)malloc(1*sizeof(struct semaphore));
    s->count = value;
    s->Q = InitQueue();
    return s;
}

void P(struct semaphore * semaphore){
    struct TCB_t * temp;
    semaphore->count--;
    if (semaphore->count<0){

        temp = DelQueue(runQ);
        AddQueue(semaphore->Q, temp);
        struct TCB_t * Curr_Thread=runQ->next;
        swapcontext(&(temp->context),&(Curr_Thread->context));
    }
}

void v(struct semaphore * semaphore){
    struct TCB_t * temp;
    semaphore->count++;
    if (semaphore->count<=0){
        temp = DelQueue(semaphore->Q);
        AddQueue(runQ,temp);
    }
    yield();
}