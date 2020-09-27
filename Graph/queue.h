
#ifndef _QUEUE_H
#define _QUEUE_H



typedef int Status;

typedef struct VERTEX Vertex_Nodes;


Status EnVQueue(Vertex_Nodes *vertex);

Status DeVQueue();

Status IsVQEmpty();

Status IsVQFull();

#endif
