#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int (*cw)[4];
extern int *ncw;
extern int pos;
extern int worms[400][36];
extern int nworms[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Array Base Offset
    int base = 19 + 2;
    int limit = (19 + 1) * (19 + 1);
    for (pos = base; pos < limit; pos++) {
        if (!(board[pos] != 3))
            continue;
        if (nworms[pos] > 4)
            ncw[pos] = 0;
        else
            ncw[pos] = nworms[pos];
        int *worm_row = worms[pos];
        int count = ncw[pos];
        int (*cw_row)[4] = &cw[pos];
        for (k = 0; k < count; k++) {
            (*cw_row)[k] = worm_row[k];  // Sequential access in inner loop
        }
    }
}
