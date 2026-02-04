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
        temp = i * 2; // Introduce WAW dependency on temp, but not loop-carried across iterations of i
        for (j = 0; j < size2; j++) {
            temp += j; // RAW: temp depends on previous update; WAR avoided by sequential flow
            temp = temp % 1000; // Modify same variable — intra-loop-carried dependency in j-loop
        }
        // temp used after inner loop, but no carry from one i-iteration to next beyond assignment
    }
}
