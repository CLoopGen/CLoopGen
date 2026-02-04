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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t local_sum = 0;
    for (i = pred_order; i < blocksize; i++) {
        local_sum += decoded[i];
        decoded[i] = local_sum;
    }
    a += local_sum;
    b = local_sum;
    c = local_sum;
}
