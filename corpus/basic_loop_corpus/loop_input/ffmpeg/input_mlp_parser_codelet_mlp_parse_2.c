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

uint8_t *buf;
int buf_size;
MLPParseContext *mp;
int i;

void init_vars() {
    buf_size = 1 << 20; // 1MB of data for approximately 0.01 sec runtime
    buf = (uint8_t *)calloc(buf_size, sizeof(uint8_t));
    if (!buf) {
        fprintf(stderr, "Failed to allocate buf\n");
        exit(1);
    }

    mp = (MLPParseContext *)calloc(1, sizeof(MLPParseContext));
    if (!mp) {
        fprintf(stderr, "Failed to allocate mp\n");
        free(buf);
        exit(1);
    }

    mp->pc.buffer = NULL;
    mp->pc.index = 0;
    mp->pc.last_index = 0;
    mp->pc.buffer_size = 0;
    mp->pc.state = 0;
    mp->pc.frame_start_found = 0;
    mp->pc.overread = 0;
    mp->pc.overread_index = 0;
    mp->pc.state64 = 0;

    mp->bytes_left = 0;
    mp->in_sync = 0;
    mp->num_substreams = 0;

    for (int j = 0; j < buf_size; j++) {
        buf[j] = rand() & 0xFF;
    }

    // Ensure the pattern will eventually match to break early
    // Pattern: state matches condition (state & 4294967294U) == 4168249274U
    // We write bytes such that after 8 shifts, the state becomes 0xF870F87A (which satisfies the condition)
    uint32_t target = 0xF870F87AU; // This satisfies (target & 4294967294U) == 4168249274U
    if (buf_size >= 8) {
        buf[buf_size - 8] = (target >> 24) & 0xFF;
        buf[buf_size - 7] = (target >> 16) & 0xFF;
        buf[buf_size - 6] = (target >> 8) & 0xFF;
        buf[buf_size - 5] = target & 0xFF;
        // Ensure earlier bytes don't trigger early match
        for (int j = buf_size - 9; j >= 0; j--) {
            buf[j] = 0x00;
        }
    }
}