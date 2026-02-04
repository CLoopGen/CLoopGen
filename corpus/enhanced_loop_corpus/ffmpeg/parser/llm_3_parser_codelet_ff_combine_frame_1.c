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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2, then fill in gaps)
    // Simulate a strided write pattern for data rearrangement (e.g., even indices first)
    int stride = 2;
    int remaining = pc->overread;
    uint8_t *src = pc->buffer + pc->overread_index;
    uint8_t *dst = pc->buffer + pc->index;

    // First pass: write every `stride`-th element
    int written = 0;
    for (int i = 0; i < remaining; i += stride) {
        dst[written++] = src[i];
    }
    // Second pass: fill in the rest (strided continuation)
    for (int i = 1; i < remaining && written < remaining; i += stride) {
        dst[written++] = src[i];
    }

    pc->index += pc->overread;
    pc->overread_index += pc->overread;
    pc->overread = 0;
}
