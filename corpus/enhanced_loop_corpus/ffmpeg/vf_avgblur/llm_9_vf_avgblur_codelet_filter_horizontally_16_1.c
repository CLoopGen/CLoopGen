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
extern  uint16_t *src;
extern float *ptr;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = slice_start; y < slice_end; y += 2) {
    float acc1 = 0, acc2 = 0;
    int count1 = 0, count2 = 0;
    src = (const uint16_t *)td->ptr + linesize * y;
    ptr = buffer + width * y;
    const uint16_t *src2 = (y + 1 < slice_end) ? (const uint16_t *)td->ptr + linesize * (y + 1) : src;
    float *ptr2 = (y + 1 < slice_end) ? buffer + width * (y + 1) : ptr;

    for (x = 0; x < radius; x++) {
        acc1 += src[x];
        if (y + 1 < slice_end) acc2 += src2[x];
    }
    count1 = count2 = radius;

    for (x = 0; x <= radius; x++) {
        acc1 += src[x + radius]; count1++;
        ptr[x] = acc1 / count1;
        if (y + 1 < slice_end && x + radius < width) {
            acc2 += src2[x + radius]; count2++;
            ptr2[x] = acc2 / count2;
        }
    }

    for (; x < width - radius; x++) {
        acc1 += src[x + radius] - src[x - radius - 1];
        ptr[x] = acc1 / count1;
        if (y + 1 < slice_end) {
            acc2 += src2[x + radius] - src2[x - radius - 1];
            ptr2[x] = acc2 / count2;
        }
    }

    for (; x < width; x++) {
        acc1 -= src[x - radius]; count1--;
        ptr[x] = acc1 / count1;
        if (y + 1 < slice_end && x - radius >= 0) {
            acc2 -= src2[x - radius]; count2--;
            ptr2[x] = acc2 / count2;
        }
    }
}
}
