#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int pos;
extern int neighbors;
extern int k;
extern int delta[8];
extern Intersection board[421];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_neighbors = neighbors;
    for (k = 0; k < 4; k++) {
        Intersection val = board[pos + delta[k]];
        if (val != 3)
            temp_neighbors |= val;
    }
    neighbors = temp_neighbors;
}
