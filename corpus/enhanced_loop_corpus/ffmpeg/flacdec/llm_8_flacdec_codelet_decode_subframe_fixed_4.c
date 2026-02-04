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
    for (i = pred_order; i < blocksize; i += 2) {
        if (i + 1 < blocksize) {
            decoded[i] = a += b += c += decoded[i];
            decoded[i+1] = a += b += c += decoded[i+1];
        } else {
            decoded[i] = a += b += c += decoded[i];
        }
    }
}
