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

typedef struct ADXParseContext {
    ParseContext pc;
    int header_size;
    int block_size;
    int remaining;
} ADXParseContext;

extern  uint8_t *buf;
extern int buf_size;
extern ADXParseContext *s;
extern int i;
extern uint64_t state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via precomputed even indices)
    int *indices = malloc((buf_size + 1) / 2 * sizeof(int));
    int num_indices = 0;
    for (int temp_i = 0; temp_i < buf_size; temp_i++) {
        if (temp_i % 2 == 0) {
            indices[num_indices++] = temp_i;
        }
    }

    state = 0;
    for (i = 0; i < num_indices; i++) {
        int idx = indices[i];  // Indirect access via index array
        state = (state << 8) | buf[idx];
        if ((state & 18446462603027808000UL) == 9223372036906288128ULL) {
            int channels = state & 255;
            int header_size = ((state >> 32) & 65535) + 4;
            if (channels > 0 && header_size >= 8) {
                s->header_size = header_size;
                s->block_size = 18 * channels;
                s->remaining = idx - 7 + s->header_size + s->block_size;
                break;
            }
        }
    }

    free(indices);
}
