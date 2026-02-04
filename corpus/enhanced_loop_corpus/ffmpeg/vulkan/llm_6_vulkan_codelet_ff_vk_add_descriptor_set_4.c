#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (int i = 0; i < num; i++) {
        temp += i;
    }
    // Introduces a loop-carried RAW (read-after-write) dependency on `temp`.
    // Each iteration depends on the previous value of `temp`, creating a sequential data dependency.
}
