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
    ssize_t local_offset = offset;
    int local_data_order = data_order;
    for (y = 0; y < (ssize_t)iris_info.rows; y++) {
        for (z = 0; z < (ssize_t)iris_info.depth; z++) {
            ssize_t index = y + z * iris_info.rows;
            if (local_data_order == 0) {
                if (offsets[index] < local_offset)
                    local_data_order = 1;
                local_offset = offsets[index];
            }
        }
    }
    offset = local_offset;
    if (local_data_order)
        data_order = 1;
}
