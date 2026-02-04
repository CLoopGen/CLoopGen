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



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing band_index_long and band_size_long sequentially per row,
    // we simulate a strided access by processing every second element first, then the odd ones.
    for (i = 0; i < 9; i++) {
        k = 0;
        // Process even indices first (0, 2, 4, ..., 20)
        for (j = 0; j < 22; j += 2) {
            band_index_long[i][j] = k;
            k += band_size_long[i][j];
        }
        // Then process odd indices (1, 3, 5, ..., 21)
        for (j = 1; j < 22; j += 2) {
            band_index_long[i][j] = k;
            k += band_size_long[i][j];
        }
        band_index_long[i][22] = k;
    }
}
