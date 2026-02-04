#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples;
extern  int32_t *coeffs;
extern  uint8_t *bypassed_lsbs;
extern  int8_t *noise_buffer;
extern int _usr_index;
extern unsigned int dest_ch;
extern uint16_t blockpos;
extern unsigned int maxchan;
extern int matrix_noise_shift;
extern int access_unit_size_pow2;
extern int32_t mask;
extern unsigned int src_ch;
extern unsigned int i;
extern int index2;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Strided Memory Access with Indirect Indexing
    // Use indirect addressing via precomputed indices to simulate irregular memory access,
    // which could model sparse matrix contributions or non-contiguous channel mapping.
    uint32_t idx_map[32]; // Simulated precomputed index map (assume maxchan < 32)
    for (src_ch = 0; src_ch <= maxchan; src_ch++) {
        idx_map[src_ch] = src_ch * 7; // Artificial stride (prime number for irregularity)
    }
    for (i = 0; i < blockpos; i++) {
        int64_t accum = 0;
        for (src_ch = 0; src_ch <= maxchan; src_ch++) {
            uint32_t idx = idx_map[src_ch] + i;
            accum += (int64_t)samples[idx] * coeffs[idx];
        }
        if (matrix_noise_shift) {
            index &= access_unit_size_pow2 - 1;
            accum += noise_buffer[index] * (1LL << (matrix_noise_shift + 7));
            index += index2;
        }
        samples[dest_ch + i * 8] = ((accum >> 14) & mask) + bypassed_lsbs[i];
        bypassed_lsbs++;
        samples++;
    }
}
