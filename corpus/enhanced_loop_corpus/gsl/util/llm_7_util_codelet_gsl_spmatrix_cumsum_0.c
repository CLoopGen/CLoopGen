#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern int *c;
extern int sum;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_sum = sum;
    for (k = 0; k < n; ++k) {
        int ck = c[k];
        c[k] = local_sum;
        local_sum += ck;
    }
    sum = local_sum;
}
