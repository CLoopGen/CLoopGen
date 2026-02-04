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
    for (; i < buf_size - 3; i += 4) {
        uint32_t s0 = (state << 8) | buf[i];
        uint32_t s1 = (s0 << 8) | buf[i+1];
        uint32_t s2 = (s1 << 8) | buf[i+2];
        state = (s2 << 8) | buf[i+3];

        uint32_t magic_be = ('X') | (('P') << 8) | (('D') << 16) | ((unsigned int)('S') << 24);
        uint32_t magic_le = ('S') | (('D') << 8) | (('P') << 16) | ((unsigned int)('X') << 24);

        if (state == magic_be || state == magic_le) {
            d->pc.frame_start_found = 1;
            d->is_be = (state == magic_be);
            d->index = 0;
            break;
        }
    }
}
