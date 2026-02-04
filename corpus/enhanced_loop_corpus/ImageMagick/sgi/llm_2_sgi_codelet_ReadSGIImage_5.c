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



void loop() {
    // Variant 1: Change memory access pattern to strided access with reversed loop order
    // Instead of accessing offsets[y + z * iris_info.rows], we traverse in column-major-like fashion with stride = rows
    // We also reverse the iteration order for both loops to create a different access pattern

    for (z = (ssize_t)iris_info.depth - 1; ((z >= 0) && (data_order == 0)); z--)
        for (y = (ssize_t)iris_info.rows - 1; ((y >= 0) && (data_order == 0)); y--) {
            ssize_t idx = y + z * iris_info.rows;
            if (offsets[idx] < offset)
                data_order = 1;
            offset = offsets[idx];
        }
}
