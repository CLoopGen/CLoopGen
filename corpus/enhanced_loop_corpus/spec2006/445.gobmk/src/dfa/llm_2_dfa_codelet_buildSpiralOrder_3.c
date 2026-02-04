#include <stdio.h>

#include <inttypes.h>

extern  int generator[4];
extern int mark[7056];
extern int fifo[14112];
extern int top;
extern int k;
extern int ii;
extern int delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing generator sequentially, use a fixed stride (e.g., every second element, wrapping)
    int stride = 2;
    for (k = 0; k != 4; k++) {
        int idx = (k * stride) % 4;  // Strided access into generator
        delta = generator[idx];
        if (!mark[ii + delta]) {
            fifo[top] = ii + delta;
            mark[ii + delta] = 1;
            top++;
        }
    }
}
