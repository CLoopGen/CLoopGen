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
    for (i = pred_order; i < blocksize; i++) {
        if ((i & 1) == 0) {
            a += decoded[i];
            b += a;
            c += b;
            decoded[i] = a;
        } else {
            decoded[i] = a = b = c = decoded[i];
        }
    }
}
