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
if (blockpos > 0) {
    int64_t accum = 0;
    src_ch = 0;
    do {
        accum += (int64_t)samples[src_ch] * coeffs[src_ch];
        src_ch++;
    } while (src_ch <= maxchan);

    if (matrix_noise_shift) {
        index &= access_unit_size_pow2 - 1;
        accum += noise_buffer[index] * (1 << (matrix_noise_shift + 7));
    }

    for (i = 0; i < blockpos; i++) {
        samples[dest_ch] = ((accum >> 14) & mask) + bypassed_lsbs[i * 8];
        if (matrix_noise_shift) {
            index += index2;
            index &= access_unit_size_pow2 - 1;
            // Reuse base accum but add shifted noise based on updated index
            int64_t temp_accum = accum + noise_buffer[index] * (1 << (matrix_noise_shift + 7));
            samples[dest_ch] = ((temp_accum >> 14) & mask) + bypassed_lsbs[i * 8];
        }
    }
    samples += blockpos * 8;
    bypassed_lsbs += blockpos * 8;
}
}
