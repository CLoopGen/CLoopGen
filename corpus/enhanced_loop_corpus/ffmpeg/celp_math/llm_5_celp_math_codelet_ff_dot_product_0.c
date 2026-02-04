#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *a;
extern  int16_t *b;
extern int length;
extern int i;
extern int64_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i < length; i++) {
        int32_t product = (int32_t)(a[i]) * (int32_t)(b[i]);
        if (product > 0) {
            sum += product;
        }
    }
}
