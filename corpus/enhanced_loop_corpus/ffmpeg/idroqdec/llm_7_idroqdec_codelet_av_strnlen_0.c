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
        // Convert loop control to use 'j', but still update 'i' each iteration (RAW: j -> i)
        // Introduces loop-carried WAW on 'i' and breaks direct dependency chain on 'i' in condition
    }
    i = j; // Final assignment to maintain semantic equivalence
}
