#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[20];
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (n = 0; n < 20; n++) {
        double np1 = n + 1.;
        double square = np1 * np1;
        t[n] = 1. / square;
        temp_sum += t[n]; // Remove loop-carried dependency on global 'sum' by using local accumulator
    }
    sum = temp_sum; // Update global sum only once after loop (eliminates WAW and RAW dependencies on 'sum')
}
