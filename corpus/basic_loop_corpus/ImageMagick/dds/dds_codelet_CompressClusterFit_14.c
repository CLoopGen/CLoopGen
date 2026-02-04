#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t count;
extern ssize_t bestk;
extern ssize_t i;
extern unsigned char *o;
extern unsigned char unordered[16];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = bestk; i < (ssize_t)count; i++)
    unordered[o[i]] = 1;

}
