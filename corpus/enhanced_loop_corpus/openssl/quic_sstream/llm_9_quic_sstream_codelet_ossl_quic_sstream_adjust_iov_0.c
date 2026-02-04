#include <stdio.h>

#include <inttypes.h>

typedef struct ossl_qtx_iovec_st {
    const unsigned char *buf;
    size_t buf_len;
} OSSL_QTX_IOVEC;

extern size_t len;
extern OSSL_QTX_IOVEC *iov;
extern size_t num_iov;
extern size_t running;
extern size_t i;
extern size_t iovlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_len = 0;
    for (i = 0; i < num_iov; ++i) {
        temp_len = iov[i].buf_len;
        running += temp_len;
        if (running > len) {
            iov[i].buf_len = (running - temp_len >= len) ? 0 : (len - (running - temp_len));
        }
    }
    for (i = 0; i < num_iov; ++i) {
        if (iov[i].buf_len > len) {
            iov[i].buf_len = len;
        }
    }
}
