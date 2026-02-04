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
        temp += i; // Introduce WAW dependency on temp across iterations
        for (j = i + 1; j < size2; j++) {
            temp = temp + j - i; // RAW dependency: j and i used to update temp
        }
    }
    // temp is not used further, but dependencies are enforced within the loop
}
