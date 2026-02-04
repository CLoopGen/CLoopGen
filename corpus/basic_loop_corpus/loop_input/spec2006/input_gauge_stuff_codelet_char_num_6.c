#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *chr;
int length;
int j;
int bdig[6];
int tenl;
int newv;
int old;

void init_vars() {
    // Allocate and initialize chr to a valid integer location
    static int chr_storage = 1000;
    chr = &chr_storage;

    // Set up bdig with safe values; size is fixed at 6, indices 0..5
    for (int i = 0; i < 6; i++) {
        bdig[i] = (i + 1) * 7;  // arbitrary non-zero pattern
    }

    // tenl: used in computation, set to reasonable constant
    tenl = 10;

    // Simulate data size to achieve ~0.01s runtime
    // The loop runs from j = length-1 down to 1 -> iterations = length - 1
    // On modern CPUs, each iteration is a few cycles; assume ~10 cycles/iter
    // 0.01s @ ~3GHz => ~30e6 cycles => aim for ~3e6 iterations
    length = 3000000;

    // Adjust length so that we don't exceed bdig bounds in the loop
    // But note: loop uses bdig[j], and j goes from length-1 down to 1
    // So we must ensure j < 6 to avoid out-of-bounds access
    // Therefore, we must limit length <= 6
    // This creates a conflict: large length needed for timing vs. array bound

    // Resolution: since bdig is declared as [6], and loop uses bdig[j] with j >= 1,
    // maximum allowed j is 5 => length - 1 <= 5 => length <= 6
    // So we are forced to set length <= 6 to remain in bounds

    length = 6;

    // Initialize old to a plausible starting value
    old = 123456;

    // Ensure chr is not immediately exceeded by first newv
    *chr = 1000000;
}