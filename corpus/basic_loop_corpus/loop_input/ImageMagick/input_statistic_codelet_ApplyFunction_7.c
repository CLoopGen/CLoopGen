#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef float MagickFloatType;
typedef MagickFloatType Quantum;

Quantum pixel = 32768.0f;
size_t number_parameters = 0;
double *parameters = NULL;
double result = 1.0;
ssize_t i = 0;

void init_vars() {
    const uint64_t target_time_ns = 10000000; // 10 ms in nanoseconds
    uint64_t start_time, end_time;
    struct timespec ts;

    // Estimate iterations needed for ~10ms runtime
    clock_gettime(CLOCK_MONOTONIC, &ts);
    start_time = ts.tv_sec * 1000000000ULL + ts.tv_nsec;

    size_t temp_n = 10000;
    double *temp_params = malloc(temp_n * sizeof(double));
    for (size_t j = 0; j < temp_n; j++) {
        temp_params[j] = (double)(j % 1000) / 100.0;
    }

    double temp_result = 1.0;
    for (i = 0; i < (ssize_t)temp_n; i++)
        temp_result = temp_result * ((double)1. / (double)((Quantum)65535.)) * (double)pixel + temp_params[i];

    clock_gettime(CLOCK_MONOTONIC, &ts);
    end_time = ts.tv_sec * 1000000000ULL + ts.tv_nsec;
    uint64_t elapsed = end_time - start_time;

    if (elapsed == 0) elapsed = 1; // Avoid division by zero

    // Scale n to achieve approximately target_time_ns
    double factor = (double)target_time_ns / (double)elapsed;
    number_parameters = (size_t)((double)temp_n * factor);

    free(temp_params);

    // Allocate and initialize parameters array
    parameters = malloc(number_parameters * sizeof(double));
    if (parameters == NULL) {
        number_parameters = 0;
        return;
    }

    for (i = 0; i < (ssize_t)number_parameters; i++) {
        parameters[i] = (double)(i % 1000) / 100.0;
    }

    result = 1.0;
    pixel = 32768.0f;
}