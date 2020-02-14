// Author: Xiao Liu (asu  id: 1211522751) & Siyu Liu (asu id: 1217399495)
#include<unistd.h>
#define	_GNU_SOURCE
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

struct item
{
    int payload;
    struct item * next = NULL;
    struct item * prev = NULL;
};

struct item * NewItem(){
    struct item * p = new item;
    p->payload = 1;
    return p;
}

void InitQueue(struct item * head){
    head->payload=0;
    head->next=NULL;
    head->prev=NULL;
}

void AddQueue(struct item* head, struct item * item){
    if (head->next  == NULL && head->prev == NULL){
        head->next = item;
        head->prev = item;
        item->prev = head;
        item->next = head;
    }
    else{
        struct item* mid = head->prev;
        head->prev = item;
        mid->next=item;
        item->next = head;
        item->prev = mid;
    }
}

struct item* DelQueue(struct item * head){
    if (head->prev == NULL && head->next == NULL){
        return head;
    }
    else if (head->next->next == head){
        struct item* p0;
        p0 = head->next;
        head->next = NULL;
        head->prev = NULL;
        return p0;
    }
    else{
        struct item * p;
        struct item * p1;
        p = head->next;
        p1 = p->next;
        head->next = p1;
        p1->prev = head;
        return p;
    }
}

void RotateQ(struct item * head){
    AddQueue( head, DelQueue(head));
}







