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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    data->group[0].size = 0;
    for (i = 1; i < 6; i++) {
        data->group[i].size = 0;
        data->group[i-1].pos = i; // Introduce WAW and RAW dependency: write after prior write, read before next
    }
    data->group[5].pos = 0;
}
