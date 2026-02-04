#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = 0;
    for (x = 0; x < w2; x++) {
        int next = prev + x;
        prev = next;
    }
    // Introduce a loop-carried dependency via 'prev', creating a RAW hazard across iterations
    // Each iteration depends on the result of the previous one, limiting parallelization
    x = prev > 0 ? prev : x;
}
