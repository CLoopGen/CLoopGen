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
    int temp_dims[4];
    for (int i = 0; i < 4; i++)
        temp_dims[i] = dims[i];
    for (int i = 0; i < 4; i++)
        gh->dims[i] = temp_dims[i];
}
