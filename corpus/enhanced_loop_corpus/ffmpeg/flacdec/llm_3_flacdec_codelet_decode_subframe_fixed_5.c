#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *decoded;
extern int pred_order;
extern  int blocksize;
extern unsigned int a;
extern unsigned int b;
extern unsigned int c;
extern unsigned int d;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Iterates backward from blocksize-1 down to pred_order, maintaining dependency chain.
    // This changes spatial locality and may affect cache behavior.
    for (i = blocksize - 1; i >= pred_order; i--) {
        decoded[i] = a += b += c += d += decoded[i];
    }
}
