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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *src = pc->buffer + pc->overread_index;
    uint8_t *dst = pc->buffer + pc->index;
    for (int i = 0; i < pc->overread; i++) {
        dst[i] = src[i];
    }
    pc->index += pc->overread;
    pc->overread_index += pc->overread;
    pc->overread = 0;
}
