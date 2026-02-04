#include <stdio.h>

#include <inttypes.h>

extern int N;
extern int *coord;
extern int col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = (N > 16) ? 4 : 1;
    for (col = 0; col < N; col++) {
        coord[col] = col * stride - (stride / 2);
        coord[col] += (col % 3) == 0 ? 1 : 0;
    }
}
