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
int next;

static uint8_t *global_buffer;
static ParseContext global_pc;

void init_vars() {
    size_t data_size = 16777216; // 16MB to target ~0.01s runtime
    global_buffer = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!global_buffer) {
        exit(1);
    }

    global_pc.buffer = global_buffer;
    global_pc.index = 0;
    global_pc.last_index = 8;
    global_pc.buffer_size = (unsigned int)data_size;
    global_pc.state = 0xAAAAAAAA;
    global_pc.frame_start_found = 0;
    global_pc.overread = 0;
    global_pc.overread_index = 0;
    global_pc.state64 = 0xAAAAAAAAAAAAAAAAULL;

    pc = &global_pc;
    next = -16;
}

void cleanup_vars() {
    if (global_buffer) {
        free(global_buffer);
        global_buffer = NULL;
    }
}