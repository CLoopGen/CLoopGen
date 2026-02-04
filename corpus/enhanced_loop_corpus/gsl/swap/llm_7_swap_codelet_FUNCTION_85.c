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
        for (j = i + 1; j < size2; j++) {
            temp += i * j; // Introduce RAW dependency: temp depends on previous iteration's write
        }
    }
    // Prevent dead code elimination by potentially using temp
    if (temp > 0) {
        size2 = temp % 100 + 1;
    }
}
