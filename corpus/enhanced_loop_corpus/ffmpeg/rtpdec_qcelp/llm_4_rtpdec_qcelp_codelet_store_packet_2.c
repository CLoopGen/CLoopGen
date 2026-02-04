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
    for (; idx < interleave_index; idx++) {
        if (data->group[idx].size > 0) {
            data->group[idx].size = 0;
        }
    }
    data->interleave_index = idx;
}
