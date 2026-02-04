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
    int idx = mp->pc.index;
    int oidx = mp->pc.overread_index;
    for (; mp->pc.overread > 0; mp->pc.overread--) {
        mp->pc.buffer[idx++] = mp->pc.buffer[oidx++];
    }
    mp->pc.index = idx;
    mp->pc.overread_index = oidx;
}
