#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

uint8_t *d;
ptrdiff_t stride;
int y;
uint64_t a;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    d = aligned_alloc(64, data_size);
    if (!d) exit(1);

    stride = sizeof(uint64_t); // Ensure alignment and access within bounds
    a = 0xdeadbeefdeadbeefULL;

    // Ensure loop from 0 to 7 accesses only within allocated memory: 8 * stride <= data_size
}