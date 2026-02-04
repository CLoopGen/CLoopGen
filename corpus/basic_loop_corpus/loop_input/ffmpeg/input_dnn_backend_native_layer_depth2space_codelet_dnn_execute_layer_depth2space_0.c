#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *output;
int block_size;
int height;
int width;
float *input;
int y;
int x;
int by;
int bx;
int ch;
int new_channels;
int output_linesize;
int by_linesize;
int x_linesize;

void init_vars() {
    block_size = 4;
    height = 64;
    width = 64;
    new_channels = 16;
    by_linesize = width * block_size * new_channels;
    x_linesize = block_size * new_channels;
    output_linesize = block_size * by_linesize;

    int input_size = height * width * block_size * block_size * new_channels;
    int total_output_size = height * output_linesize + block_size * by_linesize;

    input = (float*)calloc(input_size, sizeof(float));
    output = (float*)calloc(total_output_size, sizeof(float));

    if (!input || !output) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < input_size; ++i) {
        input[i] = (float)(i % 256) / 255.0f;
    }
}