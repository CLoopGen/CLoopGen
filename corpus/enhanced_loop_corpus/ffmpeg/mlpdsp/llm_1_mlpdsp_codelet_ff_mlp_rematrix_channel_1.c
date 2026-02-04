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
for (i = 0; i < blockpos; i++) {
    for (src_ch = 0; src_ch <= maxchan; src_ch++) {
        int64_t accum = (int64_t)samples[src_ch] * coeffs[src_ch];
        if (matrix_noise_shift) {
            int temp_index = index;
            temp_index &= access_unit_size_pow2 - 1;
            accum += noise_buffer[temp_index] * (1 << (matrix_noise_shift + 7));
            index += index2;
        }
        if (src_ch == maxchan) {
            samples[dest_ch] = ((accum >> 14) & mask) + *bypassed_lsbs;
            bypassed_lsbs += 8;
            samples += 8;
        }
    }
}
}
