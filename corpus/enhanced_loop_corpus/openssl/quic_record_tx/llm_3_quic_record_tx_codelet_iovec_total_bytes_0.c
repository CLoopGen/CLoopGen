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
    // Variant 2: Indirect memory access using an index remapping array (simulated via reverse order traversal)
    size_t j;
    for (j = 0; j < num_iovec; ++j) {
        size_t idx = num_iovec - 1 - j; // Access elements in reverse order
        l += iovec[idx].buf_len;
    }
}
