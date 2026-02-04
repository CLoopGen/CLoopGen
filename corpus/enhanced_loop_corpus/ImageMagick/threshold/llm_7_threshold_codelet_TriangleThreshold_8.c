#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double count;
extern ssize_t i;
extern ssize_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t local_max = max;
    double local_count = count;
    for (i = 1; i <= (ssize_t)255; i += 2) {
        double val0 = histogram[i - 1];
        double val1 = histogram[i];
        ssize_t update0 = (val0 > local_count) ? (i - 1) : -1;
        ssize_t update1 = (val1 > ((update0 != -1) ? val0 : local_count)) ? i : -1;
        if (update0 != -1) {
            local_count = val0;
            local_max = update0;
        }
        if (update1 != -1 && histogram[i] > local_count) {
            local_count = val1;
            local_max = update1;
        }
    }
    if ((ssize_t)255 % 2 == 0) {
        double last_val = histogram[255];
        if (last_val > local_count) {
            local_max = 255;
            local_count = last_val;
        }
    }
    max = local_max;
    count = local_count;
}
