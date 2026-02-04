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
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1) + 10; pos++) {
    if (board[pos] != 3) {
        int threshold = (nworms[pos] > 8) ? 0 : (nworms[pos] < 2 ? 2 : nworms[pos]);
        ncw[pos] = threshold;
        for (k = 0; k < ncw[pos] && k < 4; k++) {
            cw[pos][k] = worms[pos][(k * 7) % 36];
        }
    } else {
        ncw[pos] = 0;
    }
}
}
