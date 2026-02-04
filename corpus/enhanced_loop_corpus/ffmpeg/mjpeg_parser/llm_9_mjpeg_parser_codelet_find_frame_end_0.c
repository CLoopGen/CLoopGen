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
    int stride = 4;
    for (i = 0; i <= buf_size - stride; i += stride) {
        uint32_t s0 = (state << 8) | buf[i];
        uint32_t s1 = (s0 << 8) | buf[i+1];
        uint32_t s2 = (s1 << 8) | buf[i+2];
        uint32_t s3 = (s2 << 8) | buf[i+3];

        uint32_t states[] = {s0, s1, s2, s3};
        int updated = 0;
        for (int j = 0; j < 4; j++) {
            uint32_t st = states[j];
            if (st >= 4290772992U && st <= 4294901759U) {
                if (st >= 4292411328U && st <= 4292411391U) {
                    vop_found = 1;
                    i += j;
                    updated = 1;
                    break;
                } else if (st < 4291821568U || st > 4292476927U) {
                    m->size = (st & 65535) - 1;
                }
            }
        }
        if (vop_found || updated) {
            state = 0;
            break;
        }
        if (m->size > 0) {
            int size = (buf_size - i) > m->size ? m->size : (buf_size - i);
            i += size - 1;
            m->size -= size;
            state = 0;
            continue;
        } else {
            state = s3;
        }
    }
    // Handle remaining bytes with scalar processing if needed
    for (; i < buf_size && !vop_found; i++) {
        state = (state << 8) | buf[i];
        if (state >= 4290772992U && state <= 4294901759U) {
            if (state >= 4292411328U && state <= 4292411391U) {
                vop_found = 1;
                break;
            } else if (state < 4291821568U || state > 4292476927U) {
                m->size = (state & 65535) - 1;
            }
        }
        if (m->size > 0) {
            int size = (buf_size - i) > m->size ? m->size : (buf_size - i);
            i += size - 1;
            m->size -= size;
            state = 0;
        }
    }
}
