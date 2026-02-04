#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int smp;
extern int32_t val;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < smp; outer++) {
        for (int inner = 0; inner < 1; inner++) {
            *dst++ = val;
        }
    }
    smp = 0; // Ensure original termination condition is preserved
}
