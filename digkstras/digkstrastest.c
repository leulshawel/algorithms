#include "digkstras.h"



int main(){
    int numofnodes = 5;
    struct  Node* nodes[numofnodes]; //array to store the nodes to pass them to init

    //create some node 
    struct  Node asebe;
    struct  Node addis;
    struct  Node adama;
    struct  Node awash;
    struct  Node mojo;
    
    //give nodes name
    asebe.name = 'A';
    adama.name = 'N';
    awash.name = 'W';
    addis.name = 'S';
    mojo.name = 'M';

    //add the nodes to the array and pass to init
    //first in this array must be the startingNode
    nodes[0] = &asebe;
    nodes[1] = &adama;
    nodes[2] = &awash;
    nodes[3] = &mojo;
    nodes[4] = &addis;

    init(5, nodes);

    //create connections between nodes (should be done after init)
    asebe.nodes[0] = &adama; asebe.nodes[1] = &awash; mojo.nodes[0]  = &addis; adama.nodes[0] = &mojo; adama.nodes[1] = &addis;
    //set distance values ([i]th dist corresponds to [i]th connection)
    asebe.dist[0] = 260; asebe.dist[1] = 190; mojo.dist[0] = 10; adama.dist[0] = 50; adama.dist[1] = 65;

    //find shortest path. this doesnt return anything but sets the destination node's 
    //mydist value to the shortest distance from the startingNode 
    shortest(&asebe, &addis);
    printf("%d  ", addis.mydist); //print the shortest ditance of destination node
    return 0;
}

