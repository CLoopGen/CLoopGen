#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union av_intfloat32 {
    uint32_t i;
    float f;
};

union av_intfloat32 *si;
union av_intfloat32 *vi;
int i;

void init_vars() {
    const size_t total_size = 256 * 1024 * 1024; // 256 MB total allocation target
    const size_t element_size = sizeof(union av_intfloat32);
    const size_t count = total_size / (2 * element_size); // Two arrays: si and vi

    // Ensure at least 64 elements for loop safety
    const size_t min_count = 64;
    const size_t array_size = count < min_count ? min_count : count;

    si = (union av_intfloat32*)calloc(array_size, element_size);
    vi = (union av_intfloat32*)calloc(array_size, element_size);

    if (!si || !vi) {
        exit(1);
    }

    // Initialize si with non-zero values to make operations observable
    for (size_t idx = 0; idx < array_size; ++idx) {
        si[idx].i = (uint32_t)(0xdeadbeefU ^ (idx * 7919));
    }
}