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
int16_t *base_local = *base;
int16_t *ext_local = *ext;
for (i = 0; i < 8; i++) {
    for (j = 0; j < 4; j++) {
        dst[scan[i * 8 + j]] = base_local[j];
    }
    for (j = 0; j < 4; j++) {
        dst[scan[i * 8 + j + 4]] = ext_local[j];
    }
    base_local += 4;
    ext_local += 4;
}
*base = base_local;
*ext = ext_local;
}
