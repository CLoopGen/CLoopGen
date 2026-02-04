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
int i;

void init_vars() {
    data = (PayloadContext*)calloc(1, sizeof(PayloadContext));
    if (!data) {
        exit(1);
    }
    data->interleave_size = 0;
    data->interleave_index = 0;
    data->group_finished = 0;
    data->next_size = 0;
    data->next_timestamp = 0;
    for (int j = 0; j < 6; j++) {
        data->group[j].pos = 0;
        data->group[j].size = 0;
    }
}