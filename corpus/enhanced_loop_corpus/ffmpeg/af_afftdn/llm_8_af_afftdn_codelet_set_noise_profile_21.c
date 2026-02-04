#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum1 = 0.0;
    double local_sum2 = 0.0;
    for (int m = 0; m < 15; m += 2) {
        local_sum1 += temp[m];
        if (m + 1 < 15) {
            local_sum2 += temp[m + 1];
        }
    }
    sum += (local_sum1 + local_sum2);
}
