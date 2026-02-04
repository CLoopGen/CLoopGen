#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < n2; i++) {
        temp += i;
    }
    // Introduces a loop-carried RAW (read-after-write) dependency: each iteration reads 'temp' written in the previous iteration.
    // Eliminates any prior independent behavior of the loop body by making it accumulate state across iterations.
}
