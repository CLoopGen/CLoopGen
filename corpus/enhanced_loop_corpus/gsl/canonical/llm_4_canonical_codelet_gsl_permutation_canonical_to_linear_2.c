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
for (i = 1; i < n; i++) {
    kk = qq[i];
    k = kk;
    if (kk > first) {
        pp[k] = pp[kk];
    } else {
        pp[k] = first;
        first = pp[kk];
    }
}
}
