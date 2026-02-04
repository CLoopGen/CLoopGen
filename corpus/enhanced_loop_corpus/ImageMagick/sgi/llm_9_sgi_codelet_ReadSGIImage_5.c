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

extern SGIInfo iris_info;
extern ssize_t y;
extern ssize_t z;
extern ssize_t offset;
extern ssize_t *offsets;
extern unsigned int data_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t total_elements = (ssize_t)(iris_info.rows * iris_info.depth);
    for (y = 0; y < total_elements && data_order == 0; y++) {
        ssize_t row = y % iris_info.rows;
        ssize_t depth_idx = y / iris_info.rows;
        if (depth_idx >= (ssize_t)iris_info.depth) continue;
        if (offsets[row + depth_idx * iris_info.rows] < offset)
            data_order = 1;
        offset = offsets[row + depth_idx * iris_info.rows];
    }
}
