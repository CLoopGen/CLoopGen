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
    uint32_t prev_state = state;
    uint32_t temp_state = state;
    for (; i < buf_size; i++) {
        temp_state = (prev_state << 8) | buf[i];
        prev_state = temp_state;
        if (temp_state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24)) || 
            temp_state == (('S') | (('D') << 8) | (('P') << 16) | ((unsigned int)('X') << 24))) {
            d->pc.frame_start_found = 1;
            d->is_be = temp_state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24));
            d->index = 0;
            state = temp_state;
            break;
        }
    }
}
