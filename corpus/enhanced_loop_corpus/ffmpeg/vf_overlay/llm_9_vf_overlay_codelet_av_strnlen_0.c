#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating every second element, then adjust
    for (i = 0; i < len && s[i]; i += 2)
        ;
    // Compensate: if exited early due to step size, finish the last element
    if (i >= len && (i - 1) < len && s[i - 1]) 
        i = len;
}
