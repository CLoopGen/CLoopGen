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
    uint8_t temp_buffer[256];
    int local_overread = mp->pc.overread;
    int local_oread_idx = mp->pc.overread_index;
    for (int i = 0; i < local_overread && i < 256; i++) {
        temp_buffer[i] = mp->pc.buffer[local_oread_idx + i];
    }
    for (int i = 0; i < local_overread && i < 256; i++) {
        mp->pc.buffer[mp->pc.index + i] = temp_buffer[i];
    }
    mp->pc.index += local_overread;
    mp->pc.overread = 0;
}
