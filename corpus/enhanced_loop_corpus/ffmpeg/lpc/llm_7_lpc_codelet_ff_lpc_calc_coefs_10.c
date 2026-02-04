#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max_order;
extern double ref[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_ref[32];
    for (i = 0; i < max_order; i++) {
        prev_ref[i] = ref[i];
    }
    for (i = max_order - 1; i > 0; i--) {
        ref[i] = prev_ref[i - 1] - prev_ref[i];
    }
}
