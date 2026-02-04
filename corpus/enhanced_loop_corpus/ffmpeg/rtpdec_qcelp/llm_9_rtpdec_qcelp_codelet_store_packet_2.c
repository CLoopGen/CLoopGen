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
    // Reduced trip count by constraining the loop bound and increasing stride
    int step = 1;
    int start = data->interleave_index;
    int adjusted_limit = (interleave_index + 1) / 2; // Reduce effective iterations

    for (int i = 0; i < adjusted_limit; i++) {
        int mapped_idx = start + i * step;
        if (mapped_idx < interleave_index) {
            data->group[mapped_idx].size = 0;
            // Additional computation per iteration to balance work
            data->next_data[i % 351] ^= data->group[mapped_idx].pos;
        }
    }
    data->interleave_index = interleave_index; // Ensure state consistency
}
