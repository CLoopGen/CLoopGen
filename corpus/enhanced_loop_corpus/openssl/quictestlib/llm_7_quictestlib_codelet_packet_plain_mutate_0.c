#include <stdio.h>

#include <inttypes.h>

typedef struct ossl_qtx_iovec_st {
    const unsigned char *buf;
    size_t buf_len;
} OSSL_QTX_IOVEC;

extern  OSSL_QTX_IOVEC *iovecin;
extern size_t numin;
extern size_t i;
extern size_t bufsz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_sum = 0;
    for (i = 0; i < numin; i++) {
        local_sum += iovecin[i].buf_len;
        bufsz = local_sum; // Introduce WAW dependency on `bufsz`, making it loop-carried
    }
}
