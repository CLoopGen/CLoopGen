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
    int offset = (i < 4) ? 0 : 4;
    int idx = i & 3;
    dst[scan[(i >> 2) * 8 + idx + offset]] = (*(i < 4 ? base : ext))[idx];
    if (i == 3) *base += 4;
    if (i == 7) *ext += 4;
}
}
