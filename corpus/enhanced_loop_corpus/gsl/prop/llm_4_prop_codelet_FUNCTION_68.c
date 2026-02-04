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
        temp = i * i + 1;
        for (j = 0; j < size2; j++) {
            temp += j;
        }
        // WAW dependency on temp removed after inner loop
        // RAW dependency: temp depends on previous iteration's computation
        // Introduces loop-carried dependency via temp across outer loop
    }
}
