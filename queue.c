#include<stdio.h>
#include<malloc.h>

#ifndef _QUEUE_C
#define _QUEUE_C

#include "queue.h"


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef struct VERTEX Vertex_Nodes;

typedef struct VQueue_Nodes{
    Vertex_Nodes *vertex;
    struct VQueue_Nodes *next;
}VQnodes;

VQnodes *head = NULL;

int EnVQueue(Vertex_Nodes *vertex){
    if(IsVQFull()==TRUE)return ERROR;
    VQnodes **rptr = &head;
    VQnodes *new = (VQnodes*)malloc(sizeof(VQnodes));
    new->vertex = vertex;
    new->next = NULL;
    while(*rptr!=NULL){
        rptr = &(*rptr)->next;
    }
    *rptr = new;
    return OK;
}

int DeVQueue(Vertex_Nodes **vertex){
    if(IsVQEmpty()==TRUE)return ERROR;
    VQnodes *temp = head;
    *vertex = temp->vertex;
    head = head->next;
    free(temp);
    return OK;
}

int IsVQEmpty(){
    return head == NULL;
}

int IsVQFull(){
    return FALSE;
}

#endif