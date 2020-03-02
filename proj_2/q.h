// Author: Xiao Liu (asu  id: 1211522751) & Siyu Liu (asu id: 1217399495)
#include<unistd.h>
#define	_GNU_SOURCE
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "TCB.h"

/*struct item
{
    int payload;
    struct item * next = NULL;
    struct item * prev = NULL;
};*/

/*struct item * NewItem(){
    struct item * p = new item;
    p->payload = 1;
    return p;
}*/
struct TCB_t * runQ;
//runQ->next=NULL;
//runQ->prev=NULL;
struct TCB_t * InitQueue(){
    struct TCB_t * RunQ = (TCB_t *)malloc(1*sizeof(TCB_t));
    RunQ->next=NULL;
    RunQ->prev=NULL;
    return RunQ;
}

void AddQueue(struct TCB_t* RunQ, struct TCB_t * item){
    if (RunQ->next  == NULL && RunQ->prev == NULL){
        RunQ->next = item;
        RunQ->prev = item;
        item->prev = RunQ;
        item->next = RunQ;
    }
    else{
        struct TCB_t* mid = RunQ->prev;
        RunQ->prev = item;
        mid->next=item;
        item->next = RunQ;
        item->prev = mid;
    }
}

struct TCB_t* DelQueue(struct TCB_t * RunQ){
    if (RunQ->prev == NULL && RunQ->next == NULL){
        return RunQ;
    }
    else if (RunQ->next->next == RunQ){
        struct TCB_t* p0;
        p0 = RunQ->next;
        RunQ->next = NULL;
        RunQ->prev = NULL;
        return p0;
    }
    else{
        struct TCB_t * p;
        struct TCB_t * p1;
        p = RunQ->next;
        p1 = p->next;
        RunQ->next = p1;
        p1->prev = RunQ;
        return p;
    }
}

void RotateQ(struct TCB_t * RunQ){
    AddQueue( RunQ, DelQueue(RunQ));
}







