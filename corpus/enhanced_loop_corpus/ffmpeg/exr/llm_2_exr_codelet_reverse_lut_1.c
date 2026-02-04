#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bitmap;
extern uint16_t *lut;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access by precomputing bitmap indices and accessing sequentially
    uint8_t *bm = bitmap;
    uint16_t *table = lut;
    int index = k;
    for (i = 0; i < (1 << 16); i += 8) {
        uint8_t byte = (i < (1 << 16)) ? bm[i >> 3] : 0;
        for (int bit = 0; bit < 8 && (i + bit) < (1 << 16); ++bit) {
            int idx = i + bit;
            if ((idx == 0) || (byte & (1 << bit)))
                table[index++] = idx;
        }
    }
    k = index;
}
