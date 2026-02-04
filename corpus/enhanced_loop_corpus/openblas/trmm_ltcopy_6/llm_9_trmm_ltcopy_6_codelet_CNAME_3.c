#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced computational intensity with smaller trip count and fewer memory operations
    BLASLONG limit = i / 2;
    for (ii = 0; ii < limit; ii++) {
        // Only write two elements per iteration instead of four
        b[0] = ao1[0];
        b[1] = ao1[1];
        b += 2;
        ao1 += 2;
    }
}
