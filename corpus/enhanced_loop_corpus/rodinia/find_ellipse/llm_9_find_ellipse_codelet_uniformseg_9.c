#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dist[36];
extern double dsum[36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = dsum[0];
    for (i = 1; i < 18; i++) {
        temp_sum += dist[2*i] + dist[2*i - 1];
        dsum[2*i - 1] = temp_sum - dist[2*i];
        dsum[2*i] = temp_sum;
    }
    if (i == 18) {
        dsum[35] = dsum[34] + dist[35];
    }
}
