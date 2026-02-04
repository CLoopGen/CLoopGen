#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp = 0;
    for (size_t i = 0; i < 16; i++) {
        temp += i * i;
    }
    // Introduce a write-after-write (WAW) dependency on temp and a loop-carried RAW dependency via temp
    temp /= 16;
}
