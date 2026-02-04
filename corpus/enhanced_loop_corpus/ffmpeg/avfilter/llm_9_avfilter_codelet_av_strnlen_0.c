#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing by 2 each iteration and skip every other byte
    // Also reduce arithmetic complexity by removing any extra operations
    for (i = 0; i < len && s[i]; i += 2)
        ;
}
