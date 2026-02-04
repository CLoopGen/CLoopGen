#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

typedef enum {
    PACK_ORDER_LITTLE = 0,
    PACK_ORDER_BIG
} PACK_ORDER;

char *inptr;
npy_intp element_size;
npy_intp in_stride;
char *outptr;
npy_intp n_out;
npy_intp out_stride;
PACK_ORDER order;
npy_intp _usr_index;
int remain;

#define index _usr_index

static char *in_buffer = NULL;
static char *out_buffer = NULL;

void init_vars() {
    const size_t total_input_bytes = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    element_size = 1; // Each element is 1 byte
    in_stride = 1;
    out_stride = 1;
    n_out = total_input_bytes / element_size / 8 + ((total_input_bytes / element_size) % 8 != 0);
    remain = (total_input_bytes / element_size) % 8;
    if (remain == 0) remain = 8;
    order = PACK_ORDER_LITTLE; // Can be switched, using little-endian as default
    index = 0;

    in_buffer = (char *)aligned_alloc(64, total_input_bytes);
    out_buffer = (char *)aligned_alloc(64, n_out);

    if (!in_buffer || !out_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize input with pseudo-random but deterministic data
    for (size_t i = 0; i < total_input_bytes; i++) {
        in_buffer[i] = (char)((i * 7381 + 445) & 0xFF);
    }
    memset(out_buffer, 0, n_out);

    inptr = in_buffer;
    outptr = out_buffer;
}