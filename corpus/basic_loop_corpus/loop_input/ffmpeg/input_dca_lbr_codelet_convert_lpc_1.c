#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float lpc_tab[16];

float *coeff;
int *codes;
int i;
int j;

void init_vars() {
    // Allocate and initialize lpc_tab
    for (int idx = 0; idx < 16; idx++) {
        lpc_tab[idx] = 0.1f * idx;
    }

    // Determine size: we want the loop to run in ~0.01 seconds.
    // The inner loop runs about O(i^2) operations, total over i=0..7 is small (~12 ops per i, 96 total).
    // So the bottleneck is negligible unless coeff is large. But the loop only accesses indices up to i (max 7).
    // However, to meet data size requirement of 1MB–256MB, we need to allocate large arrays even if not fully used.

    // But note: the loop only uses coeff[0] to coeff[7], and codes[0] to codes[7].
    // To satisfy the data size requirement without affecting correctness, we can pad the heap usage elsewhere.
    // However, the problem says "data size that ensures the original loop runs in approximately 0.01 seconds".
    // Since the loop is fixed (i<8), its runtime is constant regardless of data size beyond that.
    // Therefore, to make it take ~0.01s, we must scale the work — but the loop bounds are fixed.

    // Interpretation: perhaps the external context intends this loop to be part of a larger processing,
    // but here we are only given this code. We must satisfy both constraints:
    // - Memory access does not go out of bounds.
    // - Total data size between 1MB and 256MB.

    // Since the actual loop uses only 8 elements of codes and 8+1 elements of coeff,
    // we can allocate large arrays and let the rest be unused.

    // Let's allocate 1MB / sizeof(float) ≈ 262,144 floats for coeff, but ensure at least 8 are available.
    const size_t min_coeff_size = 8;
    const size_t desired_data_size = 1 << 20; // 1MB
    const size_t float_count = desired_data_size / sizeof(float);
    const size_t coeff_alloc_size = float_count > min_coeff_size ? float_count : min_coeff_size;

    coeff = (float*)malloc(coeff_alloc_size * sizeof(float));
    for (size_t idx = 0; idx < coeff_alloc_size; idx++) {
        coeff[idx] = 1.0f + 0.01f * (idx % 100);
    }

    // Similarly for codes: needs 8 ints
    const size_t min_codes_size = 8;
    const size_t int_count = desired_data_size / sizeof(int);
    const size_t codes_alloc_size = int_count > min_codes_size ? int_count : min_codes_size;

    codes = (int*)malloc(codes_alloc_size * sizeof(int));
    for (size_t idx = 0; idx < codes_alloc_size; idx++) {
        codes[idx] = idx % 16; // ensures lpc_tab[codes[i]] is within [0,15]
    }

    // Initialize i and j to safe values (loop will set them anyway)
    i = 0;
    j = 0;
}