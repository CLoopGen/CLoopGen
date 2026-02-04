#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern  uint8_t *scan;
extern int16_t **base;
extern int16_t **ext;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i++) {
    int block = i / 8;
    int offset = i % 8;
    if (offset < 4) {
        dst[scan[block * 8 + offset]] = (*base)[offset];
    } else {
        dst[scan[block * 8 + offset]] = (*ext)[offset - 4];
    }
    if (offset == 7) {
        *base += 4;
        *ext += 4;
    }
}
}
