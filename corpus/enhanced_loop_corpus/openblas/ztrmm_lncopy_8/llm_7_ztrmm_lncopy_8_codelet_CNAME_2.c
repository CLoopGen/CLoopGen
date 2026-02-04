#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *a1 = ao1, *a2 = ao2, *a3 = ao3, *a4 = ao4;
    float *local_b = b;
    for (ii = 0; ii < 4; ii++) {
        *(local_b + 0) = *a1++;
        *(local_b + 1) = *a1++;
        *(local_b + 2) = *a2++;
        *(local_b + 3) = *a2++;
        *(local_b + 4) = *a3++;
        *(local_b + 5) = *a3++;
        *(local_b + 6) = *a4++;
        *(local_b + 7) = *a4++;
        local_b += 8;
    }
    ao1 = a1;
    ao2 = a2;
    ao3 = a3;
    ao4 = a4;
    b = local_b;
}
