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
    for (x = 0; x < radius; x++) {
        acc += src[x];
    }
    count = radius;
    x = 0;
    for (; x <= radius; x++) {
        acc += src[x + radius];
        count++;
        ptr[x] = acc / count;
    }
    for (; x < width; x++) {
        if (x < width - radius) {
            acc += src[x + radius] - src[x - radius - 1];
            ptr[x] = acc / count;
        } else {
            acc -= src[x - radius];
            count--;
            ptr[x] = acc / count;
        }
    }
}
}
