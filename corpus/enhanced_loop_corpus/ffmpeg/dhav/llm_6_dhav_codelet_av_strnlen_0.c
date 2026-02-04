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
        // Introduce temporary variable j to break direct use of i in memory access
        // New dependency: j is now loop-carried (WAW on j), and i depends on j (RAW: j -> i increment)
        // Original data dependency on s[i] replaced with s[j], decoupling index update from use
    }
    i = j; // Final assignment to preserve original semantics: i holds the index of first null or len
}
