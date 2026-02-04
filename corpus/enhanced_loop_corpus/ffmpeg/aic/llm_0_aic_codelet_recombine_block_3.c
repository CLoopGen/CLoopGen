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
    for (; i < 8; i++) {
        dst[scan[i * 8 + 0]] = (*ext)[0];
        dst[scan[i * 8 + 1]] = (*ext)[1];
        dst[scan[i * 8 + 2]] = (*ext)[2];
        dst[scan[i * 8 + 3]] = (*ext)[3];
        dst[scan[i * 8 + 4]] = (*ext)[4];
        dst[scan[i * 8 + 5]] = (*ext)[5];
        dst[scan[i * 8 + 6]] = (*ext)[6];
        dst[scan[i * 8 + 7]] = (*ext)[7];
        *ext += 8;
    }
}
