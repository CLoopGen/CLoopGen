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
    for (i = 0; j < len && s[j]; j++) {
        i = j + 1;  // Introduce RAW: j used before update; WAR: i written after j; loop-carried dep on j only
    }
    // Final value of i is j (from last iteration) + 1, preserving original semantics: i points to first invalid index
}
