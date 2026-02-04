#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            temp += i * j;
        }
    }
    // Introduce a write-after-write (WAW) and read-after-write (RAW) dependency on temp
    // Loop-carried dependency through temp across outer loop iterations
}
