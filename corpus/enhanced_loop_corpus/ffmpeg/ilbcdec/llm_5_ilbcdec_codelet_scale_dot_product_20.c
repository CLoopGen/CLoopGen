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
    for (int i = 0; i < length; ++i) {
        if ((v1[i] | v2[i]) == 0) continue;
        int64_t scaled_product = (v1[i] * v2[i]) >> scaling;
        sum += scaled_product;
    }
}
