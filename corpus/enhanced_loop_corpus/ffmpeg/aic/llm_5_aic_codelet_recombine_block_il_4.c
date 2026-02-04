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
        int offset = i * 8;
        for (j = 0; j < 8; j++) {
            if (j < 4)
                dst[scan[offset + j]] = (*base)[j];
            else
                dst[scan[offset + j]] = (*ext)[j - 4];
        }
        *base += 4;
        *ext += 4;
    }
}
