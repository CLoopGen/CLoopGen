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
    for (; i < 4; i++) {
        int16_t *ext_row = (*ext);
        for (j = 0; j < 8; j++) {
            dst[scan[i * 8 + j]] = ext_row[j];
            dst[scan[(i + 4) * 8 + j]] = ext_row[j + 8]; // process two rows at once
        }
        *ext += 16; // advance by 16 to account for dual row processing
    }
}
