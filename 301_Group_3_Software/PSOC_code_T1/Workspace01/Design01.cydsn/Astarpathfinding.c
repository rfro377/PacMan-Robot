
#include <Astarpathfinding.h>

void Pathfinder (start_x,start_y,end_x,end_y){
    u = 15;
    z = 19;
    int y;
    int x;
    for( y=0; y < u; y++){
        for(x = 0; x < z; x++){
            closedList[y][x].x = 0;
            closedList[y][x].y = 0;
            closedList[y][x].f = 999;
            closedList[y][x].g = 999;
            closedList[y][x].h = 999;
            closedList[y][x].px = 0;
            closedList[y][x].py = 0;
        }
    }

    while (valid == 0){
        startloc.x = start_x;
        startloc.y = start_y;
        startloc.f = 0;
        startloc.g = 0;
        startloc.h = 0;
        startloc.px = 0;
        startloc.py = 0;

        endloc.x = end_x;
        endloc.y = end_y;

        if(map[startloc.y][startloc.x] == 1 || map[endloc.y][endloc.x] == 1){
            valid = 0;
        } else {
            valid = 1;
        }
    }
    openList[0] = startloc; 
    int founddest = 0;
    int a;
    int i;
    while (openList[0].x != -1 && founddest == 0){
        a = 1;
        for(i = 0;i<15*19;i++){
            if(openList[i].f < openList[a].f){
                a =i;
            } else if(openList[i].x == -1){
                break;
            }
        }

        node q = openList[a];
        openList[a].x = -1;

        up = q;
        up.y = up.y -1;
        up.f = 999;
        down = q;
        down.y = down.y +1;
        down.f = 999;
        left = q;
        left.x = left.x -1;
        left.f = 999;
        right = q;
        right.x = right.x +1;
        right.f = 999;

        if(up.y<0||map[up.y][up.x] == 1){
            up.x = -1; 
        }
        if(down.y>=u||map[down.y][down.x] == 1){
        down.x = -1; 
        }
        if(left.x<0||map[left.y][left.x] == 1){
        left.x = -1; 
        }
        if(right.y>=z||map[right.y][right.x] == 1){
        right.x = -1; 
        }

        node_t successors[4] = {up,down,left,right};
        int found = 0;
        int i;
        int b;
        for (i=0; i<4; i++){
            if(successors[i].x == -1){
            }else{
                successors[i].px = q.x;
                successors[i].py = q.y;

                if(successors[i].x == endloc.x && successors[i].y == endloc.y){
                    endloc.px=q.x;
                    endloc.py =q.y;
                    founddest = 1;
                    break;
                } else if (closedList[successors[i].y][successors[i].x].f == 999){
                    successors[i].g = q.g+1;
                    successors[i].h = (int) sqrt( ((successors[i].x-endloc.x)^2 + (successors[i].y - endloc.y)^2));
                    successors[i].f = successors[i].g+successors[i].h;
                    for (b = 0;b<15*19;b++){

                        if((openList[b].x == successors[i].x) && (openList[b].y == successors[i].y)){
                            found = 1;
                            if(openList[b].f>successors[i].f){
                                openList[b] = successors[i];
                            }
                        }
                    }
                }

                if (found == 0 && founddest != 1){
                    for (b = 0;b<15*19;b++){
                        if(openList[b].x == -1){
                            openList[b] = successors[i];
                            break;
                        }
                    }
                }
            }
        }
        closedList[q.y][q.x] = q;
    }
    printcur = endloc;
    createlinkedlist(path,printcur);
    while (printcur.x != startloc.x || printcur.y != startloc.y){
        addfirst(path,printcur);
        printcur = closedList[printcur.y][printcur.x];
    }

}