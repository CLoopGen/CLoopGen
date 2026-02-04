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
for (; next < 0; next++) {
    if (pc->last_index + next >= pc->buffer_size) {
        pc->overread++;
        continue;
    }
    uint8_t byte = pc->buffer[pc->last_index + next];
    pc->state = (pc->state << 8) | byte;
    pc->state64 = (pc->state64 << 8) | byte;
    pc->overread++;
}
}
