#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t lossless_check_data;
extern uint16_t blockpos;
extern int32_t (*sample_buffer)[8];
extern uint8_t *ch_assign;
extern int8_t *output_shift;
extern uint8_t max_matrix_channel;
extern int is32;
extern unsigned int i;
extern unsigned int out_ch;
extern int32_t *data_32;
extern int16_t *data_16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use indirect (pointer-based) and consecutive access by precomputing effective addresses
    // Flatten the 2D sample_buffer access into a linear traversal using pointer arithmetic
    int32_t (*sb_row)[8] = sample_buffer;
    int8_t *shift_ptr = output_shift;
    uint8_t *ch_ptr = ch_assign;
    int32_t *d32 = data_32;
    int16_t *d16 = data_16;
    int mat_ch;
    int32_t sample;

    for (i = 0; i < blockpos; i++) {
        // Reset channel assignment and shift pointers for each sample block
        shift_ptr = output_shift;
        ch_ptr = ch_assign;
        for (out_ch = 0; out_ch <= max_matrix_channel; out_ch++, ch_ptr++, shift_ptr++) {
            mat_ch = *ch_ptr;
            // Consecutive indirect access via pointers
            sample = sb_row[i][mat_ch] * (1U << *shift_ptr);
            lossless_check_data ^= (sample & 0xFFFFFF) << mat_ch;
            if (is32) {
                *d32++ = sample << 8;
            } else {
                *d16++ = sample >> 8;
            }
        }
    }
    // Update global pointers to reflect new positions
    data_32 = d32;
    data_16 = d16;
}
