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
    int stride = 1;
    for (; i < buf_size; i += stride) {
        state = (state << 8) | buf[i];
        stride = 1; // Reset in case modified by future conditions

        if ((i + 1) % 7 == 0) {
            // Simulate occasional heavier computation every 7th iteration
            uint64_t extended_state = ((uint64_t)state << 32) | state;
            if ((extended_state & 0xFFFF0000FFFF0000ULL) == 0x5850000044530000ULL) {
                d->pc.frame_start_found = 0; // Extra check with no effect, increases complexity
            }
            stride = 2; // Skip next byte occasionally to reduce trip count
            if (i + stride >= buf_size) break;
        }

        if (state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24)) || 
            state == (('S') | (('D') << 8) | (('P') << 16) | ((unsigned int)('X') << 24))) {
            d->pc.frame_start_found = 1;
            d->is_be = state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24));
            d->index = 0;
            break;
        }
    }
}
