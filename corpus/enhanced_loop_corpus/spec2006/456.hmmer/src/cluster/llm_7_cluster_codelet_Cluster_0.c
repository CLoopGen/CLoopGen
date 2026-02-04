#include <stdio.h>

#include <inttypes.h>

extern int N;
extern int *coord;
extern int col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 1; col < N; col++) {
        coord[col] = coord[col - 1] + 1;
    }
    if (N > 0) {
        coord[0] = 0;
    }
}
