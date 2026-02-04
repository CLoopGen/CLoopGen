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
    // Variant 2: Use indirect array indexing via pointer arithmetic and consecutive access simulation
    // Flatten the nested loop into a single loop that iterates over all (row, depth) pairs
    // Access offsets using computed indices, simulating consecutive traversal in memory layout

    ssize_t total_elements = (ssize_t)(iris_info.rows * iris_info.depth);
    for (ssize_t i = 0; (i < total_elements) && (data_order == 0); i++) {
        // Map linear index i to z (depth) and y (row): row-major order: i = y + z * rows
        ssize_t z = i / iris_info.rows;
        ssize_t y = i % iris_info.rows;

        if (offsets[y + z * iris_info.rows] < offset)
            data_order = 1;
        offset = offsets[y + z * iris_info.rows];
    }
}
