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
    if (data->interleave_index < interleave_index) {
        int i = data->interleave_index;
        do {
            data->group[i].size = 0;
            i++;
        } while (i < interleave_index);
        data->interleave_index = interleave_index;
    }
}
