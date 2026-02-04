#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    temp[8 * i + 0] = (src[stride * i + 0] - dst[stride * i + 0]) + (src[stride * i + 1] - dst[stride * i + 1]);
    temp[8 * i + 1] = (src[stride * i + 0] - dst[stride * i + 0]) - (src[stride * i + 1] - dst[stride * i + 1]);
    temp[8 * i + 2] = (src[stride * i + 2] - dst[stride * i + 2]) + (src[stride * i + 3] - dst[stride * i + 3]);
    temp[8 * i + 3] = (src[stride * i + 2] - dst[stride * i + 2]) - (src[stride * i + 3] - dst[stride * i + 3]);
    temp[8 * i + 4] = (src[stride * i + 4] - dst[stride * i + 4]) + (src[stride * i + 5] - dst[stride * i + 5]);
    temp[8 * i + 5] = (src[stride * i + 4] - dst[stride * i + 4]) - (src[stride * i + 5] - dst[stride * i + 5]);
    temp[8 * i + 6] = (src[stride * i + 6] - dst[stride * i + 6]) + (src[stride * i + 7] - dst[stride * i + 7]);
    temp[8 * i + 7] = (src[stride * i + 6] - dst[stride * i + 6]) - (src[stride * i + 7] - dst[stride * i + 7]);

    int a0 = temp[8 * i + 0], b0 = temp[8 * i + 2];
    temp[8 * i + 0] = a0 + b0;
    temp[8 * i + 2] = a0 - b0;

    int a1 = temp[8 * i + 1], b1 = temp[8 * i + 3];
    temp[8 * i + 1] = a1 + b1;
    temp[8 * i + 3] = a1 - b1;

    int a4 = temp[8 * i + 4], b4 = temp[8 * i + 6];
    temp[8 * i + 4] = a4 + b4;
    temp[8 * i + 6] = a4 - b4;

    int a5 = temp[8 * i + 5], b5 = temp[8 * i + 7];
    temp[8 * i + 5] = a5 + b5;
    temp[8 * i + 7] = a5 - b5;

    int a = temp[8 * i + 0], b = temp[8 * i + 4];
    temp[8 * i + 0] = a + b;
    temp[8 * i + 4] = a - b;

    a = temp[8 * i + 1]; b = temp[8 * i + 5];
    temp[8 * i + 1] = a + b;
    temp[8 * i + 5] = a - b;

    a = temp[8 * i + 2]; b = temp[8 * i + 6];
    temp[8 * i + 2] = a + b;
    temp[8 * i + 6] = a - b;

    a = temp[8 * i + 3]; b = temp[8 * i + 7];
    temp[8 * i + 3] = a + b;
    temp[8 * i + 7] = a - b;
}
}
