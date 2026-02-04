#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern size_t i;
extern size_t k;
extern size_t s;
extern size_t t;
extern  size_t * pp;
extern size_t * qq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n && t > 0; i++) {
    k = pp[i];
    s = 1;
    for (size_t temp = k; temp > i; s++) {
        temp = pp[temp];
    }
    if (k < i)
        continue;
    t -= s;
    qq[t] = i;
    k = pp[i];
    s = 1;
    qq[t + s] = k;
    for (k = pp[k]; k > i; s++) {
        qq[t + s + 1] = k;
        k = pp[k];
    }
    if (t == 0)
        break;
}
}
