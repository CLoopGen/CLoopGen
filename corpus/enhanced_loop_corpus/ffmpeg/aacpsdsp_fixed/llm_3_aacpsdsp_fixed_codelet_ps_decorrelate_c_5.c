#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT g_decay_slope;
extern  INTFLOAT a[];
extern INTFLOAT ag[3];
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive and offset-based access using pointer arithmetic
    INTFLOAT *pa = a;
    INTFLOAT *pag = ag;
    for (m = 0; m < 3; m++) {
        pag[m] = (int)(((int64_t)(*(pa + m)) * g_decay_slope + 536870912) >> 30);
    }
}
