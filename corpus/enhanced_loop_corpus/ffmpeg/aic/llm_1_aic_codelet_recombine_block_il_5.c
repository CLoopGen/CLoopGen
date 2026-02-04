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
    for (int level = 0; level < 2; level++) {
        int offset = level * 32;
        for (i = 0; i < 32; i++) {
            int idx = offset + i;
            dst[scan[idx]] = (*ext)[idx];
        }
    }
}
