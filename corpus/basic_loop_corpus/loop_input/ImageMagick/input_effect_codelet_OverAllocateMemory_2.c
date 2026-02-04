#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t length;
size_t extent;

static double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

void init_vars() {
    double start = get_time();
    size_t temp_length = 1 << 28; // Start with ~256MB
    size_t temp_extent;
    int iterations = 0;

    // Estimate number of iterations the loop will perform
    for (temp_extent = 256; temp_extent < temp_length; temp_extent *= 2) {
        iterations++;
        if (iterations > 1000) break;
    }

    // Adjust length so that loop runs about 0.01 seconds
    // Each iteration is very cheap (just a multiply and compare)
    // On modern CPUs, we assume billions of operations per second
    // So we scale the number of iterations to take ~0.01s

    // We assume loop body is ~10 cycles, CPU ~3GHz => ~3e9 cycles/sec
    // Target: 0.01s => ~3e7 cycles available
    // So allow about 3e6 iterations (very rough)
    // But actual loop has log2(length/256) iterations
    // So set log2(length/256) ≈ target_iters

    double target_seconds = 0.01;
    double cycles_per_iter = 10.0;
    double cpu_freq_gigahertz = 3.0;
    double max_cycles = target_seconds * cpu_freq_gigahertz * 1e9;
    double target_iters = max_cycles / cycles_per_iter;

    // Solve: 2^extent_iters = length / 256  => extent_iters = log2(length) - 8
    // We want: log2(length) - 8 ≈ target_iters
    // So: length ≈ 2^(target_iters + 8)

    // Clamp target_iters to avoid overflow
    if (target_iters > 40) target_iters = 40; // 2^48 bytes max?

    length = (size_t)(1ULL << ((int)(target_iters + 8)));
    // Cap length to something reasonable like 256MB if needed
    if (length > (256 << 20)) length = 256 << 20;
    if (length < (1 << 20)) length = 1 << 20; // At least 1MB

    // Ensure extent starts at 256 as per loop
    extent = 256;

    // Run a test to calibrate if needed (optional, but we do simple calc)
    // Given the simplicity, we rely on estimation
}