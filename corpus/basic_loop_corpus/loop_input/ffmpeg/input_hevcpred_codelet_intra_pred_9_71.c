#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 32000000; // Ensures ~128MB of data access, approx. 0.01 sec on modern CPU
uint16_t *top;

uint64_t pix = 0xCAFEBABEDEADBEEFULL;

void init_vars() {
    top = (uint16_t*)aligned_alloc(8, (size + 32000000) * sizeof(uint16_t));
    if (!top) {
        exit(1);
    }
}