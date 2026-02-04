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
    int offset_out;
    float *input_base = input;
    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            int linear_idx = y * width + x;
            for (by = 0; by < block_size; ++by) {
                for (bx = 0; bx < block_size; ++bx) {
                    offset_out = by * by_linesize + x * x_linesize + bx * new_channels;
                    for (ch = 0; ch < new_channels; ++ch) {
                        output[offset_out + ch] = input_base[linear_idx * block_size * block_size * new_channels + 
                                                             (by * block_size + bx) * new_channels + ch];
                    }
                }
            }
        }
    }
    input = input_base + height * width * block_size * block_size * new_channels;
    output += height * output_linesize;
}
