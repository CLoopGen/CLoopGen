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
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++)
        dst[scan[i * 8 + j]] = (*base)[j];
    for (j = 0; j < 4; j++)
        dst[scan[i * 8 + j + 4]] = (*ext)[j];
    *base += 4;
    *ext += 4;
}

}
