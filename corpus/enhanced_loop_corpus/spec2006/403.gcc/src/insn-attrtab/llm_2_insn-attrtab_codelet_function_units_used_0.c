#include <stdio.h>

#include <inttypes.h>

extern unsigned long accum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile unsigned long *acc_ptr = &accum;
    for (i = 0; acc_ptr[0] >>= 1; ++i)
        continue;
}
