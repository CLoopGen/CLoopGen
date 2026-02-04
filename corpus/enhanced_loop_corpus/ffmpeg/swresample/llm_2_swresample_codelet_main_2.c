#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int remaining_tests[117600];
extern int max_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 4)
    for (i = 0; i < max_tests; i += 4) {
        if (i < max_tests) remaining_tests[i] = i;
        if (i + 1 < max_tests) remaining_tests[i + 1] = i + 1;
        if (i + 2 < max_tests) remaining_tests[i + 2] = i + 2;
        if (i + 3 < max_tests) remaining_tests[i + 3] = i + 3;
    }
}
