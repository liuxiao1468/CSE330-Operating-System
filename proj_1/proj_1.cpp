// Author: Xiao Liu (asu  id: 1211522751) & Siyu Liu (asu id: 1217399495)
// by only using stdio.
#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "q.h"
#include <unistd.h>
#define _GNU_SOURCE

using namespace std;

int main(){
    item * item_1 = NewItem();
    struct item * p;
    struct item * p2;
    struct item *head = new item;
    InitQueue(head);
    srand(time(0));

    struct item* head2 = new item;
    InitQueue(head2);
    for (int n=0; n<2; n++){
        for (int i=0; i<3; i++){
            item_1 = NewItem();
            item_1->payload=rand()%100;
            AddQueue(head,item_1);
        }

//        p = head;
//        cout<<"=========current queue1 is========" <<endl;
//        while(p->next!=head && p->next!=NULL){
//            p = p->next;
//            cout<<p->payload<<endl;
//        }
//        cout<<"=========end of current queue1========" <<endl;
//        RotateQ(head);
//        p = head;
//        cout<<"=========rotate queue1 is========" <<endl;
//        while(p->next!=head && p->next!=NULL){
//            p = p->next;
//            cout<<p->payload<<endl;
//        }
//        cout<<"=========end of current rotated queue1========" <<endl;

        for (int i=0; i<3; i++){
            item_1 = NewItem();
            item_1->payload=rand()%100;
            AddQueue(head2,item_1);
        }
        while(head->next!= NULL){
            p = head;
            cout<<"current queue1 is = ";
            while(p->next!=head && p->next!=NULL){
                p = p->next;
                cout<<p->payload<<" ";
            }
            cout<<endl;
            cout<< "deleted item: "<< DelQueue(head)->payload<<endl;
        }
        cout<<endl;
        cout<<endl;

        while(head2->next!= NULL){
            p2 = head2;
            cout<<"current queue2 is = ";
            while(p2->next!=head2 && p2->next!=NULL){
                p2= p2->next;
                cout<<p2->payload<<" ";
            }
            cout<<endl;
            cout<< "deleted item "<<DelQueue(head2)->payload<<endl;
        }
        cout<<endl;
    }
}