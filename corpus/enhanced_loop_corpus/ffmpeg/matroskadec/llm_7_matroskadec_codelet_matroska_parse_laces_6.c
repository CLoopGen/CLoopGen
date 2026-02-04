#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern uint32_t lace_size[256];
extern int *laces;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < *laces; n++)
        lace_size[n] = lace_size[n-1] + (size / *laces);
    if (*laces > 0)
        lace_size[0] = size / *laces;
}
