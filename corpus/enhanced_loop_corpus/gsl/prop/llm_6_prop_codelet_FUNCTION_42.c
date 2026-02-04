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
        temp = i * 2; // Introduce WAW dependency on temp, but no loop-carried dependency since it's redefined each iteration
        for (j = 0; j < size2; j++) {
            temp += j; // RAW: temp depends on previous value; loop-carried dependency introduced across inner iterations
        }
        // temp used after inner loop — creates dependency between outer loop iterations if temp were carried over,
        // but here it's overwritten in next outer iteration, so no outer loop-carried dependency
    }
}
