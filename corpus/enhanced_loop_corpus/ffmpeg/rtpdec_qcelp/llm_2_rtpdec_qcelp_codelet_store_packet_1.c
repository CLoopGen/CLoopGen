#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct InterleavePacket {
    int pos;
    int size;
    uint8_t data[315];
} InterleavePacket;

struct PayloadContext {
    int interleave_size;
    int interleave_index;
    InterleavePacket group[6];
    int group_finished;
    uint8_t next_data[351];
    int next_size;
    uint32_t next_timestamp;
};


typedef struct PayloadContext PayloadContext;

extern PayloadContext *data;
extern int interleave_size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2, unrolled to handle even indices
    int idx = data->interleave_index;
    while (idx <= interleave_size) {
        data->group[idx].size = 0;
        idx += 2;
    }
    // Handle odd index if starting point was odd
    idx = data->interleave_index + 1;
    while (idx <= interleave_size) {
        data->group[idx].size = 0;
        idx += 2;
    }
}
