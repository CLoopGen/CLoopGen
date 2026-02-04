#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef int Int32;

static Int32 minLen_val;
static Int32 maxLen_val;
static Int32 i_val;
static Int32 vec_val;

static Int32 *base_ptr = NULL;
static Int32 *limit_ptr = NULL;

Int32 *limit = NULL;
Int32 *base = NULL;
Int32 minLen;
Int32 maxLen;
Int32 i;
Int32 vec;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for base and limit arrays
    const size_t num_elements = data_size / sizeof(Int32);

    if (base_ptr) free(base_ptr);
    if (limit_ptr) free(limit_ptr);

    base_ptr = (Int32*)calloc(num_elements, sizeof(Int32));
    limit_ptr = (Int32*)calloc(num_elements, sizeof(Int32));

    if (!base_ptr || !limit_ptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    base = base_ptr;
    limit = limit_ptr;

    // Ensure we have enough room: loop uses base[i+1], so maxLen+1 must be valid index
    minLen_val = 100;
    maxLen_val = num_elements - 2; // so that maxLen + 1 is within bounds

    // Adjust maxLen to target runtime ~0.01s via calibration
    minLen = minLen_val;
    maxLen = maxLen_val;
    i = minLen;
    vec = vec_val = 17;

    // Calibration step: run a sample portion to estimate full timing
    const Int32 test_start = minLen_val;
    const Int32 test_end = minLen_val + 500000; // 0.5M iterations
    if (test_end < maxLen_val) {
        Int32 temp_i, temp_vec = vec_val;
        for (temp_i = test_start; temp_i <= test_end; temp_i++) {
            temp_vec += (base[temp_i + 1] - base[temp_i]);
            limit[temp_i] = temp_vec - 1;
            temp_vec <<= 1;
        }
        gettimeofday(&end, NULL);
        double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

        if (elapsed > 0 && elapsed < 0.02) {
            // Estimate required maxLen for ~0.01s
            double ratio = 0.01 / elapsed;
            Int32 estimated_maxLen = test_end + (Int32)((test_end - test_start) * ratio);
            if (estimated_maxLen < maxLen_val) {
                maxLen = minLen + estimated_maxLen;
            }
        }
    } else {
        maxLen = maxLen_val;
    }

    // Initialize base array with non-zero values to avoid trivial optimizations
    for (size_t idx = 0; idx < num_elements; idx++) {
        base[idx] = (Int32)(idx * 7919) ^ 0xABCDEF; // prime multiplier
    }

    i = minLen;
    vec = vec_val;
}