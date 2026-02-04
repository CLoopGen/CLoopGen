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

static struct PayloadContext payload_context_instance;

struct PayloadContext *data = &payload_context_instance;
int interleave_size = 5;

void init_vars() {
    data->interleave_size = 5;
    data->interleave_index = 0;
    data->group_finished = 0;
    data->next_size = 0;
    data->next_timestamp = 0;
    for (int i = 0; i < 6; ++i) {
        data->group[i].pos = 0;
        data->group[i].size = 0;
    }
    for (int i = 0; i < 351; ++i) {
        data->next_data[i] = 0;
    }
}