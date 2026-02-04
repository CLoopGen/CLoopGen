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



void loop(){
    int i = data->interleave_index;
    for (; i <= interleave_size; i++) {
        // Introduce a RAW dependency: current iteration depends on previous iteration's size
        if (i > data->interleave_index) {
            data->group[i].size = data->group[i - 1].size + 1; // Forward data dependency (RAW), creating loop-carried dependence
        } else {
            data->group[i].size = 0;
        }
    }
    data->interleave_index = i; // Update field after loop completes, eliminating loop increment side effect
}
