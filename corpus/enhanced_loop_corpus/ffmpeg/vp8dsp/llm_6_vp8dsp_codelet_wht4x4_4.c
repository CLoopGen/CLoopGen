#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int a1 = coef[i * 4 + 0];
    int b1 = coef[i * 4 + 1];
    int c1 = coef[i * 4 + 2];
    int d1 = coef[i * 4 + 3];
    int e1;
    // Introduce artificial dependency: make 'a1' depend on previous iteration via loop-carried reuse
    if (i > 0) {
        a1 += coef[(i-1) * 4 + 0];  // RAW dependency across iterations
    }
    e1 = (a1 + b1 - (d1 - c1)) >> 1;
    b1 = e1 - b1;
    c1 = e1 - c1;
    a1 = (a1 - c1) * 2;
    d1 = (d1 + b1) * 2;
    c1 *= 2;
    b1 *= 2;
    // Reorder stores to create WAW hazard potential (though not exploited here)
    coef[i * 4 + 1] = b1;
    coef[i * 4 + 2] = c1;
    coef[i * 4 + 0] = a1;
    coef[i * 4 + 3] = d1;
}
}
