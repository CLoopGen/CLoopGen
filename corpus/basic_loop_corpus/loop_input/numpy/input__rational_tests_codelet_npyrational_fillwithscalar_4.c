#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

typedef struct {
    int n;
    int dmm;
} rational;

npy_intp length;
rational r;
rational *buffer;
npy_intp i;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Estimate data size for ~0.01 seconds runtime
    // Start with 64M elements and adjust if needed based on timing
    npy_intp estimated_length = 64 * 1024 * 1024;
    buffer = (rational *)malloc(estimated_length * sizeof(rational));
    if (!buffer) {
        exit(1);
    }

    length = estimated_length;
    r.n = 42;
    r.dmm = 84;
    i = 0;

    // Warm-up run
    for (i = 0; i < length; i++) {
        buffer[i] = r;
    }

    // Timing loop to calibrate
    gettimeofday(&start, NULL);
    for (i = 0; i < length; i++) {
        buffer[i] = r;
    }
    gettimeofday(&end, NULL);

    long time_usec = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    double target_time = 0.01 * 1e6; // 0.01 seconds in microseconds

    // Adjust length to hit target time
    if (time_usec > 0) {
        npy_intp calibrated_length = (npy_intp)((double)length * target_time / time_usec);
        if (calibrated_length == 0) calibrated_length = 1;
        if (calibrated_length > 256 * 1024 * 1024) {
            calibrated_length = 256 * 1024 * 1024;
        }

        free(buffer);
        length = calibrated_length;
        buffer = (rational *)malloc(length * sizeof(rational));
        if (!buffer) {
            exit(1);
        }
    }

    // Final initialization
    r.n = 42;
    r.dmm = 84;
}