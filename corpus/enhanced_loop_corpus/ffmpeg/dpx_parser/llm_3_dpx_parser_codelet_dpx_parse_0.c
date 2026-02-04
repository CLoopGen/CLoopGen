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
    // Variant 2: Indirect memory access using an index array
    // Simulates irregular access via precomputed indices (within bounds).
    // We create a local indirect access pattern by accessing buf through an index map.
    int *indices = (int*)malloc(buf_size * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Create indirect access: reverse order access (simulating non-sequential)
    for (int j = 0; j < buf_size; j++) {
        indices[j] = buf_size - 1 - j; // reverse mapping
    }

    state = 0;
    for (int j = 0; j < buf_size; j++) {
        int pos = indices[j]; // indirect access position
        state = (state << 8) | buf[pos];

        if (state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24)) || 
            state == (('S') | (('D') << 8) | (('P') << 16) | ((unsigned int)('X') << 24))) {
            d->pc.frame_start_found = 1;
            d->is_be = state == (('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24));
            d->index = 0;
            i = pos + 1; // update global index to forward progress
            free(indices);
            return;
        }
    }

    // If no sync in reversed scan, fallback to original forward scan from current i
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

    free(indices);
}
