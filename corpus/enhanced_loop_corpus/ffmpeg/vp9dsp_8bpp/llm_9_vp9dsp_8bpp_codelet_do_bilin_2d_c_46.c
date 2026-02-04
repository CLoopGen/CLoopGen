#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mx;
extern uint8_t *tmp_ptr;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = w >> 1;
    for (x = 0; x < limit; x++) {
        int idx1 = x;
        int idx2 = w - 1 - x;
        tmp_ptr[idx1] = (src[idx1] + ((mx * (src[idx1 + 1] - src[idx1]) + 8) >> 4)) ^ 0x55;
        tmp_ptr[idx2] = (src[idx2] + ((mx * (src[idx2 + 1] - src[idx2]) + 8) >> 4)) ^ 0xAA;
    }
}
