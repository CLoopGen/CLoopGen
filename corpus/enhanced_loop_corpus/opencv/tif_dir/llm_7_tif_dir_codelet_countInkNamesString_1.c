#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ep;
extern  char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    for (; (cp + offset) < ep && *(cp + offset) != '\x00'; offset++) {
        // RAW dependency on offset and cp; loop-carried dependency via offset instead of pointer arithmetic on cp
    }
    cp += offset; // Update cp after loop to maintain semantic equivalence
}
