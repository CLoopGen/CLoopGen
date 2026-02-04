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
    if (numin > 0) {
        i = 0;
        for (;;)
        {
            bufsz += iovecin[i].buf_len;
            i++;
            if (i >= numin) break;
        }
    }
}
