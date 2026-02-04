#include <stdio.h>

extern  int dims[3][3];
extern int i;



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D array access into a 1D pattern
    int *base = &dims[0][0];
    for (i = 0; i < 3; i++) {
        int offset = i * 3;
        base[offset + 0] = 256;
        base[offset + 1] = 256;
        base[offset + 2] = 128;
    }
}
