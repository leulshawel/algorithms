#include <stdio.h>
#define MAXNODE 10 //maximum number of nodes a node can connect with




//a node structure to represent a single node
struct Node{
    char name;                  //Name of this node
    unsigned int mydist;         //distance of this node from the starting node
    struct Node* nodes[MAXNODE]; //the next nodes connected to this node
    unsigned int dist[MAXNODE];  //the distance between this node and the [i]th node connected to it
    
}; 


//initialization of nodes
//the firts in the nodes array has to be the starting node
//the remaining nodes can come in any order in the node array
void init(int argc, struct Node* nodes[]){
    struct Node** node = nodes;
    //loop though all the nodes in the array
    for (; node < nodes + argc; node++){
        //set the initial distance of nodes from the starting node to infinity
        (*node)->mydist = 0x7fffffff;   
        //Initialize nodes array to zero to avoid segmentation fault (due to junk values in memory)
        for (int i=0; i < MAXNODE; i++) {
            (*node)->nodes[i] = NULL;  
            (*node)->dist[i] = 0x0;  

        } 
    }
    nodes[0]->mydist = 0; //the starting node has a distance of 0 from itself
}



void shortest(struct Node* startingNode, struct Node* dest){
    int dist;
    struct Node* currentNode;
    //loop though all the node connected to this node
    for (int i=0; i < MAXNODE; i++){
        currentNode = startingNode->nodes[i];
        //if node pointer is null then continue
        if (!currentNode) continue; 
        //calculate the distance of currentNode from the original startingNode 
        dist = startingNode->dist[i];
        dist += startingNode->mydist;
        //set the distance from the original startingNode to dist if dist is smaller
        if (dist < currentNode->mydist) 
            currentNode->mydist = dist;
    }
    
    //do the exact same this on all the nodes connected to this node and the ones connected to tem
    //and the ones connected to the ones connected to them...you get the idea recurssion
    //except for the destination and null node pointers
    for (int i=0; i < MAXNODE; i++){
        currentNode = startingNode->nodes[i];
        if (currentNode != NULL && currentNode != dest) shortest(currentNode, dest);
    }
   
}
