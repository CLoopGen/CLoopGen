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
    int64_t temp = 0;
    for (i = 0; i < size1; i++) {
        temp = i * 2; // Introduce loop-carried dependency via 'temp'
        for (j = 0; j < size2; j++) {
            temp += i + j; // RAW dependency: 'temp' read before write
        }
        // Write 'temp' to prevent dead code elimination
        if (temp > 1000) {
            temp = 0;
        }
    }
}
