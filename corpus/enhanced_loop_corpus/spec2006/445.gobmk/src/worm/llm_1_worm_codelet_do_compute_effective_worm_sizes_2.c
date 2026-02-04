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
// Increase loop nesting depth by splitting the original loop into two levels where applicable
// Outer loop iterates over blocks or regions, inner handles individual positions

int start = (19 + 2);
int end = (19 + 1) * (19 + 1);
int block_size = 16;
for (int block_start = start; block_start < end; block_start += block_size) {
    for (pos = block_start; pos < end && pos < block_start + block_size; pos++) {
        if (!(board[pos] != 3))
            continue;
        if (nworms[pos] > 4)
            ncw[pos] = 0;
        else
            ncw[pos] = nworms[pos];
        for (k = 0; k < ncw[pos]; k++)
            cw[pos][k] = worms[pos][k];
    }
}
}
