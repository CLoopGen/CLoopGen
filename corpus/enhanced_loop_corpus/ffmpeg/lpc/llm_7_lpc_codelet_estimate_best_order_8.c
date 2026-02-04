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
    int local_est = est;
    for (i = max_order - 1; i >= min_order - 1; i--) {
        if (ref[i] > 0.10000000000000001 && local_est == est) {
            local_est = i + 1;
        }
    }
    est = local_est;
}
