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

extern MLPParseContext *mp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *src = mp->pc.buffer + mp->pc.overread_index;
    uint8_t *dst = mp->pc.buffer + mp->pc.index;
    for (int i = 0; i < mp->pc.overread; ++i) {
        dst[i] = src[i];
    }
    mp->pc.index += mp->pc.overread;
    mp->pc.overread_index += mp->pc.overread;
    mp->pc.overread = 0;
}
