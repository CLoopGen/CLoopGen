#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K && i < 1000; i += 4) {
        volatile size_t sum1 = i;
        volatile size_t sum2 = i + 1;
        volatile size_t sum3 = i + 2;
        volatile size_t sum4 = i + 3;
        sum1 *= sum1; sum2 *= sum2; sum3 *= sum3; sum4 *= sum4;
    }
}
