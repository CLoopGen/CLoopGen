#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float alpha = 0.443506f;
    float beta = 0.3f;
    for (i = (i0 >> 1) + 1; i < (i1 >> 1) - 1; i++) {
        p[2 * i] += alpha * (p[2 * i - 1] + p[2 * i + 1]) +
                    beta * (p[2 * i - 3] + p[2 * i + 3]);
    }
}
