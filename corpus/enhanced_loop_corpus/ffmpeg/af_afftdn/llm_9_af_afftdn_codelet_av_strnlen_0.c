#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by processing two elements per iteration to reduce trip count
    i = 0;
    size_t limit = len - 1;
    for (; i < limit && s[i] && s[i+1]; i += 2)
        ;
    // Handle remaining element if any
    for (; i < len && s[i]; i++)
        ;
}
