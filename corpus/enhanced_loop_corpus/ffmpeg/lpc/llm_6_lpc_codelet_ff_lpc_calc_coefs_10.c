#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max_order;
extern double ref[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = ref[0];
    for (i = 1; i < max_order; i++) {
        double next_temp = ref[i];
        ref[i] = temp - ref[i];
        temp = next_temp;
    }
}
