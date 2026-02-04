#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order and stride of 1 across transformed index
    int16_t *c = coef;
    for (i = 3; i >= 0; i--) {
        const int idx = i;
        const int a1 = c[0*4 + idx] + c[3*4 + idx];
        const int b1 = c[1*4 + idx] + c[2*4 + idx];
        const int c1 = c[1*4 + idx] - c[2*4 + idx];
        const int d1 = c[0*4 + idx] - c[3*4 + idx];
        c[0*4 + idx] = (a1 + b1 + 7) >> 4;
        c[1*4 + idx] = ((c1 * 2217 + d1 * 5352 + 12000) >> 16) + !!d1;
        c[2*4 + idx] = (a1 - b1 + 7) >> 4;
        c[3*4 + idx] = (d1 * 2217 - c1 * 5352 + 51000) >> 16;
    }
}
