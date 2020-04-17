// Author: Xiao Liu (asu  id: 1211522751) & Siyu Liu (asu id: 1217399495)
// we choose option2 with N=10 children. In our code, it doesn't matter how large N is.
// if you want to change N into something else, you can modify the initial array and add/delete some number of children threads.
// we add sleep(1) in reader and writer code, you will need to wait for 10s to see the result of each round.

#include "sem.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define _GNU_SOURCE

int gID=0;

struct semaphore * r_sem;
struct semaphore * w_sem;
struct semaphore * mutex;

int rwc = 0;
int wwc = 0;
int rc = 0;
int wc = 0;
int array[10] = {0,0,0,0,0,0,0,0,0,0};


void reader_entry(int ID){
    printf("[children: #%d]\t trying to update array[%d]\t \n",ID, ID);
    P(mutex);
    if(wwc>0 || wc>0){
//        printf("[children: #%d]\t blocking for parent\n",ID);
        rwc++;
        v(mutex);
        P(r_sem);
        rwc--;
    }
    rc++;
    if (rwc>0)
        v(r_sem);
    else
        v(mutex);
}

void reader_exit(int ID){
    P(mutex);
    rc--;
    if (rc == 0 && wwc>0){
        v(w_sem);
    }
    else{
        v(mutex);
    }
}

void writer_entry(int ID){
    printf("\t\t\t\t\t[parent] trying to print array\n");
    P(mutex);
    if (rc>0 || wc>0){
//        printf("\t\t\t\tparent blocking others\n");
        wwc++;
        v(mutex);
        P(w_sem);
        wwc--;
    }
    wc++;
    v(mutex);
}

void writer_exit(int ID){
    P(mutex);
    wc--;
    if(rwc>0){
        v(r_sem);
    }
    else if (wwc>0){
        v(w_sem);
    }
    else{
        v(mutex);
    }
}

void reader(void){
    int ID;
    P(mutex);
    ID = gID++;
    v(mutex);
    while(1){
        reader_entry(ID);
        array[ID] = array[ID]+1;
//        printf("reader current array \t %d \t %d \t %d \n",array[0],array[1], array[2]);
        sleep(1);
        reader_exit(ID);
    };
}

void writer(void){
    int ID;
    P(mutex);
    ID = gID++;
    v(mutex);
    while(1){
        writer_entry(ID);
        printf("\t\t\t\t\t[parent] current array is [%d %d %d %d %d %d %d %d %d %d]\n",
                array[0],array[1], array[2],array[3],array[4], array[5],array[6],array[7], array[8],array[9]);
        sleep(1);
        writer_exit(ID);
    };
}


int main(){

	runQ=InitQueue();

	mutex = init_sem(1);
    r_sem = init_sem(0);
    w_sem = init_sem(0);


	start_thread(reader);
	start_thread(reader);
    start_thread(reader);
    start_thread(reader);
    start_thread(reader);
    start_thread(reader);
    start_thread(reader);
    start_thread(reader);
    start_thread(reader);
    start_thread(reader);
	start_thread(writer);
//    start_thread(writer);
	run();

	return 0;
}
