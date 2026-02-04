#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 65536;
uint16_t *top;
int top_right_size = 1024;
uint64_t pix = 0xCAFEBABECAFEBABEULL;

void init_vars() {
    top = (uint16_t*)aligned_alloc(8, (size + top_right_size + 65536) * sizeof(uint16_t));
    if (!top) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}

__attribute__((destructor))
void cleanup() {
    if (top) {
        free(top);
    }
}