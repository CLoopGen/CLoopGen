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
    l = 0;
    for (i = 0; i < num_iovec; ++i) {
        size_t len = iovec[i].buf_len;
        if (len > 0 && (len % 2 == 0))
            l += len;
        else if (len > 0)
            l += len + 1;
    }
}
