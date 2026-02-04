#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern uint16_t *dst;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided but unrolled by factor of 2 for improved spatial access pattern
    uint16_t *d = dst;
    int limit = width - (width % (2 * step)); // Make divisible by 2*step
    for (x = 0; x < limit; x += 2 * step, d += 2 * step) {
        d[0] = (v - d[0]) * o1 + d[0] * o2;
        d[step] = (v - d[step]) * o1 + d[step] * o2;
    }
    // Handle remaining elements
    for (; x < width; x += step, d += step) {
        *d = (v - *d) * o1 + *d * o2;
    }
}
