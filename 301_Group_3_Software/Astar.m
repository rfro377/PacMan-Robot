map = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1;
    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1;
    1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1;
    1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1;
    1,0,1,0,1,0,0,0,1,1,1,0,1,1,1,1,1,0,1;
    1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1;
    1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1;
    1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1;
    1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1;
    1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1;
    1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1;
    1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1;
    1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1;
    1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1;
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1];

% white =1 black = 0
valid =0;
f1 = figure;
hold on
data = imread('practice_maze_2018.jpg');
imshow(data)
[u,z] = size(map);
for y = 1:u
    for x = 1:z
        closedlist(y,x).x = 0;
        closedlist(y,x).y = 0;
        closedlist(y,x).f = 999;
        closedlist(y,x).g = 999;
        closedlist(y,x).h = 999;
        closedlist(y,x).px = 0;
        closedlist(y,x).py =0;
    end
end

while valid == 0
startloc.x = input('add start location x');
startloc.y = input('add start location y');
startloc.f = 0;
startloc.g = 0;
startloc.h = 0;
startloc.px = 0;
startloc.py=0;

endloc.x = input('add end location x');
endloc.y = input('add end location y');

if (map(startloc.y,startloc.x) == 1 || map(endloc.y,endloc.x) == 1)
    valid = 0;
else
    valid = 1;
end

end
openlist = [startloc];
foundDest = 0;
ll=1;
while isempty(openlist) == 0 && foundDest == 0
    fprintf('%d\n',ll);
    a=1;
        for x = 1:length(openlist)
            if openlist(x).f < openlist(a).f
               a=x;
            end
        end
    
    q = openlist(a);
    openlist(a)=[];
    
    up = q;
    up.y = up.y - 1;
    up.f = 999;
    down = q;
    down.y = down.y + 1;
    down.f = 999;
    left = q;
    left.x = left.x - 1;
    left.f = 999;
    right = q;
    right.x = right.x + 1;
    right.f = 999;
    
         if (up.y <1||map(up.y,up.x)==1)
        up = [];
         end
         if (down.y > u||map(down.y,down.x)==1)
            down = [];
         end
         if (left.x < 1||map(left.y,left.x)==1)
            left = [];
         end
         if (right.x > z||map(right.y,right.x)==1)
            right = [];
         end
     successors = [up,down,left,right];
    p = length(successors);
    for i = 1:p
       if(map(successors(i).y,successors(i).x) == 1)
       else
           successors(i).px = q.x;
           successors(i).py = q.y;

           if (successors(i).x == endloc.x && successors(i).y == endloc.y)
               endloc.px = q.x;
               endloc.py = q.y;
               foundDest = 1;
               break;
           elseif closedlist(successors(i).y,successors(i).x).f == 999
               successors(i).g  = q.g + 1;
                successors(i).h = sqrt((successors(i).x - endloc.x)^2+ (successors(i).y - endloc.y)^2);
                successors(i).f = successors(i).g + successors(i).h;
                found = 0;
                for b = 1: length(openlist)
                    
                    if((openlist(b).x == successors(i).x) && (openlist(b).y == successors(i).y))
                        found = 1;
                        if openlist(b).f > successors(i).f
                        openlist(b) = successors(i);
                        end
                    end
                    
                end
         
                
           end
           
           
                if found == 0 && foundDest ~= 1
                    openlist = [openlist,successors(i)];
                end
       end
           
       
    end
    closedlist(q.y,q.x) = q;
    ll=ll+1;
end
printcur = endloc;
prevx = endloc.x;
prevy = endloc.y;
while(printcur.x ~= startloc.x||printcur.y ~= startloc.y)
   fprintf("(%d,%d)<---\n",printcur.x,printcur.y);
   line(63*[prevx,printcur.x],65*[prevy,printcur.y],'Color','g','lineWidth',2);
   prevx = printcur.x;
   prevy = printcur.y;
   printcur = closedlist(printcur.py,printcur.px);
end
line(63*[prevx,printcur.x],65*[prevy,printcur.y],'Color','g','lineWidth',2);

