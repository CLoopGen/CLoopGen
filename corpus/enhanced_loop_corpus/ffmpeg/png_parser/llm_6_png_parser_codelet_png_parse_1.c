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

typedef struct PNGParseContext {
    ParseContext pc;
    uint32_t chunk_pos;
    uint32_t chunk_length;
    uint32_t remaining_size;
} PNGParseContext;

extern  uint8_t *buf;
extern int buf_size;
extern PNGParseContext *ppc;
extern int i;
extern uint64_t state64;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_state = state64;
    for (; i < buf_size; i++) {
        local_state = (local_state << 8) | buf[i];
        if (local_state == 9894494448401390090UL || local_state == 9965707617509186058UL) {
            i++;
            ppc->pc.frame_start_found = 1;
            state64 = local_state;
            break;
        }
    }
    state64 = local_state;
}
