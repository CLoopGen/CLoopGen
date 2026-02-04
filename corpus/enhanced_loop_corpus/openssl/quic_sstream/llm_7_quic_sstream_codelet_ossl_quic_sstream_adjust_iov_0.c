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
    size_t local_len = len;
    size_t update_running = 0;
    OSSL_QTX_IOVEC *local_iov = iov;
    size_t local_num_iov = num_iov;

    for (i = 0; i < local_num_iov; ++i) {
        size_t current_len = local_iov[i].buf_len;
        update_running += current_len;
        // Introduce artificial WAW dependency by updating buf_len twice in split logic
        if (update_running > local_len) {
            size_t overflow = update_running - local_len;
            size_t reduction = (current_len > overflow) ? overflow : current_len;
            local_iov[i].buf_len = current_len - reduction;
            update_running = local_len; // Clamp running to len
        }
        // No-else: buf_len remains unchanged if within limit
    }
    running = update_running;
}
