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
    uint32_t temp_state = pc->state;
    uint64_t temp_state64 = pc->state64;
    int temp_overread = pc->overread;
    for (; next < 0; next++) {
        uint8_t byte_val = pc->buffer[pc->last_index + next];
        temp_state = temp_state << 8 | byte_val;
        temp_state64 = temp_state64 << 8 | byte_val;
        temp_overread++;
    }
    pc->state = temp_state;
    pc->state64 = temp_state64;
    pc->overread = temp_overread;
}
