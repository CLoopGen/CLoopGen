#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short **inY;
unsigned short ***refY;
int i;
int j;
int ref_inx;
int pos_y;
int pos_x;

static unsigned short ***alloc_refY(int depth, int height, int width) {
    unsigned short ***arr = malloc(depth * sizeof(unsigned short**));
    for (int d = 0; d < depth; ++d) {
        arr[d] = malloc(height * sizeof(unsigned short*));
        for (int h = 0; h < height; ++h) {
            arr[d][h] = malloc(width * sizeof(unsigned short));
            for (int w = 0; w < width; ++w) {
                arr[d][h][w] = rand() & 0xFFFF;
            }
        }
    }
    return arr;
}

static unsigned short **alloc_inY(int height, int width) {
    unsigned short **arr = malloc(height * sizeof(unsigned short*));
    for (int h = 0; h < height; ++h) {
        arr[h] = calloc(width, sizeof(unsigned short));
    }
    return arr;
}

void init_vars() {
    const int total_data_size = 64 * 1024 * 1024;
    const int element_size = sizeof(unsigned short);
    const int total_elements = total_data_size / element_size;
    const int block_area = 16 * 16;
    const int num_blocks = (total_elements + block_area - 1) / block_area;
    const int feature_dim = 32;

    ref_inx = 0;
    pos_y = 8;
    pos_x = 8;

    refY = alloc_refY(num_blocks, pos_y + 16, pos_x + 16);
    inY = alloc_inY(pos_y + 16, pos_x + 16);
}