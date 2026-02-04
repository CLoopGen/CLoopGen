#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

uint8_t *l;
int bytesperpixel;
int n_px_need;
int i;
uint8_t *dst;
ptrdiff_t stride;

#define DATA_SIZE (128 << 20) // 128 MB total data

static uint8_t *buffer_l;
static uint8_t *buffer_dst;

void init_vars() {
    // Set parameters
    bytesperpixel = 2; // choose 2 for wider coverage of both branches
    n_px_need = DATA_SIZE / (bytesperpixel * 2); // ensure we have enough pixels in buffer
    if (n_px_need == 0) n_px_need = 1;
    
    stride = bytesperpixel;

    // Allocate buffers with sufficient size to prevent out-of-bounds access
    // l needs at least n_px_need * (bytesperpixel==2 ? 2 : 1)
    // dst needs at least (n_px_need * stride) + abs(stride) for negative indexing
    size_t l_size = (size_t)n_px_need * bytesperpixel;
    size_t dst_size = (size_t)n_px_need * stride + stride;

    buffer_l = (uint8_t*)aligned_alloc(32, l_size);
    buffer_dst = (uint8_t*)aligned_alloc(32, dst_size);

    if (!buffer_l || !buffer_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers to zero (or any safe value)
    for (size_t idx = 0; idx < l_size; idx++) {
        buffer_l[idx] = 0;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        buffer_dst[idx] = (uint8_t)(idx & 0xFF);
    }

    // Assign external pointers
    l = buffer_l + (bytesperpixel == 1 ? 0 : 1); // offset allowed as long as in bounds
    dst = buffer_dst + stride; // ensure dst[-stride] is valid
}