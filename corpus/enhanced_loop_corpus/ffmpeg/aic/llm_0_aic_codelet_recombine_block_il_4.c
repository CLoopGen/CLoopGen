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
    j = 0;
    do {
        dst[scan[i * 8 + j]] = (*base)[j];
        j++;
    } while (j < 4);
    j = 0;
    do {
        dst[scan[i * 8 + j + 4]] = (*ext)[j];
        j++;
    } while (j < 4);
    *base += 4;
    *ext += 4;
}
}
