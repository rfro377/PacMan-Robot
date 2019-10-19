
#include "Astarpathfinding.h"

void Pathfinder (start_x,start_y,end_x,end_y){
    u = 15;
    z = 19;
    int y;
    int x;
    node up,down,left,right;
    node openList[u*z];
    node closedList[u][z];
    for( y=0; y < u; y++){
        for(x = 0; x < z; x++){
            closedList[y][x].data.x = 0;
            closedList[y][x].data.y = 0;
            closedList[y][x].data.f = 999;
            closedList[y][x].data.g = 999;
            closedList[y][x].data.h = 999;
            closedList[y][x].data.px = 0;
            closedList[y][x].data.py = 0;
        }
    }

    while (valid == 0){
        startloc.data.x = start_x;
        startloc.data.y = start_y;
        startloc.data.f = 0;
        startloc.data.g = 0;
        startloc.data.h = 0;
        startloc.data.px = 0;
        startloc.data.py = 0;

        endloc.data.x = end_x;
        endloc.data.y = end_y;

        if(map[startloc.data.y][startloc.data.x] == 1 || map[endloc.data.y][endloc.data.x] == 1){
            valid = 0;
        } else {
            valid = 1;
        }
    }
    openList[0] = startloc; 
    int founddest = 0;
    int a;
    int i;
    while (openList[0].data.x != -1 && founddest == 0){
        a = 1;
        for(i = 0;i<15*19;i++){
            if(openList[i].data.f < openList[a].data.f){
                a =i;
            } else if(openList[i].data.x == -1){
                break;
            }
        }

        node q = openList[a];
        openList[a].data.x = -1;

        up = q;
        up.data.y = up.data.y -1;
        up.data.f = 999;
        down = q;
        down.data.y = down.data.y +1;
        down.data.f = 999;
        left = q;
        left.data.x = left.data.x -1;
        left.data.f = 999;
        right = q;
        right.data.x = right.data.x +1;
        right.data.f = 999;

        if(up.data.y<0||map[up.data.y][up.data.x] == 1){
            up.data.x = -1; 
        }
        if(down.data.y>=u||map[down.data.y][down.data.x] == 1){
        down.data.x = -1; 
        }
        if(left.data.x<0||map[left.data.y][left.data.x] == 1){
        left.data.x = -1; 
        }
        if(right.data.y>=z||map[right.data.y][right.data.x] == 1){
        right.data.x = -1; 
        }

        node successors[4] = {up,down,left,right};
        int found = 0;
        int i;
        int b;
        for (i=0; i<4; i++){
            if(successors[i].data.x == -1){
            }else{
                successors[i].data.px = q.data.x;
                successors[i].data.py = q.data.y;

                if(successors[i].data.x == endloc.data.x && successors[i].data.y == endloc.data.y){
                    endloc.data.px=q.data.x;
                    endloc.data.py =q.data.y;
                    founddest = 1;
                    break;
                } else if (closedList[successors[i].data.y][successors[i].data.x].data.f == 999){
                    successors[i].data.g = q.data.g+1;
                    successors[i].data.h = (int) sqrt( ((successors[i].data.x-endloc.data.x)^2 + (successors[i].data.y - endloc.data.y)^2));
                    successors[i].data.f = successors[i].data.g+successors[i].data.h;
                    for (b = 0;b<15*19;b++){

                        if((openList[b].data.x == successors[i].data.x) && (openList[b].data.y == successors[i].data.y)){
                            found = 1;
                            if(openList[b].data.f>successors[i].data.f){
                                openList[b] = successors[i];
                            }
                        }
                    }
                }

                if (found == 0 && founddest != 1){
                    for (b = 0;b<15*19;b++){
                        if(openList[b].data.x == -1){
                            openList[b] = successors[i];
                            break;
                        }
                    }
                }
            }
        }
        closedList[q.data.y][q.data.x] = q;
    }
    printcur = endloc;
    createlinkedlist(path,printcur.data);
    while (printcur.data.x != startloc.data.x || printcur.data.y != startloc.data.y){
        addfirst(path,printcur.data);
        printcur = closedList[printcur.data.y][printcur.data.x];
        fprintf("%d $d",printcur.data.y,printcur.data.x);
    }

}