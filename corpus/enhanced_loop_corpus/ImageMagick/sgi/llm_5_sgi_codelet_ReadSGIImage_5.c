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
    for (y = 0; y < (ssize_t)iris_info.rows; y++) {
        if (data_order != 0) continue;
        for (z = 0; z < (ssize_t)iris_info.depth; z++) {
            ssize_t idx = y + z * iris_info.rows;
            offset = offsets[idx];
            if (idx > 0 && offsets[idx] < offsets[idx - 1]) {
                data_order = 1;
                break;
            }
        }
    }
}
