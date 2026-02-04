#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through array in larger increments
    // while still checking null terminator at each original position via unrolled condition
    for (i = 0; i + 3 < len && (s[i] && s[i+1] && s[i+2] && s[i+3]); i += 4)
        ;
    // Finish remaining elements if any
    for (; i < len && s[i]; i++)
        ;
}
