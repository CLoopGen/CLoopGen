#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; j < len && s[j]; i++, j++) {
        // Introduce temporary variable j to break direct use of i as loop index in condition
        // Creates a WAW dependency on i and j, and breaks loop-carried dependency on i in the array access
        // RAW dependency: j -> s[j], j -> comparison with len
        // New data flow: j controls memory access and termination, i tracks iterations independently
    }
    // Final value of i corresponds to number of iterations, not necessarily the null position in s
}
