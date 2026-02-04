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
    int stride = 4;
    for (k = 0; k < 32; k++) {
        int index = (pos + delta[k % 8]) + (k / 8);
        if ((board[index] != 3))
            mx[index] = 1;
    }
}
