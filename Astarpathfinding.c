
#include "stdio.h"

struct Node
{
    int x;
    int y;
    int score;
    int distfromstart;
    int esttoend;
};
// the struct node is a place holder for our Linked List
struct Node Open[100] = {NULL};
struct Node Closed[100] = {NULL};
struct Node startNode = {0,0,0,0,0};
struct Node endNode = {0,0,0,0,0};
struct Node up,down,left,right = {0,0,0,0,0};
struct Node currentNode = {0,0,0,0,0};

// variables used to check state of lists
int emptyOpen = 0;
int destreached = 0;


int main (){

Open[0] = startNode; // Loads startPos into Open List

while(emptyOpen.size() != 0){ // checks if Open List is not empty
//used to find node with the lowest score
int curlowestf = 0;

// loops to find the node in Open with the lowest score f.
for (int i = 0;i<Open.size();i++){
    if(Open[i].f <Open[curlowestf].f ){
        curlowestf = i;
    }
}
//current node is the node with lowest f
currentNode = Open[curlowestf];
//remove curr node from the Open List and add to the Closed List
Open.remove[curlowestf];
Closed.add[curlowestf];

// checks if we have reached the end destination. checks the Closed list
for(int i = 0;i<Closed.size(); i++){
    if(Closed[i] == endNode){
        destreached = 1;
    }
}
//if we found destination exit loop
if(destreached == 1) {break;}

//get all adjacent squares
struct Node adjacentsquares = {up,down,left,right}

/*d) for each square in adjacent squares
        i) if square is the goal, stop search
          square.g = currentNode.g + distance between square and currentNode
          square.h = distance from goal to square 
          
          square.f = square.g + square.h

        ii) if a node with the same position as 
            square is in the OPEN list which has a 
           lower f than square, skip this square

        iii) if a node with the same position as 
            square is in the CLOSED list which has
            a lower f than square, skip this square
            
        iv) else add  the node to the open list
     end (for loop)

*/
closed.add(currentNode);

}

return 0;

}