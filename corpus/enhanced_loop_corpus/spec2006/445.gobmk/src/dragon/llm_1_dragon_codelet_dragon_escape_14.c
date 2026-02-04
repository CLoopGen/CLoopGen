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
    int outer_start = (19 + 2) / 10;
    int outer_end = ((19 + 1) * (19 + 1)) / 10 + 1;
    int inner_start, inner_end;
    for (int jj = outer_start; jj < outer_end; jj++) {
        inner_start = (jj == (19 + 2)/10) ? (19 + 2) : jj * 10;
        inner_end = (jj * 10 + 10 < (19 + 1)*(19 + 1)) ? jj * 10 + 10 : (19 + 1)*(19 + 1);
        for (ii = inner_start; ii < inner_end; ii++)
            if ((board[ii] != 3) && goal[ii])
                (queue[queue_end++] = (ii), mx[ii] = 1);
    }
}
