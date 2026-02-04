#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t pitch;
extern int16_t tmp[64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — transpose the store order, writing column-wise instead of row-wise
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            (buf[i * pitch + j]) = (tmp[i * 8 + j] >> 1);
        }
    }
}
