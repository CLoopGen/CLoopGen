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
    // Variant 2: Indirect Memory Access Pattern via Index Remapping
    // Use an auxiliary array to define the order of accessing iov elements.
    // This simulates indirect access (e.g., gather pattern). For demonstration,
    // we create a simple reverse-order index map without dynamic allocation.
    // Assume we have a precomputed permutation array `perm` of size num_iov.
    // Since we cannot allocate memory, simulate indirect access using arithmetic.

    running = 0;
    // Traverse iov in reverse order (indirect access pattern)
    for (i = 0; i < num_iov; ++i) {
        size_t idx = num_iov - 1 - i;  // Reverse indexing: indirect access
        iovlen = iov[idx].buf_len;
        if (running >= len)
            iov[idx].buf_len = 0;
        else if (running + iovlen > len)
            iov[idx].buf_len = len - running;
        running += iovlen;
    }
}
