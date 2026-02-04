#include <stdio.h>

#include <inttypes.h>

typedef int int32type;

typedef struct {
    int32type magic_number;
    char time_stamp[64];
    int32type dims[4];
    int32type header_bytes;
    int32type order;
} gauge_header;

extern gauge_header *gh;
extern int i;
extern int dims[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    for (i = 3; i >= 0; i--)
        gh->dims[i] = dims[i];
}
