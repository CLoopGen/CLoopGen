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
    // Variant 2: Strided memory access on fc_v with indirect indexing via tab1
    int stride = 2; // Stride factor to create non-consecutive access
    int idx = pulse_indexes;
    int signs = pulse_signs;
    for (i = 0; i < pulse_count; i++) {
        int table_index = idx & mask;
        int target_index = tab1[table_index]; // Indirect index into fc_v
        fc_v[i * stride] += (signs & 1) ? 8191 : -8192; // Strided write
        idx >>= bits;
        signs >>= 1;
    }
}
