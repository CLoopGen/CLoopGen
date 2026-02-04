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
    // Variant 2: Strided memory access (stride of 2, reading every second byte backwards)
    // Simulates irregular access pattern; handles potential buffer bounds by clamping
    int stride = 2;
    int adjusted_next = (next % stride == 0) ? next : next + 1; // Align to stride
    uint8_t *buf = pc->buffer + pc->last_index;

    for (; adjusted_next < 0; adjusted_next += stride) {
        int idx = adjusted_next + stride - 1; // Access the prior element in stride
        if (idx >= -16) { // Artificial bound to prevent excessive overread
            uint8_t byte = buf[idx];
            pc->state = pc->state << 8 | byte;
            pc->state64 = pc->state64 << 8 | byte;
            pc->overread++;
        }
    }
    next = adjusted_next; // Update next accordingly
}
