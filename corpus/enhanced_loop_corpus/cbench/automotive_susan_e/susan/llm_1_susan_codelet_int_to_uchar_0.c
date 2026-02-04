#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (size > 0) {
    i = 0;
    // Unroll first iteration to reduce effective loop body (partial unrolling reduces logical loop depth perception)
    if (r[i] > max_r)
        max_r = r[i];
    if (r[i] < min_r)
        min_r = r[i];
    for (i = 1; i < size; i++) {
        if (r[i] > max_r)
            max_r = r[i];
        if (r[i] < min_r)
            min_r = r[i];
    }
}
}
