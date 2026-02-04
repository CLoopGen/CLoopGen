#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (p = 0; p < size1; p++) {
        size_t k = temp + p; // Loop-carried dependence: temp from previous iteration
        size_t r = k * k;
        size_t c = r / 2;
        temp = c; // WAW and WAR: temp is written each iteration and read next
        // Creates loop-carried flow (RAW) dependency via temp
    }
}
