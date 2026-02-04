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

typedef struct MLPParseContext {
    ParseContext pc;
    int bytes_left;
    int in_sync;
    int num_substreams;
} MLPParseContext;

static uint8_t *global_buffer = NULL;
MLPParseContext *mp = NULL;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB

    global_buffer = (uint8_t*)malloc(data_size);
    if (!global_buffer) exit(1);

    mp = (MLPParseContext*)malloc(sizeof(MLPParseContext));
    if (!mp) exit(1);

    mp->pc.buffer = global_buffer;
    mp->pc.buffer_size = data_size;
    mp->pc.overread = 5000000; // Set overread to trigger loop ~5e6 times for ~0.01 sec runtime
    mp->pc.index = 0;
    mp->pc.overread_index = data_size - mp->pc.overread; // Ensure copy from valid region
    mp->pc.last_index = 0;
    mp->pc.state = 0;
    mp->pc.frame_start_found = 0;
    mp->pc.overread_index = data_size - mp->pc.overread;
    mp->pc.state64 = 0;

    mp->bytes_left = 0;
    mp->in_sync = 0;
    mp->num_substreams = 0;

    for (int i = 0; i < mp->pc.overread; i++) {
        global_buffer[mp->pc.overread_index + i] = (uint8_t)(i & 0xFF);
    }
}