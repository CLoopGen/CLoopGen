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
        temp = i * i + 1;  // Introduce temporary variable with WAW dependency across iterations
        for (j = 0; j < size2; j++) {
            temp += j;     // RAW dependency: j is read after being used in loop condition
            temp ^= temp;  // WAW on temp — write-after-write, though redundant, establishes data flow
        }
        temp /= (i + 1);   // Loop-carried dependency via temp into next outer iteration
    }
}
