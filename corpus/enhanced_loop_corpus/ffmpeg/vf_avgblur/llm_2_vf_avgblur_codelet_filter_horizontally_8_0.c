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
        acc += src[x * 2]; // Strided access: step by 2
    }
    count += radius;
    for (x = 0; x <= radius; x++) {
        acc += src[(x + radius) * 2];
        count++;
        ptr[x] = acc / count;
    }
    for (; x < width - radius; x++) {
        acc += src[(x + radius) * 2] - src[(x - radius - 1) * 2];
        ptr[x] = acc / count;
    }
    for (; x < width; x++) {
        acc -= src[(x - radius) * 2];
        count--;
        ptr[x] = acc / count;
    }
}
}
