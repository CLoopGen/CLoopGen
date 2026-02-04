#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t k;
extern size_t kk;
extern size_t first;
extern  size_t n;
extern size_t * pp;
extern  size_t * qq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < n; i++) {
        size_t temp1 = qq[i];
        size_t temp2 = qq[i-1];
        kk = (temp1 > temp2) ? temp1 : temp2;
        if (kk > first) {
            pp[k] = pp[kk];
            pp[k+1] = pp[kk-1];
            k = kk;
        } else {
            pp[k] = first;
            pp[k+1] = first - 1;
            k = kk;
            first = pp[kk];
        }
        i++; 
    }
}
