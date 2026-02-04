#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
int dc3;
int dc4;
uint16_t *src;

void init_vars() {
    // Allocate a sufficiently large buffer to make the loop take ~0.01 seconds
    // Assuming moderate CPU speed and cache effects, aim for ~64MB of data
    const size_t total_size = 1 << 23; // 8M elements * 2 bytes = 16MB
    src = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));
    if (!src) exit(1);

    // Initialize buffer to avoid undefined behavior during accumulation
    for (size_t idx = 0; idx < total_size; ++idx) {
        src[idx] = (uint16_t)(idx % 512);
    }

    // Set stride to a reasonable value to ensure memory accesses are in bounds
    // The maximum index used: -1 + (i + 12)*stride where i goes up to 3 => -1 + 15*stride
    // We require: 15*stride - 1 < total_size => stride < (total_size + 1)/15
    stride = (total_size + 1) / 16;  // conservative choice

    // Ensure base indices used in loop stay within valid range:
    // Access patterns:
    //   src[-1 + i * stride]           --> needs: -1 + 3*stride >= 0
    //   src[i - stride]                --> needs: 3 - stride >= 0? No — this would be negative!
    //
    // But wait: 'i - stride' when i=0 -> -stride, so we must shift base pointer
    // so that negative indexing stays within allocated block.
    //
    // Solution: shift src pointer forward by at least 'stride' elements
    // Rebase src so that negative indices are valid
    uint16_t* base = src;
    src += stride;  // Now index [-stride ... total_size - stride] is valid

    // Reset accumulators
    dc0 = dc1 = dc2 = dc3 = dc4 = 0;
}