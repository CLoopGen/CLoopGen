#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct ossl_qtx_iovec_st {
    const unsigned char *buf;
    size_t buf_len;
} OSSL_QTX_IOVEC;

OSSL_QTX_IOVEC *iov;
size_t iov_len;
size_t i;
size_t total_len;

void init_vars() {
    iov_len = 8192;
    iov = malloc(iov_len * sizeof(OSSL_QTX_IOVEC));
    if (!iov) return;

    for (size_t idx = 0; idx < iov_len; ++idx) {
        size_t len = 16 + (idx % 15); // Vary buffer length between 16 and 30
        unsigned char *buf = malloc(len);
        if (buf) {
            for (size_t j = 0; j < len; ++j)
                buf[j] = (unsigned char)(j % 256);
        }
        iov[idx].buf = buf;
        iov[idx].buf_len = len;
    }

    i = 0;
    total_len = 0;
}