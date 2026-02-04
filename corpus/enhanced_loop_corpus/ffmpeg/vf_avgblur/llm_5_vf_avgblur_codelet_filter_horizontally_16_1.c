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
for (y = slice_start; y < slice_end; y++) {
    float acc = 0;
    int count = 0;
    src = (const uint16_t *)td->ptr + linesize * y;
    ptr = buffer + width * y;

    x = 0;
    if (radius == 0) {
        for (; x < width; x++) {
            acc += src[x];
            ptr[x] = acc / (x + 1);
        }
    } else {
        for (; x < radius; x++) {
            acc += src[x];
        }
        count = radius;

        for (; x <= radius && x < width; x++) {
            acc += src[x + radius];
            count++;
            ptr[x] = acc / count;
        }

        for (; x < width - radius; x++) {
            acc += src[x + radius] - src[x - radius - 1];
            ptr[x] = acc / count;
        }

        for (; x < width; x++) {
            ptr[x] = acc / count;
            acc -= src[x - radius];
            count--;
        }
    }
}
}
