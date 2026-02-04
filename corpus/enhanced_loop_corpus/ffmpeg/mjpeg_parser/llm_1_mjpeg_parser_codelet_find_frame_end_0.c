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
    for (i = 0; i < buf_size && !(vop_found); ) {
        state = (state << 8) | buf[i];
        if (state >= 4290772992U && state <= 4294901759U) {
            if (state >= 4292411328U && state <= 4292411391U) {
                i++;
                vop_found = 1;
            } else if (state < 4291821568U || state > 4292476927U) {
                m->size = (state & 65535) - 1;
            }
        }
        if (m->size > 0 && !vop_found) {
            for (int j = 0; j < m->size && i < buf_size; j++) {
                i++;
                m->size--;
                if (i >= buf_size || m->size == 0) {
                    state = 0;
                    break;
                }
            }
        } else if (!vop_found) {
            i++;
        }
    }
}
