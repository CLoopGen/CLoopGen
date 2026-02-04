#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mode;
int x;
uint8_t *left;
int inv_angle[32];
uint8_t *ref_tmp;
int last;

void init_vars() {
    // Allocate large enough arrays to make the loop run ~0.01 seconds
    // Assuming each iteration takes a few cycles, we need around 10M-50M iterations for ~0.01s
    const size_t data_size = 16777216; // 16M elements (~16MB), adjust as needed

    // Allocate left and ref_tmp with padding to prevent out-of-bounds access
    left = (uint8_t*)aligned_alloc(32, data_size + 256);
    ref_tmp = (uint8_t*)aligned_alloc(32, data_size + 256);

    if (!left || !ref_tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data in left to non-zero
    for (size_t i = 0; i < data_size + 256; i++) {
        left[i] = (uint8_t)(i & 0xFF);
    }

    // Initialize ref_tmp
    for (size_t i = 0; i < data_size + 256; i++) {
        ref_tmp[i] = 0;
    }

    // Set mode to a valid index: mode - 11 must be within [0,31) for inv_angle
    mode = 11; // so inv_angle[mode - 11] = inv_angle[0]

    // Initialize inv_angle array to avoid division by zero or extreme values
    for (int i = 0; i < 32; i++) {
        inv_angle[i] = 256; // identity-like scaling: (x * 256 + 128) >> 8 = x or x+1
    }
    inv_angle[0] = 200; // example value to control step size

    // Set loop bounds: x from last to -1 inclusive, so last <= -1
    // To get many iterations, set last to a large negative number
    // We require: ref_tmp[x] is valid => x in [0, data_size+255]
    // But x <= -1, so we must map negative indices into valid memory range via pointer offset

    // Instead, shift the base pointers so that negative x accesses valid region
    // Let’s set up: ref_tmp points to middle of buffer so x=-1 accesses valid slot
    uint8_t* ref_base = ref_tmp;
    uint8_t* left_base = left;

    // Shift ref_tmp and left so that negative x can access positive offsets
    ref_tmp = ref_base + data_size;
    left = left_base + 128;

    // Now set last to start at a large negative index but still within bounds
    // x goes from last to -1 inclusive
    // We want: ref_tmp[x] valid => x >= -data_size (because ref_tmp = base + data_size)
    // So set last = - (number of iterations)
    last = -(1 << 20); // 1 million iterations
    if (last < -(ptrdiff_t)data_size) {
        last = -data_size;
    }

    // Ensure that during loop:
    // index = -1 + ((x * inv_angle[mode-11] + 128) >> 8)
    // must be within [0, data_size+255) for left[index]
    // With x in [last, -1], inv_angle[0]=200:
    // x * 200 ranges from last*200 to -200
    // Add 128 -> last*200+128 to -72
    // Right shift 8 -> (last*200+128)>>8 to -1
    // Then -1 + that -> (last*200+128)>>8 -1 to -2
    // This would be negative — invalid.

    // Adjust strategy: use positive scaling and shift base

    // Recompute safe parameters
    int scale = inv_angle[0]; // 200
    ptrdiff_t min_x = last;
    ptrdiff_t max_x = -1;

    // Compute index range:
    // idx = -1 + ((x * scale + 128) >> 8)
    // For x = -1: idx = -1 + ((-scale + 128) >> 8) = -1 + ((-72)>>8) = -1 + (-1) = -2 → bad

    // Need x*scale + 128 >= 0 to get non-negative shift result
    // So even for x=-1: -scale + 128 >= 0 → scale <= 128
    inv_angle[0] = 100; // reduce scale to 100

    // Now for x=-1: (-100 + 128) = 28 → 28>>8 = 0 → index = -1 + 0 = -1 → still bad

    // We must ensure left[-1 + ...] >= 0
    // So -1 + ((x * scale + 128)>>8) >= 0
    // → ((x * scale + 128)>>8) >= 1
    // → x * scale + 128 >= 256
    // → x >= (128) / scale
    // For scale=100 → x >= 1.28 → but x <= -1 → impossible

    // Therefore, we cannot satisfy this with x <= -1 unless scale is negative

    // Try negative scale
    inv_angle[0] = -200;

    // Then for x = last (large negative): x * -200 = large positive
    // For x = -1: x * -200 = 200 → +128 = 328 → >>8 = 1 → index = -1 + 1 = 0 → valid
    // For x = last = -1048576: x * -200 = 209715200 → +128 = 209715328 → >>8 = 820300 → index = 820299
    // That exceeds typical buffer

    // So limit last to small magnitude

    last = -1024; // only 1024 iterations

    // Max index: x = -1024: (-1024)*(-200) = 204800 +128 = 204928 >>8 = 800 → index = -1 + 800 = 799
    // So we need left[799] valid → allocate left with at least 800 bytes from base

    free(left_base);
    free(ref_base);

    left_base = (uint8_t*)aligned_alloc(32, 1024);
    ref_base = (uint8_t*)aligned_alloc(32, 1024);

    if (!left_base || !ref_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < 1024; i++) {
        left_base[i] = (uint8_t)(i & 0xFF);
        ref_base[i] = 0;
    }

    left = left_base;
    ref_tmp = ref_base;

    mode = 11;
    inv_angle[0] = -200;
    for (int i = 1; i < 32; i++) {
        inv_angle[i] = 256;
    }

    last = -1024;

    // Validate bounds:
    // x from -1024 to -1
    // index = -1 + ((x * -200 + 128) >> 8)
    // x=-1024: (-1024*-200)=204800 +128=204928 >>8 = 800 → index=799
    // x=-1: (-1*-200)=200 +128=328 >>8=1 → index=0
    // So index ranges from 0 to 799 → valid for left[0..1023]
    // ref_tmp[x]: x from -1024 to -1 → all negative → invalid!

    // Problem: ref_tmp[x] with x negative → out of bounds

    // Solution: shift ref_tmp base pointer forward so that ref_tmp[-1024] maps to valid address
    uint8_t* new_ref = (uint8_t*)aligned_alloc(32, 2048);
    if (!new_ref) exit(1);
    for (size_t i = 0; i < 2048; i++) {
        new_ref[i] = 0;
    }
    // Make ref_tmp point to middle so that negative indices are valid
    ref_tmp = new_ref + 1024; // now ref_tmp[-1024] = new_ref[0]

    free(ref_base);
}