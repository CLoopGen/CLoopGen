#include <stdlib.h>
#include <math.h>

float *wf;
float vals[8];
int i;
int j;

void init_vars() {
    // Allocate approximately 128MB for wf to ensure sufficient data size
    // Total size: 32 + 16 + 4 = 52 used elements -> allocate much more to dominate runtime
    const size_t total_size = 32 * 1024 * 1024; // ~128MB of floats (each float 4 bytes)
    wf = (float*)aligned_alloc(32, total_size * sizeof(float));
    
    // Initialize all elements of wf with a simple arithmetic pattern to avoid math function calls
    for (size_t idx = 0; idx < total_size; ++idx) {
        wf[idx] = (float)(idx % 100) * 0.01f;
    }

    // Initialize vals array
    for (int k = 0; k < 8; ++k) {
        vals[k] = (float)(k + 1) * 0.1f;
    }

    // Ensure loop bounds are safe:
    // Inner loop j in [0,3], i in [0,3]
    // Access: wf[8 + i + (j << 2)] -> max index = 8 + 3 + (3 << 2) = 8 + 3 + 12 = 23
    // Also access wf[8 + 16 + i] = 24 + i -> max 27
    // So we need at least 28 elements in wf, which is satisfied by our large allocation.
}