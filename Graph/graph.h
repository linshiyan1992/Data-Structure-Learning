/*
** 1.It's  an implementation of Undirected Graph Without Weight
** 2.Edges of graph is stored using adjacent table and linked list and Vertex ** information is stored in an 1-D Array
** 3.There are 2 traverse method use in this file,one is DFS(Depth-First-Search)
** and the other one is BFS(Breadth-First-Search)
** 4.The BFS method is implemented with queue structure which defines in other ** header file
*/

#ifndef _GRAPH_H_
#define _GRAPH_H_


typedef int Status;

/*
** Graph Initialization
** Return True if Initialize successfully
** Return False if instead
*/
Status InitGraph();

/*
** Depth First Search Alogrithm for traversing Graph
*/
Status DFS();

/*
** Breadth First Search Alogrithm for traversing Graph
*/
Status BFS();

#endif
