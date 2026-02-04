#include <stdio.h>

#include <inttypes.h>

typedef struct ossl_qtx_iovec_st {
    const unsigned char *buf;
    size_t buf_len;
} OSSL_QTX_IOVEC;

extern size_t len;
extern OSSL_QTX_IOVEC *iov;
extern size_t num_iov;
extern size_t running;
extern size_t i;
extern size_t iovlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential i++, use a stride of 2, processing elements with even indices first,
    // then handle odd indices in a second pass if needed. Here we simulate a strided access
    // by unrolling the loop behavior with step size 2, assuming num_iov is even for simplicity.
    size_t stride = 2;
    size_t limit = (num_iov + stride - 1) / stride; // Ceiling division for full coverage

    running = 0;
    for (i = 0; i < limit; ++i) {
        size_t idx1 = i * stride;
        size_t idx2 = idx1 + 1;

        if (idx1 < num_iov) {
            iovlen = iov[idx1].buf_len;
            if (running >= len)
                iov[idx1].buf_len = 0;
            else if (running + iovlen > len)
                iov[idx1].buf_len = len - running;
            running += iovlen;
        }

        if (idx2 < num_iov) {
            iovlen = iov[idx2].buf_len;
            if (running >= len)
                iov[idx2].buf_len = 0;
            else if (running + iovlen > len)
                iov[idx2].buf_len = len - running;
            running += iovlen;
        }
    }
}
