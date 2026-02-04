#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[10];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element, forward and backward pass)
    for (i = 0; i < 10; i += 2) {
        count[i] = 0;
    }
    for (i = 1; i < 10; i += 2) {
        count[i] = 0;
    }
}
