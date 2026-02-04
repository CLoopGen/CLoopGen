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
    int16_t temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = (*ext)[i];
    }
    for (i = 0; i < 64; i++) {
        dst[scan[i]] = temp[i];
    }
}
