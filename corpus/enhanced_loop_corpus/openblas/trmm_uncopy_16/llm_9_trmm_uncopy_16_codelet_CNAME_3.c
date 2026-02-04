#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced computational intensity with smaller trip count and fewer operations
    BLASLONG limit = i / 4;
    for (ii = 0; ii < limit; ii++) {
        // Only update first four elements per iteration
        b[0] = *(a01 + 0);
        b[1] = *(a02 + 0);
        b[2] = *(a03 + 0);
        b[3] = *(a04 + 0);

        a01++;
        a02++;
        a03++;
        a04++;
        b += 4;
    }
}
