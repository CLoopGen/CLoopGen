#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

GXFStreamContext *sc;
uint8_t *buf;
int size;
uint32_t c;
int i;

void init_vars() {
    size = 67108864; // 64MB, tuned to run ~0.01s on modern CPU

    buf = (uint8_t*)malloc(size);
    if (!buf) {
        fprintf(stderr, "Failed to allocate buffer\n");
        exit(1);
    }

    memset(buf, 0, size);
    
    sc = (GXFStreamContext*)malloc(sizeof(GXFStreamContext));
    if (!sc) {
        fprintf(stderr, "Failed to allocate GXFStreamContext\n");
        exit(1);
    }

    memset(sc, 0, sizeof(GXFStreamContext));
    sc->first_gop_closed = -1;

    c = 0;
    i = 0;

    buf[size - 5] = 0;
    buf[size - 4] = 0;
    buf[size - 3] = 1;
    buf[size - 2] = 192;
    buf[size - 1] = 0;

    c = 0;
    for (int j = 0; j < 3; j++) {
        c = (c << 8) + buf[j];
    }
}