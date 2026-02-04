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
extern int interleave_index;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = data->interleave_index;
    int limit = interleave_index;
    // Increased computational intensity by unrolling and adding redundant arithmetic operations
    for (; idx < limit; idx += 2) {
        data->group[idx].size = 0;
        if (idx + 1 < limit) {
            data->group[idx + 1].size = 0;
        }
        // Add dummy arithmetic to increase computational load
        volatile uint32_t dummy = idx * idx + idx * 3 + 1;
        (void)dummy;
    }
    data->interleave_index = idx > interleave_index ? interleave_index : idx;
}
