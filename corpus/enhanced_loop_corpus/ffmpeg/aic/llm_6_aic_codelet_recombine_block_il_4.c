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
for (i = 0; i < 8; i++) {
    int16_t temp_base[4], temp_ext[4];
    for (j = 0; j < 4; j++) {
        temp_base[j] = (*base)[j];
        temp_ext[j] = (*ext)[j];
    }
    for (j = 0; j < 4; j++) {
        dst[scan[i * 8 + j]] = temp_base[j];
    }
    for (j = 0; j < 4; j++) {
        dst[scan[i * 8 + j + 4]] = temp_ext[j];
    }
    *base += 4;
    *ext += 4;
}
}
