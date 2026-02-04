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

extern ParseContext *pc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *buf = pc->buffer;
    int idx = pc->index;
    int oidx = pc->overread_index;
    int overread = pc->overread;
    for (; overread > 0; overread--) {
        buf[idx++] = buf[oidx++];
    }
    pc->index = idx;
    pc->overread_index = oidx;
    pc->overread = overread;
}
