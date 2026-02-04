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
    // Variant 2: Strided Memory Access - Process every 2nd element forward and backward recovery
    int start = 19 + 2;
    int end = (19 + 1) * (19 + 1);
    int stride = 2;
    // First pass: strided access
    for (pos = start; pos < end; pos += stride) {
        if (!(board[pos] != 3))
            continue;
        if (nworms[pos] > 4)
            ncw[pos] = 0;
        else
            ncw[pos] = nworms[pos];
        for (k = 0; k < ncw[pos]; k += 1) {
            cw[pos][k] = worms[pos][k];  // Direct but within strided outer loop
        }
    }
    // Second pass: fill in the strided gaps (remaining indices)
    for (pos = start + 1; pos < end; pos += stride) {
        if (!(board[pos] != 3))
            continue;
        if (nworms[pos] > 4)
            ncw[pos] = 0;
        else
            ncw[pos] = nworms[pos];
        for (k = 0; k < ncw[pos]; k += 1) {
            cw[pos][k] = worms[pos][k];
        }
    }
}
