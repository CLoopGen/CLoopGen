#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t band_size_long[9][22];
extern uint16_t band_index_long[9][23];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 9; i++) {
    k = 0;
    for (j = 0; j < 22; j += 2) {
        band_index_long[i][j] = k;
        k += band_size_long[i][j];
        if (j + 1 < 22) {
            band_index_long[i][j + 1] = k;
            k += band_size_long[i][j + 1];
        }
    }
    band_index_long[i][22] = k;
}
}
