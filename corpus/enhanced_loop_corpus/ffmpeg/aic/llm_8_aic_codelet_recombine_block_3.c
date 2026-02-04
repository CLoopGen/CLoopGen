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
        int16_t *ext_ptr = (*ext);
        for (j = 0; j < 8; j += 2) {
            int index1 = i * 8 + j;
            int index2 = index1 + 1;
            dst[scan[index1]] = ext_ptr[j];
            if (j + 1 < 8) dst[scan[index2]] = ext_ptr[j + 1];
        }
        *ext += 8;
    }
}
