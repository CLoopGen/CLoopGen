#include <stdio.h>

#include <inttypes.h>

typedef struct ossl_qtx_iovec_st {
    const unsigned char *buf;
    size_t buf_len;
} OSSL_QTX_IOVEC;

extern  OSSL_QTX_IOVEC *iovec;
extern size_t num_iovec;
extern size_t i;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < num_iovec; i += 2)
        l += iovec[i].buf_len;
    // Handle odd-sized iovec by processing the last element if needed
    if (num_iovec % 2 == 1) {
        l += iovec[num_iovec - 1].buf_len;
    }
}
