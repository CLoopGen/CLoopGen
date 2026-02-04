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
    int overread = mp->pc.overread;
    int index = mp->pc.index;
    int overread_index = mp->pc.overread_index;
    uint8_t *buffer = mp->pc.buffer;
    unsigned int buffer_size = mp->pc.buffer_size;

    for (; overread > 0; overread--) {
        buffer[index] = buffer[overread_index];
        index++;
        overread_index++;
        if (index >= buffer_size || overread_index >= buffer_size) {
            break;
        }
    }

    mp->pc.overread = 0;
    mp->pc.index = index;
    mp->pc.overread_index = overread_index;
}
