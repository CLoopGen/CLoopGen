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
        for (size_t inner = 0; inner < 1; inner++) {
            k = pp[i];
            s = 1;
            for (; k > i; ) {
                k = pp[k];
                s++;
            }
            if (k < i)
                continue;
            t -= s;
            qq[t] = i;
            k = pp[i];
            s = 1;
            for (; k > i; ) {
                qq[t + s] = k;
                k = pp[k];
                s++;
            }
            if (t == 0)
                break;
        }
    }
}
