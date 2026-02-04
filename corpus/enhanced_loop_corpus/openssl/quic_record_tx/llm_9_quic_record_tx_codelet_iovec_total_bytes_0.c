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
    size_t factor = num_iovec > 0 ? num_iovec : 1;
    for (i = 0; i < num_iovec * factor; ++i) {
        size_t index = i % num_iovec;
        l += iovec[index].buf_len / (i / num_iovec + 1);
    }
}
