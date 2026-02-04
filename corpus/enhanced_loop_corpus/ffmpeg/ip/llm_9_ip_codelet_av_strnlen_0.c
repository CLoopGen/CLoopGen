#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing faster, but check more conditions
    for (i = 0; i < len && (s[i] || s[i+1]) && i+1 < len; i += 2)
        ;
}
