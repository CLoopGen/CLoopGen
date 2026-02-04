#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char goal[400];
extern int ii;
extern int mx[400];
extern int queue[361];
extern int queue_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride to traverse non-consecutive elements
    int stride = 3;
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii += stride)
        if ((board[ii] != 3) && goal[ii])
            (queue[queue_end++] = (ii), mx[ii] = 1);
}
