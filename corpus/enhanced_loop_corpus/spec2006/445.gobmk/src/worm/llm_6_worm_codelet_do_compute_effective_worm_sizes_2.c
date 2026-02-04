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
    int temp_ncw;
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        if (!(board[pos] != 3))
            continue;
        temp_ncw = nworms[pos];
        if (temp_ncw > 4)
            ncw[pos] = 0;
        else
            ncw[pos] = temp_ncw;
        for (k = 0; k < ncw[pos]; k++)
            cw[pos][k] = worms[pos][k];
    }
}
