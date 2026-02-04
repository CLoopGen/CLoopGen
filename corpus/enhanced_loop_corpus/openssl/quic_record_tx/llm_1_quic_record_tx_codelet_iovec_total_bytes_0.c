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
    if (num_iovec > 0) {
        i = 0;
        for (; i < num_iovec; ++i)
            l += iovec[i].buf_len;
    }
}
