#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    NPY_FR_ERROR = -1,
    NPY_FR_Y = 0,
    NPY_FR_M = 1,
    NPY_FR_W = 2,
    NPY_FR_D = 4,
    NPY_FR_h = 5,
    NPY_FR_m = 6,
    NPY_FR_s = 7,
    NPY_FR_ms = 8,
    NPY_FR_us = 9,
    NPY_FR_ns = 10,
    NPY_FR_ps = 11,
    NPY_FR_fs = 12,
    NPY_FR_as = 13,
    NPY_FR_GENERIC = 14
} NPY_DATETIMEUNIT;

int den;
int i;
int num;
NPY_DATETIMEUNIT *totry;
int q;
int r;

void init_vars() {
    den = 3;
    num = 10000000; // ~10M elements to target ~0.01 sec runtime

    totry = (NPY_DATETIMEUNIT*)malloc(num * sizeof(NPY_DATETIMEUNIT));
    if (!totry) {
        exit(1);
    }

    for (int idx = 0; idx < num; idx++) {
        totry[idx] = (NPY_DATETIMEUNIT)(idx % 15);
        if (totry[idx] % den == 0 && idx != num - 1) {
            totry[idx] = (NPY_DATETIMEUNIT)((idx + 1) % 15); // avoid early break
        }
    }

    i = 0;
    q = 0;
    r = 0;
}