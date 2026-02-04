#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int TotalNumberofBasicUnit;
double *BUPFMAD;
double *BUCFMAD;
int i;

void init_vars() {
    struct timeval start, end;
    double elapsed;

    size_t target_time_ns = 10000000; // 10 ms in nanoseconds
    double estimated_time_per_iter = 5.0; // rough estimate in ns per element (adjustable)

    // Estimate data size for ~10ms runtime
    size_t num_elements = (size_t)(target_time_ns / estimated_time_per_iter);
    // Clamp between 1MB and 256MB of data (in doubles: 8 bytes each)
    size_t min_elements = (1 << 20) / sizeof(double); // ~1M doubles
    size_t max_elements = (256 << 20) / sizeof(double); // ~32M doubles

    if (num_elements < min_elements) num_elements = min_elements;
    if (num_elements > max_elements) num_elements = max_elements;

    TotalNumberofBasicUnit = (int)num_elements;

    BUPFMAD = (double*)malloc(TotalNumberofBasicUnit * sizeof(double));
    BUCFMAD = (double*)malloc(TotalNumberofBasicUnit * sizeof(double));

    if (!BUPFMAD || !BUCFMAD) {
        free(BUPFMAD);
        free(BUCFMAD);
        BUPFMAD = BUCFMAD = NULL;
        TotalNumberofBasicUnit = 0;
        return;
    }

    // Initialize BUCFMAD with sample values to ensure meaningful copy
    for (int j = 0; j < TotalNumberofBasicUnit; j++) {
        BUCFMAD[j] = (double)(j & 1023) + 1.0;
    }

    // Warm-up run to estimate timing and refine loop count if needed
    gettimeofday(&start, NULL);
    for (int iter = 0; iter < 1; iter++) {
        for (int j = 0; j < TotalNumberofBasicUnit; j++) {
            BUPFMAD[j] = BUCFMAD[j];
        }
    }
    gettimeofday(&end, NULL);

    elapsed = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    // Not adjusting array size further to keep it simple; initial estimate is sufficient
}