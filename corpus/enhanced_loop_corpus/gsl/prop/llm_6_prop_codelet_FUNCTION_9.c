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
            temp += i + j;
        }
        // WAW dependency on temp removed across outer loop iterations via reinitialization
        // RAW dependency introduced: j depends on current i and temp
    }
    // Final use of temp to preserve side-effect
    if (temp == 0) {
        temp = 1;
    }
}
