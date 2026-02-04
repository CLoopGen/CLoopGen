#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ParseContext {
    uint8_t *buffer;
    int index;
    int last_index;
    unsigned int buffer_size;
    uint32_t state;
    int frame_start_found;
    int overread;
    int overread_index;
    uint64_t state64;
} ParseContext;

ParseContext *pc;

uint8_t *global_buffer;

void init_vars() {
    const size_t data_size = 134217728; // 128MB to target ~0.01s runtime on modern CPU

    global_buffer = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!global_buffer) exit(1);

    pc = (ParseContext*)malloc(sizeof(ParseContext));
    if (!pc) exit(1);

    pc->buffer = global_buffer;
    pc->index = 0;
    pc->last_index = data_size - 1;
    pc->buffer_size = data_size;
    pc->state = 0;
    pc->frame_start_found = 1;
    pc->overread = 1000000; // Ensure loop runs sufficiently long (~1M iterations for ~0.01s)
    pc->overread_index = data_size - pc->overread;

    if (pc->overread_index < 0) {
        pc->overread_index = 0;
        pc->overread = data_size;
    }

    pc->state64 = 0;

    for (int i = 0; i < pc->overread; i++) {
        global_buffer[pc->overread_index + i] = (uint8_t)(i & 0xFF);
    }
}