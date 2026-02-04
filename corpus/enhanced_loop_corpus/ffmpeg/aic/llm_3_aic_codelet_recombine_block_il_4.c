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
    // Variant 2: Strided memory access pattern with reversed inner loop order
    int16_t *local_base = *base;
    int16_t *local_ext = *ext;
    for (i = 0; i < 8; i++) {
        for (j = 3; j >= 0; j--) {
            dst[scan[i * 8 + j]] = local_base[j];
        }
        for (j = 3; j >= 0; j--) {
            dst[scan[i * 8 + j + 4]] = local_ext[j];
        }
        local_base += 4;
        local_ext += 4;
    }
    *base = local_base;
    *ext = local_ext;
}
