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
    // Variant 1: Strided memory access with step size of 2 (access every second byte)
    state = 0;
    for (i = 0; i < buf_size; i += 2) {
        if (i + 1 < buf_size) {
            // Load two bytes in reverse order to maintain some continuity in state buildup
            state = (state << 16) | (buf[i] << 8) | buf[i + 1];
        } else {
            // Handle odd-sized buffer boundary
            state = (state << 8) | buf[i];
        }
        if ((state & 18446462603027808000UL) == 9223372036906288128ULL) {
            int channels = state & 255;
            int header_size = ((state >> 32) & 65535) + 4;
            if (channels > 0 && header_size >= 8) {
                s->header_size = header_size;
                s->block_size = 18 * channels;
                s->remaining = i - 7 + s->header_size + s->block_size;
                break;
            }
        }
    }
}
