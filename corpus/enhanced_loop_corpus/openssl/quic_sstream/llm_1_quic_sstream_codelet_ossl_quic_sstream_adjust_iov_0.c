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
    if (num_iov > 0) {
        i = 0;
        running = 0;
        goto LOOP_CHECK;
LOOP_BODY:
        iovlen = iov[i].buf_len;
        if (running >= len)
            iov[i].buf_len = 0;
        else if (running + iovlen > len)
            iov[i].buf_len = len - running;
        running += iovlen;
        ++i;
LOOP_CHECK:
        if (i < num_iov) goto LOOP_BODY;
    }
}
