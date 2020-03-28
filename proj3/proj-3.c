// Author: Xiao Liu (asu  id: 1211522751) & Siyu Liu (asu id: 1217399495)
// We choose method-2 for this project

#include "sem.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define _GNU_SOURCE


int N=4;
int in = 0;
int out = 0;
int buffer[4];
int item_num = 0;

struct semaphore * full;
struct semaphore * empty;

void prod(void){
    while(1){
        P(empty);
        printf("producing item #%d, into slot #%d\n",item_num, in);
        buffer[in] = item_num++;
        in = (in+1)%N;
        sleep(1);
        v(full);
    }
}

void cons(void){
    while(1){
        P(full);
        printf("\t\t\t consuming item #%d, from slot #%d\n", buffer[out], out);
        out = (out + 1)%N;
        sleep(1);
        v(empty);
    }
}


int main(){

	runQ=InitQueue();
    full = init_sem(0);
    empty = init_sem(N);


	start_thread(prod);
	start_thread(prod);
    start_thread(cons);
    start_thread(cons);

	run();

	return 0;
}
