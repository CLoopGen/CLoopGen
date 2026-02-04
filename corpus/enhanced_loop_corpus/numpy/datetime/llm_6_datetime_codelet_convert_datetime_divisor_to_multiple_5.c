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

extern int den;
extern int i;
extern int num;
extern NPY_DATETIMEUNIT *totry;
extern int q;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_q, temp_r;
    for (i = 0; i < num; i++) {
        temp_q = totry[i] / den;
        temp_r = totry[i] % den;
        if (temp_r == 0) {
            q = temp_q;
            r = temp_r;
            break;
        } else {
            q = temp_q;
            r = temp_r;
        }
    }
}
