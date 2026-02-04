#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef int integer;
typedef float real;

integer *n;
real *z__;
real e;
integer k;

static integer n_val;
static real *z__val;

void init_vars() {
    const uint64_t target_ns = 10000000; // 10 ms in nanoseconds
    uint64_t start, end;
    integer temp_n;
    real sum = 0.0f;

    struct timespec ts;
    
    // Estimate data size to run loop for ~10ms
    temp_n = 1 << 20; // Start with 1M elements

    while (1) {
        z__val = (real*)calloc(temp_n + 1, sizeof(real));
        if (!z__val) {
            temp_n >>= 1;
            continue;
        }

        // Initialize array with non-zero values to prevent optimization away
        for (integer i = 1; i <= temp_n; ++i) {
            z__val[i] = (real)(i & 0xFF);
        }

        n_val = temp_n;
        n = &n_val;
        z__ = z__val;
        e = 0.0f;

        clock_gettime(CLOCK_MONOTONIC, &ts);
        start = ts.tv_sec * 1000000000ULL + ts.tv_nsec;

        for (k = *n; k >= 1; --k) {
            e += z__[k];
        }

        clock_gettime(CLOCK_MONOTONIC, &ts);
        end = ts.tv_sec * 1000000000ULL + ts.tv_nsec;

        sum = e; // Prevent optimization
        free(z__val);

        uint64_t elapsed = end - start;
        if (elapsed >= target_ns * 0.9 && elapsed <= target_ns * 1.1) break;

        if (elapsed < target_ns * 0.5) {
            temp_n <<= 1;
            if (temp_n > (256 << 20)) { // Cap at 256M
                temp_n = 256 << 20;
                break;
            }
        } else {
            temp_n >>= 1;
            if (temp_n < 1) temp_n = 1;
        }
    }

    // Allocate and initialize final array
    z__val = (real*)calloc(temp_n + 1, sizeof(real));
    if (!z__val) {
        exit(1);
    }

    for (integer i = 1; i <= temp_n; ++i) {
        z__val[i] = (real)(i & 0xFF);
    }

    n_val = temp_n;
    n = &n_val;
    z__ = z__val;
    e = 0.0f;
}