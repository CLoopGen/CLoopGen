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
    // Variant 2: Strided Memory Access with Unrolling (Factor of 2)
    // Process two iterations per loop step to create strided access pattern.
    // This increases instruction-level parallelism and changes memory stride behavior.
    
    int16_t *block_base = block;
    uint8_t *scan_base = scan_table;
    int local_i = i;
    int local_len = len;
    int local_last_non_zero = last_non_zero;

    int unroll_factor = 2;
    int remainder = (last_index - local_i) % unroll_factor;
    int main_loop_end = local_i + (last_index - local_i) / unroll_factor * unroll_factor;

    // Main unrolled loop with stride-like access
    for (; local_i < main_loop_end; local_i += unroll_factor) {
        // Process two elements per iteration
        for (int u = 0; u < unroll_factor; u++) {
            int idx = local_i + u;
            int level = block_base[scan_base[idx]];
            if (level) {
                int run = idx - local_last_non_zero - 1;
                level += 64;
                if ((level & (~127)) == 0) {
                    const int index = run * 128 + level;
                    local_len += len_tab[index];
                } else {
                    local_len += 7 + 2 + 1 + 6 + 1 + 12 + 1;
                }
                local_last_non_zero = idx;
            }
        }
    }

    // Handle remaining elements without unrolling
    for (; local_i < last_index; local_i++) {
        int level = block_base[scan_base[local_i]];
        if (level) {
            int run = local_i - local_last_non_zero - 1;
            level += 64;
            if ((level & (~127)) == 0) {
                const int index = run * 128 + level;
                local_len += len_tab[index];
            } else {
                local_len += 7 + 2 + 1 + 6 + 1 + 12 + 1;
            }
            local_last_non_zero = local_i;
        }
    }

    len = local_len;
    last_non_zero = local_last_non_zero;
    i = local_i;
}
