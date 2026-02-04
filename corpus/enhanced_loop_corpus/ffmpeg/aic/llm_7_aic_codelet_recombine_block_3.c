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
        int16_t *ext_base = *ext;
        for (j = 0; j < 8; j++) {
            int idx = i * 8 + j;
            dst[scan[idx]] = ext_base[j];  // RAW dependency: each write depends on current ext_base[j]
            dst[scan[idx] + 1] += dst[scan[idx]];  // Introduce artificial WAW and WAR via read-after-write and write-after-write
        }
        *ext += 8;
    }
}
