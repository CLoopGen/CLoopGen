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
for (i = 0; i < 16; i++) {
    int offset = stride * i;
    int t[8];

    t[0] = src[offset + 0] + src[offset + 1];
    t[1] = src[offset + 0] - src[offset + 1];
    t[2] = src[offset + 2] + src[offset + 3];
    t[3] = src[offset + 2] - src[offset + 3];
    t[4] = src[offset + 4] + src[offset + 5];
    t[5] = src[offset + 4] - src[offset + 5];
    t[6] = src[offset + 6] + src[offset + 7];
    t[7] = src[offset + 6] - src[offset + 7];

    {
        int a = t[0], b = t[2];
        t[0] = a + b; t[2] = a - b;
    }
    {
        int a = t[1], b = t[3];
        t[1] = a + b; t[3] = a - b;
    }
    {
        int a = t[4], b = t[6];
        t[4] = a + b; t[6] = a - b;
    }
    {
        int a = t[5], b = t[7];
        t[5] = a + b; t[7] = a - b;
    }

    {
        int a = t[0], b = t[4];
        t[0] = a + b; t[4] = a - b;
    }
    {
        int a = t[1], b = t[5];
        t[1] = a + b; t[5] = a - b;
    }
    {
        int a = t[2], b = t[6];
        t[2] = a + b; t[6] = a - b;
    }
    {
        int a = t[3], b = t[7];
        t[3] = a + b; t[7] = a - b;
    }

    for (int j = 0; j < 8; j++) {
        temp[8 * i + j] = t[j];
    }
}
}
