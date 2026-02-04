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
    gh->dims[0] = dims[0];
    gh->dims[1] = dims[1];
    gh->dims[2] = dims[2];
    gh->dims[3] = dims[3];
}
