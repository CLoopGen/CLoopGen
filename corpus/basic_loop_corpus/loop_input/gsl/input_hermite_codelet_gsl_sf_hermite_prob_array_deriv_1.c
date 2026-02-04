#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int m;
double *result_array;
int j;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    m = 1 << 24;  // Approximately 16.7 million elements -> ~128MB for double array
    result_array = (double *)calloc(m, sizeof(double));
    if (!result_array) {
        exit(1);
    }

    // Warm-up loop to estimate timing
    for (j = 0; j < m; j++) {
        result_array[j] = 0.;
    }

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    // Scale m to achieve approximately 0.01 seconds
    if (elapsed > 0) {
        double scale = 0.01 / elapsed;
        int new_m = (int)(m * scale);
        if (new_m < 1) new_m = 1;
        m = new_m;
    } else {
        m = 1 << 18;  // Fallback size if timing failed
    }

    free(result_array);
    result_array = (double *)calloc(m, sizeof(double));
    if (!result_array) {
        exit(1);
    }
}