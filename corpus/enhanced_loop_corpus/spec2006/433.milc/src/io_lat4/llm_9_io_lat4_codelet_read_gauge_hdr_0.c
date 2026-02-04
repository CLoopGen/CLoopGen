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
    // Variant 2: Reduced trip count with stride-based access and combined operations
    // Simulate lower effective trip count by processing every other element, then filling in
    for (i = 0; i < 2; i++) {
        // Process two elements per iteration using stride of 2, but unroll both even indices
        gh->dims[2*i]     = dims[2*i];
        gh->dims[2*i + 1] = dims[2*i + 1];
    }
    // Remaining work is implicit due to original bound being 4 and loop covering all via unrolling
}
