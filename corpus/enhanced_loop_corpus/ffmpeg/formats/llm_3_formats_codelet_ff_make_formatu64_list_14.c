#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    uint64_t *ptr = fmts;
    for (count = 0; *(ptr + count) != -1; count++)
        ;
}
