// Author: Xiao Liu (asu  id: 1211522751) & Siyu Liu (asu id: 1217399495)

#include <stdio.h>
#include "q.h"
#include <unistd.h>

void start_thread(void (*function) (void)){
	void * StackPointer;
	struct TCB_t * tcb;
	int StackSize=8192;
	StackPointer = malloc(StackSize);
	tcb = (TCB_t *)malloc(1*sizeof(TCB_t));
	tcb->next=NULL;
	tcb->prev=NULL;
	init_TCB(tcb, function, StackPointer, StackSize);
	AddQueue(runQ, tcb);
}

void run(){
	struct TCB_t * Curr_Thread=runQ->next;
	ucontext_t parent;
	getcontext(&parent);
	swapcontext(&parent, &(Curr_Thread->context));

}

void yield(){
	struct TCB_t *PrevThread=runQ->next;
	RotateQ(runQ);
	struct TCB_t *CurrThread=runQ->next;
	swapcontext(&(PrevThread->context), &(CurrThread->context));
}
