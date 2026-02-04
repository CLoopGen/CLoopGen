#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _SGIInfo {
    unsigned short magic;
    unsigned char storage;
    unsigned char bytes_per_pixel;
    unsigned short dimension;
    unsigned short columns;
    unsigned short rows;
    unsigned short depth;
    size_t minimum_value;
    size_t maximum_value;
    size_t sans;
    char name[80];
    size_t pixel_format;
    unsigned char filler[404];
} SGIInfo;

SGIInfo iris_info;
ssize_t y;
ssize_t z;
ssize_t offset;
ssize_t *offsets;
unsigned int data_order;

void init_vars() {
    iris_info.rows = 512;
    iris_info.depth = 3;
    data_order = 0;
    offset = (ssize_t)0x7FFFFFFFFFFFFFFF; // large initial offset

    size_t num_offsets = iris_info.rows * iris_info.depth;
    offsets = (ssize_t*)calloc(num_offsets, sizeof(ssize_t));
    if (!offsets) {
        exit(1);
    }

    for (size_t i = 0; i < num_offsets; i++) {
        offsets[i] = rand() % 1000000;
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}