#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int x;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 4; x++) {
        int idx1 = x;
        int idx2 = x + 4;
        temp[idx1] = 2 * (src[idx1] + src[idx1 + stride]);
        temp[idx2] = 2 * (src[idx2] + src[idx2 + stride]);
        temp[idx1 + 7 * 8] = 2 * (src[idx1 + 7 * stride] + src[idx1 + 6 * stride]);
        temp[idx2 + 7 * 8] = 2 * (src[idx2 + 7 * stride] + src[idx2 + 6 * stride]);
    }
}
