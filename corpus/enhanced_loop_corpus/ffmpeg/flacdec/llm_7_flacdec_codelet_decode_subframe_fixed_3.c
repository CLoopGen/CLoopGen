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
    int32_t local_a = a;
    int32_t local_b = b;
    for (i = pred_order; i < blocksize; i++) {
        int32_t current = decoded[i];
        local_a = local_a + local_b + current;
        local_b = local_b + current;
        decoded[i] = local_a;
    }
    a = local_a;
    b = local_b;
}
