#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int pos;
extern char mx[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 8; k++) {
        if ((board[pos + delta[k]] == 3))
            continue;
        mx[pos + delta[k]] = 1;
    }
}
