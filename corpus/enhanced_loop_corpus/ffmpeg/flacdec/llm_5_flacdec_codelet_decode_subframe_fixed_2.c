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
    int skip_first = 1;
    for (i = pred_order; i < blocksize; i++) {
        if (!skip_first) {
            decoded[i] = a += decoded[i];
        }
        skip_first = 0;
    }
}
