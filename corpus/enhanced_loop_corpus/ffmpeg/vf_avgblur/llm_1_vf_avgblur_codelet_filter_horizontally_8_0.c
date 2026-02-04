#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ThreadData {
    int height;
    int width;
    uint8_t *ptr;
    int linesize;
} ThreadData;

extern ThreadData *td;
extern  int width;
extern  int slice_start;
extern  int slice_end;
extern  int radius;
extern  int linesize;
extern float *buffer;
extern  uint8_t *src;
extern float *ptr;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = slice_start; y < slice_end; y++) {
    float acc = 0;
    int count = 0;
    src = (const uint8_t *)td->ptr + linesize * y;
    ptr = buffer + width * y;

    // Unroll the first part: [0, radius)
    for (x = 0; x < radius; x++) {
        acc += src[x];
    }
    count = radius;

    // Second loop: [0, radius] inclusive — merge with previous accumulation
    for (x = 0; x <= radius; x++) {
        if (x == 0) {
            acc += src[radius];
            count++;
        } else {
            acc += src[x + radius] - src[x - 1]; // Compensate overlap in logic
            count++;
        }
        ptr[x] = acc / count;
    }

    // Middle sliding window: [radius+1, width-radius)
    for (; x < width - radius; x++) {
        acc += src[x + radius] - src[x - radius - 1];
        ptr[x] = acc / count;
    }

    // Final tail reduction
    for (; x < width; x++) {
        acc -= src[x - radius];
        count--;
        ptr[x] = acc / count;
    }
}
}
