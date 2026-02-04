#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern  uint8_t *scan;
extern int16_t **ext;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i += 2) {
        int16_t val = (*ext)[i % 64];
        dst[scan[i % 64]] = val;
        if (i + 1 < 128) {
            dst[scan[(i + 1) % 64]] = val;
        }
    }
}
