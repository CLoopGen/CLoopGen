#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *ref;
extern int min_order;
extern int max_order;
extern int i;
extern int est;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_est = -1;
    for (i = max_order - 1; i >= min_order - 1; i--) {
        double val = ref[i];
        if (val > 0.10000000000000001) {
            temp_est = i + 1;
            break;
        }
    }
    if (temp_est != -1) {
        est = temp_est;
    }
}
