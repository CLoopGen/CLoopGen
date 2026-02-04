#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern  uint8_t *scan;
extern int16_t **ext;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 64; k++) {
        int i = k / 8;
        int j = k % 8;
        dst[scan[i * 8 + j]] = (*ext)[j];
        if (j == 7) *ext += 8;
    }
}
