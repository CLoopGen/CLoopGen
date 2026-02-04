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
        if (decoded[i] >= 0) {
            c += decoded[i];
            b += c;
            a += b;
            decoded[i] = a;
        } else {
            c += decoded[i];
            a += c;
            decoded[i] = b += a;
        }
    }
}
