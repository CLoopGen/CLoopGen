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
    for (i = 0; i < 16; i++) {
        int idx = i >> 2;
        j = i & 3;
        (buf[idx * dpitch + j]) = ((ref_buf[idx * pitch + j] + ref_buf[idx * pitch + j + 1]) >> 1);
    }
}
