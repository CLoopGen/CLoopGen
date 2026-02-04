#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (x = 0; x < w; ++x) {
        temp += x;
    }
    // Introduces a loop-carried RAW (read-after-write) dependency on 'temp'
    // Each iteration depends on the previous value of 'temp'
}
