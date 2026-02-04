#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t pitch;
extern int16_t tmp[16];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D access into a 1D stride
    int16_t *ptr = buf;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            ptr[j] = (tmp[i * 4 + j] >> 1);
        }
        ptr = (int16_t*)((char*)ptr + pitch * sizeof(int16_t)); // Advance by pitch in bytes
    }
}
