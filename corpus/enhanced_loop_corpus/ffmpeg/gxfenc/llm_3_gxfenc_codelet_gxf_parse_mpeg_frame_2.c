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



void loop() {
    // Variant 2: Consecutive dual-byte lookahead access pattern with unrolled check
    uint32_t local_c = c;
    int limit = size - 6; // Adjust bound to allow lookahead up to i+4 safely
    for (i = 0; i <= limit && local_c != 256; ) {
        // Process consecutive bytes and unroll part of the logic for performance
        local_c = (local_c << 8) | buf[i++];
        if (local_c == 440 && sc->first_gop_closed == -1) {
            sc->first_gop_closed = (buf[i + 3] >> 6) & 1; // i was incremented, so offset is now i+3
        }
        // Optional second update per iteration (simulates consecutive dense checking)
        if (i <= limit && local_c != 256) {
            local_c = (local_c << 8) | buf[i++];
            if (local_c == 440 && sc->first_gop_closed == -1) {
                sc->first_gop_closed = (buf[i + 2] >> 6) & 1;
            }
        }
    }
    c = local_c;
}
