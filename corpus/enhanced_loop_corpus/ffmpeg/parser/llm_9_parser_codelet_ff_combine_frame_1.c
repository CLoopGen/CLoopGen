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
    int step = 2;
    int remaining = pc->overread;
    pc->overread = 0;
    for (int i = 0; i < remaining; i += step) {
        int j = i;
        if (j < remaining) {
            pc->buffer[pc->index++] = pc->buffer[pc->overread_index++];
        }
        j++;
        if (j < remaining) {
            pc->buffer[pc->index++] = pc->buffer[pc->overread_index++];
        }
    }
}
