#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with combined pixel processing and simplified logic
    for (; i <= size - 8; i += 8) {
        // Process two pixels at once with reduced branching and shared computation
        int avg_r = ((r + last[i + 0]) >> 1) + src[i + 0];
        int avg_g = ((g + last[i + 1]) >> 1) + src[i + 1];
        int avg_b = ((b + last[i + 2]) >> 1) + src[i + 2];
        int avg_a = ((a + last[i + 3]) >> 1) + src[i + 3];

        dst[i + 0] = r = avg_r & 255;
        dst[i + 1] = g = avg_g & 255;
        dst[i + 2] = b = avg_b & 255;
        dst[i + 3] = a = avg_a & 255;

        // Reuse computed values for next pixel with minor adjustment
        dst[i + 4] = r = ((r + last[i + 4]) >> 1) + src[i + 4] & 255;
        dst[i + 5] = g = ((g + last[i + 5]) >> 1) + src[i + 5] & 255;
        dst[i + 6] = b = ((b + last[i + 6]) >> 1) + src[i + 6] & 255;
        dst[i + 7] = a = ((a + last[i + 7]) >> 1) + src[i + 7] & 255;
    }
}
