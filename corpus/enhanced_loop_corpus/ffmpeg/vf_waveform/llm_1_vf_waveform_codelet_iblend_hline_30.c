#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int unroll_factor = 2;
    int remainder = width % (step * unroll_factor);
    // Handle main loop with unrolled iterations (simulating reduced loop depth via fusion)
    for (x = 0; x < width - remainder; x += step * unroll_factor) {
        dst[x]           = (v - dst[x])           * o1 + dst[x]           * o2;
        if (x + step < width) {
            dst[x + step] = (v - dst[x + step])   * o1 + dst[x + step]     * o2;
        }
    }
    // Cleanup remaining elements
    for (; x < width; x += step) {
        dst[x] = (v - dst[x]) * o1 + dst[x] * o2;
    }
}
