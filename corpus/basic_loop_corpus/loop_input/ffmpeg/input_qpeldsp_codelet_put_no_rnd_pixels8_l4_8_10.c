#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
uint8_t *src3;
uint8_t *src4;
int dst_stride;
int src_stride1;
int src_stride2;
int src_stride3;
int src_stride4;
int h;
int i;

static uint8_t *alloc_aligned_size(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return (uint8_t *)ptr;
}

void init_vars() {
    const int element_size = 8; 
    const int total_data_size = 64 * 1024 * 1024; 
    const int num_elements = total_data_size / element_size;

    h = num_elements;

    dst_stride = element_size;
    src_stride1 = element_size;
    src_stride2 = element_size;
    src_stride3 = element_size;
    src_stride4 = element_size;

    size_t dst_size = h * dst_stride;
    size_t src_size = h * element_size;

    dst = alloc_aligned_size(dst_size);
    src1 = alloc_aligned_size(src_size);
    src2 = alloc_aligned_size(src_size);
    src3 = alloc_aligned_size(src_size);
    src4 = alloc_aligned_size(src_size);

    for (int idx = 0; idx < src_size; idx++) {
        src1[idx] = rand() & 0xFF;
        src2[idx] = rand() & 0xFF;
        src3[idx] = rand() & 0xFF;
        src4[idx] = rand() & 0xFF;
    }

    memset(dst, 0, dst_size);
}