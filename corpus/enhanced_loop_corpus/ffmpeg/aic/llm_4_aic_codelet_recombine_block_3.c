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
        if (i % 2 == 0) {
            for (j = 0; j < 8; j++)
                dst[scan[i * 8 + j]] = (*ext)[j];
            *ext += 8;
        } else {
            *ext += 8;
            continue;
        }
    }
}
