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
    for (k = 0; k < n; ++k) {
        if (k % 2 == 0) {
            int ck = c[k];
            c[k] = sum;
            sum += ck;
        }
    }
}
