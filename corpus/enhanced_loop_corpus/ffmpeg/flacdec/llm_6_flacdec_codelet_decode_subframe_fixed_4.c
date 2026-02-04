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
    int32_t temp_a = a;
    int32_t temp_b = b;
    int32_t temp_c = c;
    for (i = pred_order; i < blocksize; i++) {
        temp_c += decoded[i];
        temp_b += temp_c;
        temp_a += temp_b;
        decoded[i] = temp_a;
    }
    a = temp_a;
    b = temp_b;
    c = temp_c;
}
