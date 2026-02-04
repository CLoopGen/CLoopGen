#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *decoded;
extern int pred_order;
extern  int blocksize;
extern unsigned int a;
extern unsigned int b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = blocksize - 1; i >= pred_order; i--)
        decoded[i] = a += b += decoded[i];
}
