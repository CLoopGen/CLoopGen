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
for (i = 0; i < 8; i++) {
    int idx[8];
    for (int j = 0; j < 8; j++) {
        idx[j] = 8 * i + j;
    }

    int src_idx[8];
    for (int j = 0; j < 8; j++) {
        src_idx[j] = stride * i + j;
    }

    temp[idx[0]] = src[src_idx[0]] + src[src_idx[1]];
    temp[idx[1]] = src[src_idx[0]] - src[src_idx[1]];
    temp[idx[2]] = src[src_idx[2]] + src[src_idx[3]];
    temp[idx[3]] = src[src_idx[2]] - src[src_idx[3]];
    temp[idx[4]] = src[src_idx[4]] + src[src_idx[5]];
    temp[idx[5]] = src[src_idx[4]] - src[src_idx[5]];
    temp[idx[6]] = src[src_idx[6]] + src[src_idx[7]];
    temp[idx[7]] = src[src_idx[6]] - src[src_idx[7]];

    {
        int a = temp[idx[0]], b = temp[idx[2]];
        temp[idx[0]] = a + b;
        temp[idx[2]] = a - b;
    }
    {
        int a = temp[idx[1]], b = temp[idx[3]];
        temp[idx[1]] = a + b;
        temp[idx[3]] = a - b;
    }
    {
        int a = temp[idx[4]], b = temp[idx[6]];
        temp[idx[4]] = a + b;
        temp[idx[6]] = a - b;
    }
    {
        int a = temp[idx[5]], b = temp[idx[7]];
        temp[idx[5]] = a + b;
        temp[idx[7]] = a - b;
    }
    {
        int a = temp[idx[0]], b = temp[idx[4]];
        temp[idx[0]] = a + b;
        temp[idx[4]] = a - b;
    }
    {
        int a = temp[idx[1]], b = temp[idx[5]];
        temp[idx[1]] = a + b;
        temp[idx[5]] = a - b;
    }
    {
        int a = temp[idx[2]], b = temp[idx[6]];
        temp[idx[2]] = a + b;
        temp[idx[6]] = a - b;
    }
    {
        int a = temp[idx[3]], b = temp[idx[7]];
        temp[idx[3]] = a + b;
        temp[idx[7]] = a - b;
    }
}
}
