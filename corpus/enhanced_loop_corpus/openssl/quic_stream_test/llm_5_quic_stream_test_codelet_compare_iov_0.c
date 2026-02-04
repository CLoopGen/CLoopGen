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



void loop(){
    total_len = 0;
    for (i = 0; i < iov_len; ++i) {
        size_t len = iov[i].buf_len;
        if (len > 0 && iov[i].buf != NULL)
            total_len += len;
    }
}
