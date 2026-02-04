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
    if (pred_order >= blocksize) return;
    int32_t temp = a;
    for (i = pred_order; i < blocksize; i++) {
        temp += b;
        decoded[i] = temp;
        b += decoded[i];
    }
    a = temp;
}
