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
    size_t *indices = (size_t[]){0, 1, 2, 3}; // Example index map, assuming numin <= 4 for demonstration
    size_t limit = (numin < 4) ? numin : 4;   // Clamp to valid range of indices
    for (i = 0; i < limit; i++)
        bufsz += iovecin[indices[i]].buf_len;
}
