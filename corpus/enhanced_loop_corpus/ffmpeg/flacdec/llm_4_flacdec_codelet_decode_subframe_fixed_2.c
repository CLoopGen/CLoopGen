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
    for (i = pred_order; i < blocksize; i++) {
        if (a < 1000000) {
            decoded[i] = a += decoded[i];
        }
    }
}
