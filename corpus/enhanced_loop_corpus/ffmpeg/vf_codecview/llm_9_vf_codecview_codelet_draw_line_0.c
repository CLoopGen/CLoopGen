#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int ex;
extern int stride;
extern int color;
extern int x;
extern int y;
extern int fr;
extern int f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = ex >> 2;
    for (x = 0; x <= limit; x++) {
        y = (x * f) >> 18;  // Adjusted shift for reduced frequency
        fr = (x * f) & 262143;  // Mask adjusted for larger range due to lower shift
        int weight = (color * (262144 - fr)) >> 18;
        buf[y * stride + (x << 2)] += weight;
        if (fr && y + 1 < 256) {
            buf[(y + 1) * stride + (x << 2)] += (color * fr) >> 18;
        }
        // Unrolled additional operations with varying offsets
        if ((x << 2) + 1 <= ex) {
            buf[y * stride + (x << 2) + 1] += weight >> 1;
        }
        if ((x << 2) + 3 <= ex) {
            buf[y * stride + (x << 2) + 3] += weight >> 2;
        }
    }
}
