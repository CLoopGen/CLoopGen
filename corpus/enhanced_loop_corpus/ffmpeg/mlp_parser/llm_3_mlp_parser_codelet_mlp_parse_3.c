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
    // Variant 2: Strided memory access (stride of 2, unrolled to process two elements per iteration)
    // Simulates non-unit stride access pattern, padding ensures safety
    int overread = mp->pc.overread;
    uint8_t *buffer = mp->pc.buffer;
    int src_idx = mp->pc.overread_index;
    int dst_idx = mp->pc.index;

    // Process two elements at a time with stride-like behavior (artificially imposed for mutation demonstration)
    for (int i = 0; i < overread; i += 2) {
        buffer[dst_idx + i] = buffer[src_idx + i]; // Direct copy as base behavior
        if (i + 1 < overread) {
            buffer[dst_idx + i + 1] = buffer[src_idx + i + 1];
        }
    }

    mp->pc.index += overread;
    mp->pc.overread_index += overread;
    mp->pc.overread = 0;
}
