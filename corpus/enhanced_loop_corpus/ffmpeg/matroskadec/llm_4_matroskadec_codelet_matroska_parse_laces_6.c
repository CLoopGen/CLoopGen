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
    for (n = 0; n < *laces && *laces > 0; n++)
        lace_size[n] = size / *laces;
}
