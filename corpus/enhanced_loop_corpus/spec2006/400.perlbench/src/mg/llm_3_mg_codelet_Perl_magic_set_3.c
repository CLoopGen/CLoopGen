#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern int PL_origargc;
extern char **PL_origargv;
extern I32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from end to beginning
    for (i = PL_origargc - 1; i >= 1; i--)
        PL_origargv[i] = 0;
}
