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
#include <linkedlist.h>
#include <map.h>
#include <math.h>

int valid = 0;
node_t closedList[15][19];
node_t openList[15*19];
node_t startloc;
node_t endloc;
node_t up;
node_t left;
node_t right;
node_t down;
node_t printcur;
 linkedlist* path;

int u,z;

void Pathfinder(int start_x, int start_y,int end_x,int end_y);

/* [] END OF FILE */
#endif /* _MY_HEADER_H2_ */
