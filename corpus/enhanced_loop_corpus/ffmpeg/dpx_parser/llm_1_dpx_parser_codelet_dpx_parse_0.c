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

typedef struct DPXParseContext {
    ParseContext pc;
    uint32_t index;
    uint32_t fsize;
    uint32_t remaining_size;
    int is_be;
} DPXParseContext;

extern  uint8_t *buf;
extern int buf_size;
extern DPXParseContext *d;
extern uint32_t state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < buf_size && !(d->pc.frame_start_found); ) {
    // Reduced effective loop depth by eliminating inner condition block structure
    // Inlined logic without additional control constructs
    state = (state << 8) | buf[i++];
    d->pc.frame_start_found = (state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24)) || 
                                state == (('S') | (('D') << 8) | (('P') << 16) | ((unsigned int)('X') << 24)));
    if (d->pc.frame_start_found) {
        d->is_be = state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24));
        d->index = 0;
    }
}
}
