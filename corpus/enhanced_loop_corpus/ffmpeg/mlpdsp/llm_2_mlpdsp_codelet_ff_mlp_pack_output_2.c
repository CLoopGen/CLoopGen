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
    // Variant 1: Change memory access pattern to use strided access for sample_buffer with reversed output channel iteration
    // This variant reverses the out_ch loop and uses a fixed stride on sample_buffer assuming cache-friendly access patterns
    uint16_t pos;
    int32_t sample;
    int mat_ch;
    for (i = 0; i < blockpos; i++) {
        // Process output channels in reverse to modify memory access order
        for (out_ch = max_matrix_channel + 1; out_ch-- > 0;) {
            mat_ch = ch_assign[out_ch];
            // Stride through sample_buffer with known index, still using [i][mat_ch], but change accumulation order
            sample = sample_buffer[i][mat_ch] << output_shift[mat_ch];  // Use shift instead of pow(2) via <<
            lossless_check_data ^= (sample & 16777215) << mat_ch;
            if (is32)
                data_32[(i * (max_matrix_channel + 1)) + out_ch] = sample << 8;  // Direct indexed write to avoid pointer increment side effects
            else
                data_16[(i * (max_matrix_channel + 1)) + out_ch] = (int16_t)(sample >> 8);
        }
    }
}
