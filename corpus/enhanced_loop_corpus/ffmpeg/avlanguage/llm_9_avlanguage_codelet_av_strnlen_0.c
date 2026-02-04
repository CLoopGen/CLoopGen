#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing faster, skip every other byte
    // Also simplify body to minimal form (already empty), but change iteration stride
    for (i = 0; i < len && s[i]; i += 2)
        ;
}
