#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t *temp = fmts;
    int i = 0;
    int64_t accumulator = 0;
    for (count = 0; temp[i] != -1; i++) {
        accumulator += temp[i]; // Create loop-carried RAW dependency via accumulator
        count = i + 1; // Introduce WAR-like pattern: write to count after use in expression
    }
    // Eliminate redundant updates: final value of count is set once
    count = i;
}
