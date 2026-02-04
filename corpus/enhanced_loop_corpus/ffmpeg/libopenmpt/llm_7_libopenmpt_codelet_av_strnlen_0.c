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
        // Introduce RAW dependency: j used to index s and control loop, i follows j
        // Loop-carried dependency now on j instead of i; i shadows j but doesn't drive iteration
    }
    i = j;  // Final assignment ensures i reflects correct terminal state
}
