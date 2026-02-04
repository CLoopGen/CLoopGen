#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t besti;
extern ssize_t bestj;
extern ssize_t i;
extern unsigned char *o;
extern unsigned char unordered[16];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = besti; i < (ssize_t)bestj; i++)
    unordered[o[i]] = 2;

}
