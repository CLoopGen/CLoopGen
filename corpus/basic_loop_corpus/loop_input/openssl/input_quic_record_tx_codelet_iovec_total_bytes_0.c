#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct ossl_qtx_iovec_st {
    const unsigned char *buf;
    size_t buf_len;
} OSSL_QTX_IOVEC;

OSSL_QTX_IOVEC *iovec;
size_t num_iovec;
size_t i;
size_t l;

void init_vars() {
    num_iovec = 512;
    iovec = malloc(num_iovec * sizeof(OSSL_QTX_IOVEC));
    for (size_t idx = 0; idx < num_iovec; ++idx) {
        size_t len = 256;
        unsigned char *buf = malloc(len);
        for (size_t j = 0; j < len; ++j)
            buf[j] = (unsigned char)(j & 0xFF);
        iovec[idx].buf = buf;
        iovec[idx].buf_len = len;
    }
    i = 0;
    l = 0;
}