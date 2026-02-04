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
    // Variant 2: Strided memory access — traverse columns first, then rows (column-major write)
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            (buf[i * pitch + j]) = (tmp[i * 4 + j] >> 1);
        }
    }
}
