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
    if (pred_order >= blocksize) return;
    int32_t local_sum = decoded[pred_order];
    decoded[pred_order] = a + b + c + d + local_sum;
    for (i = pred_order + 1; i < blocksize; i++) {
        local_sum += decoded[i];
        decoded[i] = local_sum;
    }
    a += local_sum;
    b = a;
    c = b;
    d = c;
}
