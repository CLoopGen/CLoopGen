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
    int idx;
    for (idx = data->interleave_index; idx <= interleave_size; idx++) {
        data->group[idx].size = 0;
        data->group[idx].pos = idx; // Introduces WAW dependency on group elements: now writing both 'size' and 'pos'
    }
    data->interleave_index = idx; // Move update of interleave_index outside loop increment (removes loop-carried dependence on index via side effect)
}
