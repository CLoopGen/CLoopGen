#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char goal[400];
extern char active[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int start = 20;
int end = 361;
int stride = 2;
for (pos = start; pos < end; pos += stride) {
    if ((board[pos] != 3) && (pos < 400)) {
        active[pos] = (goal[pos] != 0);
    }
    if ((pos + 1) < end && (pos + 1) < 400 && board[pos + 1] != 3) {
        active[pos + 1] = (goal[pos + 1] != 0);
    }
}
}
