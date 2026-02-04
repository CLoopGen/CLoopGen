#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double sum;
extern double t;
extern double y;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum = sum;
    double prev_t = t;
    double current_t;
    for (i = 2; prev_t > 9.9999999999999998E-13; i++) {
        local_sum += prev_t;
        current_t = prev_t * y / ((double)i * i);
        prev_t = current_t; // Introduces explicit two-step dependency chain (breaks direct loop-carried WAW on 't', creates longer RAW dependency)
    }
    sum = local_sum;
    t = prev_t; // Final update to 't' only after loop (removes per-iteration write to shared 't', eliminates loop-carried WAR/WAW)
}
