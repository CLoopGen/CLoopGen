#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *buf;
ptrdiff_t dpitch;
int16_t *ref_buf;
ptrdiff_t pitch;
int i;
int j;

static int16_t *buf_data;
static int16_t *ref_buf_data;
static ptrdiff_t buffer_height;

void init_vars() {
    const int block_size = 4;
    buffer_height = 65536; // Ensures sufficient iterations for ~0.01 sec runtime
    ptrdiff_t width = 4;

    dpitch = width;
    pitch = width;

    size_t buf_size = (size_t)buffer_height * width * sizeof(int16_t);

    buf_data = aligned_alloc(32, buf_size);
    ref_buf_data = aligned_alloc(32, buf_size);

    if (!buf_data || !ref_buf_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < buf_size / sizeof(int16_t); idx++) {
        ref_buf_data[idx] = (int16_t)(idx & 0xFFFF);
    }

    buf = buf_data;
    ref_buf = ref_buf_data;
}