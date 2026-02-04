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

typedef struct MJPEGParserContext {
    ParseContext pc;
    int size;
} MJPEGParserContext;

extern MJPEGParserContext *m;
extern  uint8_t *buf;
extern int buf_size;
extern int vop_found;
extern int i;
extern uint32_t state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < buf_size && !vop_found; i++) {
        state = (state << 8) | buf[i];
        if ((state & 0xFFFFFF00) == 0xFFD8FF00 && (state & 0xFF) >= 0x00 && (state & 0xFF) <= 0x7F) {
            if ((state & 0xFFFF) == 0x01) {
                vop_found = 1;
                break;
            } else if ((state & 0xFFFFFF00) != 0xFFD8FF00 || (state & 0xFF) > 0x7F) {
                m->size = (state & 65535) - 1;
            }
        }
        if (m->size > 0) {
            int step = (buf_size - i) < m->size ? (buf_size - i) : m->size;
            i += step - 1;
            m->size -= step;
            state = 0;
        }
    }
}
