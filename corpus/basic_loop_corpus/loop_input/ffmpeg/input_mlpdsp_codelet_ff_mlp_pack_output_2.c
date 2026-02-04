#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int32_t lossless_check_data;
uint16_t blockpos;
int32_t (*sample_buffer)[8];
uint8_t *ch_assign;
int8_t *output_shift;
uint8_t max_matrix_channel;
int is32;
unsigned int i;
unsigned int out_ch;
int32_t *data_32;
int16_t *data_16;

void init_vars() {
    // Define data size to achieve ~0.01 sec runtime: aim for moderate size
    // Based on loop: i in [0, blockpos), mat_ch from ch_assign[out_ch], which maps to [0,7] since sample_buffer[i][mat_ch]
    // We assume blockpos ~ 32768 and max_matrix_channel ~ 7 to get deep enough computation

    blockpos = 16384;           // ~16K blocks
    max_matrix_channel = 7;     // so out_ch from 0 to 7
    is32 = 1;                   // test the is32=1 branch (write to data_32)

    // Allocate ch_assign: one byte per output channel up to max_matrix_channel+1
    ch_assign = (uint8_t*)malloc((max_matrix_channel + 1) * sizeof(uint8_t));
    for (out_ch = 0; out_ch <= max_matrix_channel; out_ch++) {
        ch_assign[out_ch] = out_ch % 8;  // map to valid matrix channel 0-7
    }

    // Allocate output_shift: one per matrix channel? but indexed by mat_ch -> size 8
    output_shift = (int8_t*)malloc(8 * sizeof(int8_t));
    for (int idx = 0; idx < 8; idx++) {
        output_shift[idx] = (idx % 3) - 1;  // shift values: -1, 0, 1, -1, ...
    }

    // sample_buffer: [blockpos][8]
    sample_buffer = (int32_t(*)[8])malloc(blockpos * 8 * sizeof(int32_t));
    for (i = 0; i < blockpos; i++) {
        for (int ch = 0; ch < 8; ch++) {
            sample_buffer[i][ch] = (int32_t)(i ^ (ch << 12)) + 1000;
        }
    }

    // Data buffers: total writes = blockpos * (max_matrix_channel + 1)
    size_t total_samples = blockpos * (max_matrix_channel + 1);

    if (is32) {
        data_32 = (int32_t*)malloc(total_samples * sizeof(int32_t));
        memset(data_32, 0, total_samples * sizeof(int32_t));
    } else {
        data_16 = (int16_t*)malloc(total_samples * sizeof(int16_t));
        memset(data_16, 0, total_samples * sizeof(int16_t));
    }

    // Initialize global state
    lossless_check_data = 0;
}