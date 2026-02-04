#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *decoded;
extern int pred_order;
extern  int blocksize;
extern unsigned int a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (pred_order < blocksize) {
        int32_t prev = decoded[pred_order];
        decoded[pred_order] = a + prev;
        for (i = pred_order + 1; i < blocksize; i++) {
            int32_t curr = decoded[i];
            decoded[i] = decoded[i-1] + curr;
        }
        a += prev;
    }
}
