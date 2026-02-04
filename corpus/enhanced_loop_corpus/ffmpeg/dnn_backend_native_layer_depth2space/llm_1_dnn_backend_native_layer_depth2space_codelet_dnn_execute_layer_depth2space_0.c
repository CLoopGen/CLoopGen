#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern int block_size;
extern int height;
extern int width;
extern  float *input;
extern int y;
extern int x;
extern int by;
extern int bx;
extern int ch;
extern int new_channels;
extern int output_linesize;
extern int by_linesize;
extern int x_linesize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; ++y) {
    for (x = 0; x < width; ++x) {
        int total_block_elements = block_size * block_size * new_channels;
        float *current_input = input;
        for (int idx = 0; idx < total_block_elements; ++idx) {
            int local_ch = idx % new_channels;
            int bx = (idx / new_channels) % block_size;
            int by = (idx / new_channels) / block_size;
            output[by * by_linesize + x * x_linesize + bx * new_channels + local_ch] = current_input[local_ch];
            if (local_ch == new_channels - 1) {
                current_input += new_channels;
            }
        }
        input = current_input;
    }
    output += output_linesize;
}
}
