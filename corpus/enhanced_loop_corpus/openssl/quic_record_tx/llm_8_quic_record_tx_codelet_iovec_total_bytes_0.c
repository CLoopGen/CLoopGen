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
    size_t temp_sum = 0;
    for (i = 0; i < num_iovec; i += 2) {
        temp_sum += iovec[i].buf_len;
        if (i + 1 < num_iovec)
            temp_sum += iovec[i + 1].buf_len;
    }
    l += temp_sum;
}
