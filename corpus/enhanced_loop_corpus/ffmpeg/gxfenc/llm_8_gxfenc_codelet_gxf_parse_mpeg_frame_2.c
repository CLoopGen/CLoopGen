#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct GXFStreamContext {
    int64_t pkt_cnt;
    uint32_t track_type;
    uint32_t sample_size;
    uint32_t sample_rate;
    uint16_t media_type;
    uint16_t media_info;
    int frame_rate_index;
    int lines_index;
    int fields;
    int iframes;
    int pframes;
    int bframes;
    int p_per_gop;
    int b_per_i_or_p;
    int first_gop_closed;
    unsigned int order;
} GXFStreamContext;

extern GXFStreamContext *sc;
extern  uint8_t *buf;
extern int size;
extern uint32_t c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size - 8 && c != 256; i += 2) {
        c = (c << 16) + (buf[i] << 8) + buf[i + 1];
        if (c == 440 && sc->first_gop_closed == -1)
            sc->first_gop_closed = (buf[i + 8] >> 6) & 1;
    }
}
