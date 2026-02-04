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

PayloadContext *data;
int interleave_index;

void init_vars() {
    // Allocate and initialize data
    data = (PayloadContext*)calloc(1, sizeof(PayloadContext));
    if (!data) exit(1);

    // Initialize group elements
    for (int i = 0; i < 6; i++) {
        data->group[i].pos = 0;
        data->group[i].size = 0; // Will be set by loop
    }

    // Set interleave_index to a value that ensures ~6 iterations (within bounds)
    interleave_index = 6;

    // Initialize other fields
    data->interleave_size = 6;
    data->interleave_index = 0;
    data->group_finished = 0;
    data->next_size = 0;
    data->next_timestamp = 0;

    // Ensure next_data is initialized
    for (int i = 0; i < 351; i++) {
        data->next_data[i] = 0;
    }
}