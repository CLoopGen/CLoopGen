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
    // Eliminate loop-carried dependency on 'samples' by unrolling two iterations and reordering memory accesses
    unsigned int step = 2;
    unsigned int remainder = blockpos % step;
    // Handle multiple of 2 iterations with unrolled body
    for (i = 0; i < blockpos - remainder; i += step) {
        int64_t accum0 = 0, accum1 = 0;
        // Pre-load values before computation to expose parallelism
        int32_t s0 = samples[dest_ch];
        int32_t s1 = samples[dest_ch + 8]; // assuming dest_ch offset compatibility
        const uint8_t* lsb_ptr0 = bypassed_lsbs;
        const uint8_t* lsb_ptr1 = bypassed_lsbs + 8;

        for (src_ch = 0; src_ch <= maxchan; src_ch++) {
            int32_t c = coeffs[src_ch];
            accum0 += (int64_t)samples[src_ch] * c;
            accum1 += (int64_t)samples[src_ch + 8] * c; // shifted input assumption
        }

        if (matrix_noise_shift) {
            int idx0 = index & (access_unit_size_pow2 - 1);
            int idx1 = (index + index2) & (access_unit_size_pow2 - 1);
            accum0 += noise_buffer[idx0] * (1LL << (matrix_noise_shift + 7));
            accum1 += noise_buffer[idx1] * (1LL << (matrix_noise_shift + 7));
            index += 2 * index2;
        }

        samples[dest_ch]     = ((accum0 >> 14) & mask) + *lsb_ptr0;
        samples[dest_ch + 8] = ((accum1 >> 14) & mask) + *lsb_ptr1;

        bypassed_lsbs += 16;
        samples += 16;
    }
    // Handle remaining iteration if any
    for (; i < blockpos; i++) {
        int64_t accum = 0;
        for (src_ch = 0; src_ch <= maxchan; src_ch++)
            accum += (int64_t)samples[src_ch] * coeffs[src_ch];
        if (matrix_noise_shift) {
            index &= access_unit_size_pow2 - 1;
            accum += noise_buffer[index] * (1LL << (matrix_noise_shift + 7));
            index += index2;
        }
        samples[dest_ch] = ((accum >> 14) & mask) + *bypassed_lsbs;
        bypassed_lsbs += 8;
        samples += 8;
    }
}
