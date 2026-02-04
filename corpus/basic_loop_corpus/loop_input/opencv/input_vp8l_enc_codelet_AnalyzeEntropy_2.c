#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int HistogramBuckets[256];

int * red_and_blue_always_zero;
int i;
HistogramBuckets * red_histo;
HistogramBuckets * blue_histo;

void init_vars() {
    // Allocate memory for the histogram buckets
    red_histo = (HistogramBuckets *)calloc(1, sizeof(HistogramBuckets));
    blue_histo = (HistogramBuckets *)calloc(1, sizeof(HistogramBuckets));

    // Allocate and initialize the flag variable
    red_and_blue_always_zero = (int *)malloc(sizeof(int));
    *red_and_blue_always_zero = 1;

    // Initialize histograms such that the loop runs through most iterations
    // Set all elements from index 1 to 255 to zero except the last one to trigger break near the end
    for (int j = 1; j < 255; ++j) {
        (*red_histo)[j] = 0;
        (*blue_histo)[j] = 0;
    }
    // Set one value to non-zero to trigger the break condition at the last iteration
    (*red_histo)[255] = 1;
    (*blue_histo)[255] = 0;
}