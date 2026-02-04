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
    for (j = 21; j >= 0; j--) {
        k += band_size_long[i][j];
        band_index_long[i][j] = k;
    }
    band_index_long[i][22] = k;
    band_index_long[i][0] = 0;
    for (j = 1; j < 22; j++) {
        band_index_long[i][j] = band_index_long[i][j-1] + band_size_long[i][j-1];
    }
}
}
