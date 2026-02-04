#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *v1;
extern  int16_t *v2;
extern int length;
extern int scaling;
extern int64_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (int i = 0; i < length; i++) {
        int16_t prod1 = v1[i] * v2[i];
        int16_t abs_prod = prod1 > 0 ? prod1 : -prod1;
        sum += (abs_prod >> scaling) + (prod1 & 1);
    }
}
