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
extern int next;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pre-increment and local caching
    uint8_t *buf = pc->buffer + pc->last_index;
    uint32_t state = pc->state;
    uint64_t state64 = pc->state64;
    int next_local = next;

    for (; next_local < 0; ) {
        uint8_t byte = buf[next_local++];
        state = (state << 8) | byte;
        state64 = (state64 << 8) | byte;
    }

    pc->state = state;
    pc->state64 = state64;
    pc->overread += (-next) - (-next_local);
    next = next_local;
}
