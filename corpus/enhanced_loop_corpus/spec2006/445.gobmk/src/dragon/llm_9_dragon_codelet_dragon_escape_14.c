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
int base = 19 + 2;
int limit = (19 + 1) * (19 + 1);
for (ii = base; ii < limit; ii++) {
    int offset = ii + 100;
    if ((board[ii] != 3) && goal[ii] && (board[offset % 421] == 0))
        (queue[queue_end++] = ii, mx[ii] = 1);
}
}
