#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *b_local = b;
    const BLASLONG stride = 8;
    for (ii = 0; ii < 4; ii++) {
        // Introduce temporary variables to break direct WAW and WAR dependencies on b
        float t0 = *(a01 + 0);
        float t1 = *(a01 + 1);
        float t2 = *(a02 + 0);
        float t3 = *(a02 + 1);
        float t4 = *(a03 + 0);
        float t5 = *(a03 + 1);
        float t6 = *(a04 + 0);
        float t7 = *(a04 + 1);

        // Store through temporaries — removes potential write-after-write hazards if b is aliased
        b_local[0] = t0;
        b_local[1] = t1;
        b_local[2] = t2;
        b_local[3] = t3;
        b_local[4] = t4;
        b_local[5] = t5;
        b_local[6] = t6;
        b_local[7] = t7;

        a01 += 2;
        a02 += 2;
        a03 += 2;
        a04 += 2;
        b_local += stride;
    }
}
