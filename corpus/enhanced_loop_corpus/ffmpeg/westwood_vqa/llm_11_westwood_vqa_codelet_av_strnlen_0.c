#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective trip count by stepping more aggressively, with recovery adjustment
    for (i = 0; i < len - 1 && s[i] && s[i+1]; i += 2)
        ;
    // Finalize: ensure we don't skip the actual termination point
    for (; i < len && s[i]; i++)
        ;
}
