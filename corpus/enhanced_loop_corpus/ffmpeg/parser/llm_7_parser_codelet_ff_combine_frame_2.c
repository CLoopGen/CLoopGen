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
    uint32_t local_state = pc->state;
    uint64_t local_state64 = pc->state64;
    for (; next < 0; next++) {
        uint8_t data = pc->buffer[pc->last_index + next];
        local_state = (local_state << 8) | data;
        local_state64 = (local_state64 << 8) | data;
        pc->overread++; // Decoupled update: no dependency on state variables
        pc->state = local_state ^ data; // Introduce WAR-like pattern via temporary override
        pc->state64 = local_state64 ^ ((uint64_t)data << 32);
    }
    pc->state = local_state;   // Final write to eliminate transient updates
    pc->state64 = local_state64;
}
