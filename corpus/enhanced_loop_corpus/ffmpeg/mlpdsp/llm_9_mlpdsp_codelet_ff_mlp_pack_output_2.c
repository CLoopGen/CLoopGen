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
    for (i = 0; i < blockpos; i++) {
        for (out_ch = 0; out_ch <= max_matrix_channel; out_ch += 2) {
            int mat_ch1 = ch_assign[out_ch];
            int32_t sample1 = sample_buffer[i][mat_ch1] * (1U << output_shift[mat_ch1]);
            lossless_check_data ^= (sample1 & 16777215) << mat_ch1;
            if (is32)
                *data_32++ = sample1 * 256U;
            else
                *data_16++ = sample1 >> 8;

            if (out_ch + 1 <= max_matrix_channel) {
                int mat_ch2 = ch_assign[out_ch + 1];
                int32_t sample2 = sample_buffer[i][mat_ch2] * (1U << output_shift[mat_ch2]);
                lossless_check_data ^= (sample2 & 16777215) << mat_ch2;
                if (is32)
                    *data_32++ = sample2 * 256U;
                else
                    *data_16++ = sample2 >> 8;
            }
        }
    }
}
