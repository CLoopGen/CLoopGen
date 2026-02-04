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
    pc->state = pc->state << 8 | pc->buffer[pc->last_index + next];
    pc->state64 = pc->state64 << 8 | pc->buffer[pc->last_index + next];
    pc->overread++;
}

}
