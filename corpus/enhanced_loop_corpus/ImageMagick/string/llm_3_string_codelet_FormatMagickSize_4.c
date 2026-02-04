#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char **units;
extern double bytes;
extern double extent;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — skip every other unit (stride of 2), still using for-loop structure
    for (i = 0; (extent >= bytes) && (units[2*i + 2] != (const char *)((void *)0)); i++)
        extent /= bytes;
}
