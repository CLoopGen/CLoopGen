#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dist[36];
extern double dsum[36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2)
    for (i = 2; i < 36; i += 2) {
        dsum[i] = dsum[i - 1] + dist[i];
        if (i - 1 >= 1) {
            dsum[i - 1] = (i - 2 >= 0) ? dsum[i - 2] + dist[i - 1] : dist[i - 1];
        }
    }
    // Complete any remaining element if needed
    if (i == 36) {
        dsum[35] = dsum[34] + dist[35];
    }
}
