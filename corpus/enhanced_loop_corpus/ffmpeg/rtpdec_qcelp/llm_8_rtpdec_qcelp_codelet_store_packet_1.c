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
    int idx = 0;
    int limit = data->interleave_size + 1;
    for (; idx < limit; idx++) {
        data->group[idx].size = 0;
        data->group[idx].pos = 0;
        for (int j = 0; j < 32; j += 8) {
            ((uint64_t*)data->group[idx].data)[j / 8] = 0ULL;
        }
    }
}
