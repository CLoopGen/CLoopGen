#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct ossl_qtx_iovec_st {
    const unsigned char *buf;
    size_t buf_len;
} OSSL_QTX_IOVEC;

OSSL_QTX_IOVEC *iovecin;
size_t numin;
size_t i;
size_t bufsz;

static unsigned char **generated_bufs;
static size_t *generated_lengths;

void init_vars() {
    numin = 8192;
    iovecin = malloc(numin * sizeof(OSSL_QTX_IOVEC));
    generated_bufs = malloc(numin * sizeof(unsigned char*));
    generated_lengths = malloc(numin * sizeof(size_t));

    bufsz = 0;

    for (size_t idx = 0; idx < numin; idx++) {
        size_t len = 64 + (idx % 129); // Length between 64 and 192 bytes
        unsigned char *buf = malloc(len);
        for (size_t j = 0; j < len; j++) {
            buf[j] = (unsigned char)(j % 256);
        }
        generated_bufs[idx] = buf;
        generated_lengths[idx] = len;
        iovecin[idx].buf = buf;
        iovecin[idx].buf_len = len;
    }
}