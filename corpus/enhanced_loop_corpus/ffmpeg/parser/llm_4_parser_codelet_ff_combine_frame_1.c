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
    int overread = pc->overread;
    if (overread <= 0) return;
    uint8_t *buffer = pc->buffer;
    int *index = &pc->index;
    int overread_index = pc->overread_index;

    for (; overread > 0; overread--, (*index)++, overread_index++)
        buffer[*index] = buffer[overread_index];
}
