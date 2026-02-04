#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t dpitch;
extern  int16_t *ref_buf;
extern ptrdiff_t pitch;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (k = 0; k < 64; k++) {
        int i_index = k >> 3;
        int j_index = k & 7;
        ((int16_t*)((char*)buf + i_index * dpitch))[j_index] = ((int16_t*)((char*)ref_buf + i_index * pitch))[j_index];
    }
}
