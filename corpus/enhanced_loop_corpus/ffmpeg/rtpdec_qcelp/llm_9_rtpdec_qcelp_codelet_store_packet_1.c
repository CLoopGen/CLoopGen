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
    int step = 2;
    int i = 0;
    int n = data->interleave_size + 1;

    for (; i <= n; i += step) {
        if (i <= interleave_size)
            data->group[i].size = 0;
        if (i + 1 <= interleave_size)
            data->group[i + 1].size = 0;
    }

    if ((data->interleave_size + 1) % 2 == 1 && data->interleave_index == 0) {
        data->group[0].size = 0;
    }
}
