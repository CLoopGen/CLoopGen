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
        // Introduce WAW dependency on 'i' and RAW on 'j': 'i' is updated in lockstep with 'j'
        // Loop-carried dependence: each iteration depends on the previous update of j
        i = j; // WAW on 'i' — write after write, but logically consistent due to sequential updates
    }
}
