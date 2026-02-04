#include <stdio.h>

#include <inttypes.h>

extern int N;
extern int *coord;
extern int col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < N; col++) {
        if (col == N / 2) {
            continue;
        }
        coord[col] = col;
    }
}
