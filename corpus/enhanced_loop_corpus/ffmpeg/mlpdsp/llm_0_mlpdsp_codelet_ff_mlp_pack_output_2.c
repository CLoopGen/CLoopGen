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
    if (blockpos == 0 || max_matrix_channel < 0) return;
    for (i = 0; i < blockpos; i++) {
        int32_t sample;
        int mat_ch;
        for (out_ch = 0; out_ch <= max_matrix_channel; out_ch++) {
            mat_ch = ch_assign[out_ch];
            sample = sample_buffer[i][mat_ch] * (1U << output_shift[mat_ch]);
            lossless_check_data ^= (sample & 16777215) << mat_ch;
            if (is32)
                *data_32++ = sample * 256U;
            else
                *data_16++ = sample >> 8;
        }
    }
}
