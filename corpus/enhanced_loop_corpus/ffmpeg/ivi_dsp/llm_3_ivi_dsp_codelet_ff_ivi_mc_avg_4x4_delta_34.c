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
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    ptrdiff_t indices[4] = {0, pitch, 2*pitch, 3*pitch};
    for (j = 0; j < 4; j++) {
        int16_t *base = buf;
        for (i = 0; i < 4; i++) {
            (base[indices[i] + j]) += (tmp[i * 4 + j] >> 1);
        }
    }
}
