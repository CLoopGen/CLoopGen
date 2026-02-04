#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct ossl_qtx_iovec_st {
    const unsigned char *buf;
    size_t buf_len;
} OSSL_QTX_IOVEC;

size_t len;
OSSL_QTX_IOVEC *iov;
size_t num_iov;
size_t running;
size_t i;
size_t iovlen;

static unsigned char *buf_storage;
static OSSL_QTX_IOVEC *iov_storage;

void init_vars() {
    // Set total data size to around 512KB for ~0.01s runtime on modern CPU
    len = 512 * 1024;
    num_iov = 1000;  // Number of iovec entries

    // Allocate storage for buffer contents
    buf_storage = (unsigned char *)calloc(num_iov, 1024);
    if (!buf_storage) exit(1);

    // Allocate and initialize iovec array
    iov_storage = (OSSL_QTX_IOVEC *)malloc(num_iov * sizeof(OSSL_QTX_IOVEC));
    if (!iov_storage) exit(1);

    for (size_t idx = 0; idx < num_iov; ++idx) {
        size_t actual_len = 1024;  // Each buffer has 1024 bytes
        iov_storage[idx].buf = &buf_storage[idx * 1024];
        iov_storage[idx].buf_len = actual_len;
    }

    iov = iov_storage;
    running = 0;
    i = 0;
    iovlen = 0;
}