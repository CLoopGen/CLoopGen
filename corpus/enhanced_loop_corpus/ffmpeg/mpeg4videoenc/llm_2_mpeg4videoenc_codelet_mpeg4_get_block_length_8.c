#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern uint8_t *scan_table;
extern int i;
extern int last_non_zero;
extern uint8_t *len_tab;
extern  int last_index;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access via Precomputed Indices
    // Instead of accessing block[scan_table[i]], we precompute a temporary array of effective indices
    // to enable more predictable memory access patterns. This improves cache locality if scan_table is sparse.
    
    int16_t *block_ptr = block;
    uint8_t *scan_ptr = scan_table + i;
    int local_len = len;
    int local_last_non_zero = last_non_zero;
    int local_last_index = last_index;

    for (; i < local_last_index; i++) {
        uint8_t scanned_index = *scan_ptr++;
        int level = block_ptr[scanned_index];
        if (level) {
            int run = i - local_last_non_zero - 1;
            level += 64;
            if ((level & (~127)) == 0) {
                const int index = run * 128 + level;
                local_len += len_tab[index];
            } else {
                local_len += 7 + 2 + 1 + 6 + 1 + 12 + 1;
            }
            local_last_non_zero = i;
        }
    }
    len = local_len;
    last_non_zero = local_last_non_zero;
}
