
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>



#include "queue.h"



#define NAME_LENGTH 3
#define MAXSIZE 25

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef  int  Status;
typedef  char VertexType;
typedef  uint8_t Boolean;

typedef struct EDGE
{
    int index;              //stores the vertex index of the which it connects
    struct EDGE *next;      //pointer which points to other vertex it connects
}Edge_Nodes;

typedef struct VERTEX
{
    VertexType *data;       //stores Vertex name in this trival case
    Edge_Nodes *first_edge; //stores the first edge of vertex  (v0,j0)
}Vertex_Nodes;

typedef struct GRAPH
{
    Vertex_Nodes *Vertex_Array[MAXSIZE];   //stores all the vertex in the graph
    int size;                        //stores the amount of vertex in the graph
}Graph;

static Boolean visited[MAXSIZE];

Graph *new_graph = NULL;

Status InitGraph(){
    int size = 0;
    int i,j;
    int index;
    char str[NAME_LENGTH];
    Edge_Nodes *temp;

    //initialize size of new graph
    new_graph = (Graph*)malloc(sizeof(Graph));
    printf("Please input the amount of vertex:");
    scanf("%d",&size);
    new_graph->size = size;

    //initialize vertex data
    printf("Please input the name of each Vertex\n");
    for(i = 0;i<size;i++){
        printf("Vertex[%d]:",i);
        scanf("%s",str);
        new_graph->Vertex_Array[i]=(Vertex_Nodes*)malloc(sizeof(Vertex_Nodes));
        new_graph->Vertex_Array[i]->data = (VertexType*)malloc(NAME_LENGTH*sizeof(VertexType));
        strncpy(new_graph->Vertex_Array[i]->data,str,NAME_LENGTH);
        new_graph->Vertex_Array[i]->first_edge = NULL;
    }

    //initialize edge data(adjacent information)
    printf("Please input the adjacent value for each (vi,vj)\n");
    for(j = 0;j<size;j++){
        printf("vertex[%d]-%s:",j,new_graph->Vertex_Array[j]->data);
        scanf("%d",&index);
        while(index!=-1){
            //head pointer to first_edge of this vertex
            Edge_Nodes **headj = &new_graph->Vertex_Array[j]->first_edge;
            //check if previous link exist,if exist will skip
            temp = *headj;
            while(temp!=NULL){
                if(temp->index == index)break;
                temp = temp->next;
            }
            if(temp == NULL)
            {
                //create edge nodes for current vertex index
                Edge_Nodes *new_edge_j=(Edge_Nodes*)malloc(sizeof(Edge_Nodes));
                new_edge_j->index = index;
                if(*headj == NULL)*headj = new_edge_j;
                else{
                    new_edge_j->next = *headj;
                    *headj = new_edge_j;
                }
                //create edge nodes for user defined vertex index
                Edge_Nodes *new_edge_i=(Edge_Nodes*)malloc(sizeof(Edge_Nodes));
                Edge_Nodes **headi = &new_graph->Vertex_Array[index]->first_edge;
                if(*headi == NULL)*headi = new_edge_i;
                else{
                    new_edge_i->next =*headi;
                    *headi = new_edge_i;
                }
            }  
            //let user create another edge or quit and go into next vertex
            printf("vertex[%d]-%s:",j,new_graph->Vertex_Array[j]->data);
            scanf("%d",&index);
        }
    }
    return OK;
}

Status DFS_Traverse(int index){

    if(visited[index]==FALSE){
        visited[index] = TRUE;
        Vertex_Nodes *vert_temp = new_graph->Vertex_Array[index];
        Edge_Nodes *edge_temp = vert_temp->first_edge; 
        printf("name:%s\t",vert_temp->data);
        while(edge_temp!=NULL){
            DFS_Traverse(edge_temp->index);
            edge_temp = edge_temp->next;
        }
    }
    return OK;
}

Status DFS(){
    int i,j;
    i = j = 0;
    while(i<new_graph->size){
        visited[i] = FALSE;
        i++;
    }
    printf("\nDFS:\t");
    while(j<new_graph->size){
        if(visited[j]==FALSE)DFS_Traverse(j);
        j++;
    }
    return OK;
}


Status BFS(){
    Vertex_Nodes *vert;
    Edge_Nodes *edge;

    for(int i = 0;i<new_graph->size;i++){
        visited[i] = FALSE;
    }

    vert = new_graph->Vertex_Array[0];
    EnVQueue(vert);
    visited[0] = TRUE;
    printf("\nBFS:\t");
    while(IsVQEmpty()==FALSE){
        DeVQueue(&vert);
        printf("name:%s\t",vert->data);
        edge = vert->first_edge;
        while(edge!=NULL){
            if(visited[edge->index]==FALSE){
                EnVQueue(new_graph->Vertex_Array[edge->index]);
                visited[edge->index] = TRUE;
            }
            edge = edge->next;
        }
    }

   
    return OK;
}


