#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int unroll_factor = 4;
    int remainder = size % unroll_factor;
    for (i = 0; i < remainder; i++) {
        if (r[i] > max_r)
            max_r = r[i];
        if (r[i] < min_r)
            min_r = r[i];
    }
    for (; i <= size - unroll_factor; i += unroll_factor) {
        if (r[i] > max_r)
            max_r = r[i];
        if (r[i] < min_r)
            min_r = r[i];
        if (r[i + 1] > max_r)
            max_r = r[i + 1];
        if (r[i + 1] < min_r)
            min_r = r[i + 1];
        if (r[i + 2] > max_r)
            max_r = r[i + 2];
        if (r[i + 2] < min_r)
            min_r = r[i + 2];
        if (r[i + 3] > max_r)
            max_r = r[i + 3];
        if (r[i + 3] < min_r)
            min_r = r[i + 3];
    }
}
