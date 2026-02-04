#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float OPJ_FLOAT32;
typedef uint32_t OPJ_UINT32;

OPJ_FLOAT32 *fw;
OPJ_FLOAT32 c;
OPJ_UINT32 i;
OPJ_UINT32 imax;

static OPJ_FLOAT32 *fw_base;
static size_t data_size;
static size_t alignment = 32;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB of data
    size_t num_elements = data_size / sizeof(OPJ_FLOAT32);
    
    // Allocate aligned memory to ensure proper alignment and avoid UB
    fw_base = (OPJ_FLOAT32*)aligned_alloc(alignment, data_size);
    if (!fw_base) {
        exit(1);
    }
    
    // Initialize array elements to prevent undefined behavior in computations
    for (size_t idx = 0; idx < num_elements; ++idx) {
        fw_base[idx] = (OPJ_FLOAT32)(idx % 100) / 100.0f;
    }
    
    // Set up loop variables
    c = 0.5f;
    i = 0;
    
    // Ensure that the loop accesses: fw[-2] to fw[6], so we need at least:
    // - Index range: [-2, current + 6] relative to initial fw
    // Reserve space: leave at least 2 elements at the beginning for negative indexing
    fw = fw_base + 2;
    
    // Maximum number of iterations: each iteration increases i by 4
    // We require: i + 3 < imax  =>  i < imax - 3
    // So imax should be such that after final step, i+3 >= imax
    // Let’s allow about (num_elements - 8) / 2 steps? But bound by vector width.
    
    // Each step moves fw by 8, and uses indices up to +6 beyond current fw
    // So after k steps: fw = fw_initial + 8*k, and accesses up to (fw_initial + 8*k + 6)
    // Also requires: fw[-2] valid -> fw must be >= fw_base + 2 (already ensured)
    
    // Max k such that: 8*k + 6 < (num_elements - 2) [since base has +2 offset]
    // => 8*k < num_elements - 8 => k < (num_elements - 8)/8
    // Then max i is 4*k, so set imax = 4*k + 4 to allow all k iterations
    OPJ_UINT32 max_steps = (num_elements - 8) / 8;
    imax = 4 * max_steps + 3; // ensures last i where i+3 < imax is within bounds
}