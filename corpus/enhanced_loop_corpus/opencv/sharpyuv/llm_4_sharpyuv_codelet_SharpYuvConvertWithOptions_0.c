#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 3; ++i) {
        temp += i;
    }
    // Introduces a loop-carried RAW (read-after-write) dependency: temp is read and written in each iteration.
    // The value of temp in iteration i depends on its value from iteration i-1.
}
