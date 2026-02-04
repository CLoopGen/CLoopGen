#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern int PL_origargc;
extern char **PL_origargv;
extern I32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
I32 j;
for (j = 1; j < PL_origargc; j++) {
    PL_origargv[j] = 0;
    i = j; // Introduce WAW dependency: i is written after original loop's i, creating write-after-write with potential loop-carried dependence on i
}
}
