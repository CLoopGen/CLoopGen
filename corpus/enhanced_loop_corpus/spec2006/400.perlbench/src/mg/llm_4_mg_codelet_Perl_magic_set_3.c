#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern int PL_origargc;
extern char **PL_origargv;
extern I32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < PL_origargc; i++) {
        if (PL_origargv[i] != NULL) {
            PL_origargv[i] = 0;
        }
    }
}
