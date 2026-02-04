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
    for (i = (i0 >> 1); i < (i1 >> 1); i++) {
        if (2*i - 1 < 0 || 2*i + 1 >= (ptrdiff_t)(-i0 + i1)*2) continue;
        float left = p[2 * i - 1];
        float right = p[2 * i + 1];
        p[2 * i] += 0.443506f * (left + right);
    }
}
