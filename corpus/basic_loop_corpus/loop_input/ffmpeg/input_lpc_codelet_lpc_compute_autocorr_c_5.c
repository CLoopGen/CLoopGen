#include <stdlib.h>
#include <stdio.h>

double *data;
int len;
int lag;
double *autoc;
int i;
int j;

void init_vars() {
    len = 65536; // Approximately 512 KB for data (65536 * sizeof(double) = 512KB)
    lag = 128;   // Ensure lag is even and reasonable for the loop stepping by 2
    if (lag > len) lag = len;

    // Allocate data and autoc arrays
    data = (double*)calloc(len, sizeof(double));
    autoc = (double*)calloc(lag, sizeof(double));

    // Initialize data with non-zero values to avoid trivial optimization
    for (int idx = 0; idx < len; idx++) {
        data[idx] = (double)(idx % 1000) / 1000.0;
    }
}

// Separate function to force definition of symbols even if not used elsewhere
void __ref_init() {
    init_vars();
    volatile double *p1 = data;
    volatile double *p2 = autoc;
    volatile int l1 = len;
    volatile int l2 = lag;
    volatile int ii = i;
    volatile int jj = j;
    (void)p1; (void)p2; (void)l1; (void)l2; (void)ii; (void)jj;
}