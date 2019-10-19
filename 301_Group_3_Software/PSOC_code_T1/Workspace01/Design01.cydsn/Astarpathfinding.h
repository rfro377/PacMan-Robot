/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef _MY_HEADER_H2_
#define _MY_HEADER_H2_
#include <stdio.h>
#include "linkedlist.h"
#include "map.h"
#include <math.h>

int valid = 0;
node closedList[15][19];
node openList[15*19];
node startloc;
node endloc;
node up;
node left;
node right;
node down;
node printcur;
 linkedlist* path;

int u,z;

void Pathfinder(int start_x, int start_y,int end_x,int end_y);

/* [] END OF FILE */
#endif /* _MY_HEADER_H2_ */
