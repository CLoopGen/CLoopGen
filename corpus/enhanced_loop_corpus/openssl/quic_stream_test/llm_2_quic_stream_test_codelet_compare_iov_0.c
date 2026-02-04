#include <stdio.h>

#include <inttypes.h>

typedef struct ossl_qtx_iovec_st {
    const unsigned char *buf;
    size_t buf_len;
} OSSL_QTX_IOVEC;

extern  OSSL_QTX_IOVEC *iov;
extern size_t iov_len;
extern size_t i;
extern size_t total_len;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Access every second element forward, then handle remaining elements in a second pass
    size_t stride = 2;
    total_len = 0;

    // First pass: strided access (every 'stride' elements starting from 0)
    for (i = 0; i < iov_len; i += stride)
        total_len += iov[i].buf_len;

    // Second pass: handle odd indices if stride > 1 and iov_len is not aligned
    for (i = 1; i < iov_len; i += stride)
        total_len += iov[i].buf_len;
}
