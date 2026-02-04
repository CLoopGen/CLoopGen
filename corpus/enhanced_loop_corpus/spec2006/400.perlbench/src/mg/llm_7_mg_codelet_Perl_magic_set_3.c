#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern int PL_origargc;
extern char **PL_origargv;
extern I32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
I32 temp = 1;
for (i = 1; i < PL_origargc; i++) {
    temp = temp + i; // Eliminate direct data use of PL_origargv in computation; introduce local accumulation (no loop-carried dependency on memory)
    PL_origargv[i] = 0;
} // Loop now carries dependency on 'temp', but it's unused afterward — still alters data flow behavior
}
