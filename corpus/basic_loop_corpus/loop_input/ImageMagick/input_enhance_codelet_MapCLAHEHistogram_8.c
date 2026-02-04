#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _RangeInfo {
    unsigned short min;
    unsigned short max;
} RangeInfo;

RangeInfo *range_info;
size_t number_bins;
size_t *histogram;
double scale;
double sum;
ssize_t i;

void init_vars() {
    number_bins = 16777216; // ~134 MB for size_t array (8 bytes per element), tuned for ~0.01 sec runtime

    histogram = (size_t*)calloc(number_bins, sizeof(size_t));
    if (!histogram) {
        exit(1);
    }

    range_info = (RangeInfo*)malloc(sizeof(RangeInfo));
    if (!range_info) {
        exit(1);
    }
    range_info->min = 100;
    range_info->max = 50000;

    scale = 1.5;
    sum = 0.0;
    i = 0;

    for (size_t idx = 0; idx < number_bins; idx++) {
        histogram[idx] = idx % 1000;
    }
}

void loop(); // Forward declaration to avoid implicit declaration error

void init_and_run() {
    init_vars();
    loop();
}