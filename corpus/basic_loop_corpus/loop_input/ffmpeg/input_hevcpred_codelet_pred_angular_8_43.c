#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mode;
int x;
uint8_t *top;
int inv_angle[16]; // Assuming max index: mode-11, so need sufficient size
uint8_t *ref_tmp;
int last;

static uint8_t top_buffer[131072];   // 128 KB buffer for top
static uint8_t ref_tmp_buffer[131072]; // 128 KB buffer for ref_tmp

void init_vars() {
    // Set mode to a valid index such that mode-11 is within [0,15] range
    mode = 12;  // so inv_angle[mode-11] = inv_angle[1]

    // Initialize inv_angle array with non-zero values to avoid undefined behavior
    for (int i = 0; i < 16; i++) {
        inv_angle[i] = (i + 1) * 256; // e.g., 256, 512, ... to produce meaningful offsets
    }

    // Set top and ref_tmp to point to our allocated buffers
    top = top_buffer;
    ref_tmp = ref_tmp_buffer;

    // Set loop bounds: last to -1 inclusive, so loop runs from x = last to x <= -1
    // To ensure positive number of iterations: set last <= -1
    last = -1024; // This will make the loop run 1024 times

    // Ensure memory accesses are safe:
    // Access in loop: top[-1 + ((x * inv_angle[mode-11] + 128) >> 8)]
    // With x in [-1024, -1], inv_angle[1] = 512:
    //   offset = ((x * 512 + 128) >> 8) = (x*2 + 0.5) ~ x*2
    //   so index into top: -1 + (approx x*2), x from -1024 to -1 => index from ~-2049 to -3
    // We need to shift base pointer to allow negative indexing

    // Allocate extra space at beginning; adjust top to point mid-buffer
    uint8_t *safe_top = top_buffer + 2048; // Reserve first 2048 bytes for negative indices
    top = safe_top;

    // Now index: -1 + ((x * inv_angle[mode-11] + 128) >> 8)
    // x = -1024: offset = (-1024*512 + 128)>>8 = (-524288 + 128)>>8 = -524160>>8 = -2047.5 -> -2048
    // index = -1 -2048 = -2049 -> safe_top[-2049] = top_buffer[2048 - 2049] = top_buffer[-1] -> invalid
    // So we need even more headroom.

    // Re-adjust: use larger buffer and shift base further
    static uint8_t large_top_buffer[32768]; // 32 KB
    top = large_top_buffer + 4096; // Allow up to -4096 offset safely

    static uint8_t large_ref_tmp_buffer[4096];
    ref_tmp = large_ref_tmp_buffer + 1024; // Allow x from -1024 to -1: ref_tmp[x] -> [-1024,-1]

    last = -1024;

    // Zero-initialize arrays to prevent undefined behavior
    for (int i = 0; i < 16; i++) {
        inv_angle[i] = (i + 1) * 256;
    }
}