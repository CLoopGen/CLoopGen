#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct PayloadContext {
    int block_type;
    int block_size;
    int subpkts_per_block;
    uint16_t len[128];
    uint8_t buf[128][2048];
    unsigned int cache;
    unsigned int n_pkts;
    uint32_t timestamp;
};

typedef struct PayloadContext PayloadContext;

PayloadContext *qdm;
int n;

void init_vars() {
    qdm = (PayloadContext*)calloc(1, sizeof(PayloadContext));
    if (!qdm) exit(1);

    qdm->block_type = 0;
    qdm->block_size = 2048;
    qdm->subpkts_per_block = 1;
    qdm->cache = 0;
    qdm->n_pkts = 0;
    qdm->timestamp = 0;

    for (int i = 0; i < 128; i++) {
        qdm->len[i] = (i % 2 == 0) ? (i + 1) : 0;
        for (int j = 0; j < 2048; j++) {
            qdm->buf[i][j] = (uint8_t)(i * j + 1);
        }
    }

    n = 0;
}