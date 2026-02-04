#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    temp[8 * i + 0] = (src[stride * i + 0]) + (src[stride * i + 1]);
    temp[8 * i + 1] = (src[stride * i + 0]) - (src[stride * i + 1]);
    temp[8 * i + 2] = (src[stride * i + 2]) + (src[stride * i + 3]);
    temp[8 * i + 3] = (src[stride * i + 2]) - (src[stride * i + 3]);

    {
        int a = temp[8 * i + 0], b = temp[8 * i + 2];
        temp[8 * i + 0] = a + b;
        temp[8 * i + 2] = a - b;
    }
    {
        int a = temp[8 * i + 1], b = temp[8 * i + 3];
        temp[8 * i + 1] = a + b;
        temp[8 * i + 3] = a - b;
    }
}
}
