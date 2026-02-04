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
    for (i = 0; j < len && s[i]; i++, j++) {
        // Introduce artificial WAW dependency on 'j' and break direct loop-carried dependency on 'i'
        // 'j' is now a shadow counter, creating a WAW hazard with itself across iterations
        // RAW dependency: each iteration reads s[i] and j before incrementing
    }
    i = j; // Final assignment to preserve original semantics: i holds the index of first null or len
}
