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
    // Variant 1: Strided memory access with step size of 2
    // This variant reads every second byte, simulating a strided access pattern.
    // After processing, it resumes sequential scanning if needed to maintain correctness.
    state = 0;
    int step = 2;
    int j;
    for (j = i; j < buf_size; j += step) {
        if (j >= buf_size) break;
        state = (state << 8) | buf[j];
        if (state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24)) || 
            state == (('S') | (('D') << 8) | (('P') << 16) | ((unsigned int)('X') << 24))) {
            d->pc.frame_start_found = 1;
            d->is_be = state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24));
            d->index = 0;
            i = j + 1; // update global index
            return;
        }
    }
    // Fallback to linear scan from last point if strided missed due to alignment
    for (; i < buf_size; i++) {
        state = (state << 8) | buf[i];
        if (state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24)) || 
            state == (('S') | (('D') << 8) | (('P') << 16) | ((unsigned int)('X') << 24))) {
            d->pc.frame_start_found = 1;
            d->is_be = state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24));
            d->index = 0;
            break;
        }
    }
}
