#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern char *word;
extern int32 i;
extern int32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2 instead of 1)
    for (i = len - 2; (i > 0) && (word[i] != '('); i -= 2)
        ;
}
