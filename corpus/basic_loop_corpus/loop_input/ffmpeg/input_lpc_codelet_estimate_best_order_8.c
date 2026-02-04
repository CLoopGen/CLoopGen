#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double *ref;
int min_order;
int max_order;
int i;
int est;

static double ref_data[1048576]; // 8MB array (1M doubles)

void init_vars() {
    const int data_size = sizeof(ref_data) / sizeof(ref_data[0]);
    min_order = 100000;
    max_order = data_size - 100000;
    
    if (max_order >= data_size) {
        max_order = data_size - 1;
    }
    if (min_order < 1) {
        min_order = 1;
    }

    for (int idx = 0; idx < data_size; idx++) {
        ref_data[idx] = (idx > max_order * 0.5) ? 0.05 : 0.15;
    }

    ref = ref_data;
    i = 0;
    est = 0;
}