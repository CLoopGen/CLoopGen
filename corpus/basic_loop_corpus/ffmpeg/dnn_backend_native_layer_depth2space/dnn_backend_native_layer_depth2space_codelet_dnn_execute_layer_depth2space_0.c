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
        for (by = 0; by < block_size; ++by) {
            for (bx = 0; bx < block_size; ++bx) {
                for (ch = 0; ch < new_channels; ++ch) {
                    output[by * by_linesize + x * x_linesize + bx * new_channels + ch] = input[ch];
                }
                input += new_channels;
            }
        }
    }
    output += output_linesize;
}

}
