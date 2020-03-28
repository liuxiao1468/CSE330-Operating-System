// Author: Xiao Liu (asu  id: 1211522751) & Siyu Liu (asu id: 1217399495)

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

void reader_entry(int ID){
    printf("[reader: #%d]\t trying to read\n",ID);
    P(mutex);
    if(wwc>0 || wc>0){
        printf("[reader: #%d]\t blocking for writer\n",ID);
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
    printf("\t\t\t\t[writer: #%d]\t trying to write\n",ID);
    P(mutex);
    if (rc>0 || wc>0){
        printf("\t\t\t\t[writer: #%d] blocking for others\n",ID);
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
        printf("[reader #%d]\t ****READING****\n",ID);
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
        printf("\t\t\t\t[writer: #%d]\t &&&WRITING!&&&\n",ID);
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
	start_thread(writer);
    start_thread(writer);
	run();

	return 0;
}
