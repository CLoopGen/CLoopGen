#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *fc_v;
extern  uint8_t *tab1;
extern int pulse_indexes;
extern int pulse_signs;
extern int pulse_count;
extern int bits;
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed indices
    int16_t *fc_v_base = fc_v;
    uint8_t *tab1_base = tab1;
    int idx = pulse_indexes;
    int signs = pulse_signs;
    for (i = 0; i < pulse_count; i++) {
        int offset = idx & mask;
        fc_v_base[i] += (signs & 1) ? 8191 : -8192;
        idx >>= bits;
        signs >>= 1;
    }
}
