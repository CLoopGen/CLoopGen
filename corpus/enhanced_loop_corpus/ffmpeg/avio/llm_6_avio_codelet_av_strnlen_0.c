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
        // Introduce a new independent counter 'j' that breaks direct dependency between index and condition
        // RAW dependency on 'j' and 'i'; loop-carried dependency on both counters is now split
    }
}
