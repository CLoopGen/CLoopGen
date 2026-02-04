#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 anum;
extern long *tmpl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 step = sizeof(long) * 2;
    for (; anum >= step; anum -= step, tmpl += 2) {
        long val1 = *tmpl;
        long val2 = *(tmpl + 1);
        *tmpl = ~val1;
        *(tmpl + 1) = ~val2;
    }
}
