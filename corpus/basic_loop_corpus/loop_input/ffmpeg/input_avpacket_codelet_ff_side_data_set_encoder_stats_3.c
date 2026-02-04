#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int64_t *error;
int error_count;
uint8_t *side_data;
int i;

void init_vars() {
    // Aim for approximately 0.01 seconds of runtime
    // Assuming typical modern CPU can handle ~1e8 operations per second,
    // we target around 1e6 to 1e7 iterations for memory-bound operation.
    // Let's choose 2^20 (~1M) elements, which is about 8MB of data.

    const size_t data_size = 1 << 20;  // 1,048,576 elements
    error_count = (int)data_size;

    // Allocate error array: int64_t values
    error = (int64_t*)aligned_alloc(_Alignof(int64_t), sizeof(int64_t) * data_size);
    if (!error) exit(1);

    // side_data needs at least 8 + 8 * (error_count - 1) + 8 bytes = 8 * error_count + 8
    size_t side_data_size = 8 * data_size + 8;
    side_data = (uint8_t*)aligned_alloc(_Alignof(uint64_t), side_data_size);
    if (!side_data) exit(1);

    // Initialize error with non-zero values for meaningful test
    for (size_t idx = 0; idx < data_size; ++idx) {
        error[idx] = (int64_t)(idx * 31);  // Arbitrary pattern
    }

    // Zero-initialize side_data to avoid garbage
    for (size_t idx = 0; idx < side_data_size; ++idx) {
        side_data[idx] = 0;
    }
}