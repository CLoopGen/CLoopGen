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
    size_t temp[1024];
    for (i = 0; i < size1 && i < 1024; i++) {
        temp[i] = i * i;
        for (j = i + 1; j < size2; j++) {
            temp[i] += j - i; // RAW dependency: use of i, WAW on temp[i]
        }
    }
    // Eliminate loop-carried dependencies by ensuring each iteration writes to distinct location
}
