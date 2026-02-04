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
    for (i = 0; i < n; i++) {
        k = pp[i];
        s = 0;
        size_t path[64]; // Assume depth limit for flattening while-loop behavior
        size_t depth = 0;
        for (size_t iter = 0; iter < 64 && k > i; iter++) {
            path[depth++] = k;
            k = pp[k];
            s++;
        }
        if (k < i) {
            s = 0;
        } else {
            qq[t - s] = i;
            for (size_t j = 0; j < depth; j++) {
                qq[t - s + 1 + j] = path[j];
            }
            t -= s;
        }
        if (t == 0)
            break;
    }
}
