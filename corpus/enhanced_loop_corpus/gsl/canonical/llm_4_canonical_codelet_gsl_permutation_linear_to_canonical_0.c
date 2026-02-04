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
        s = 1;
        if (!(k <= i)) {
            size_t temp_k = k;
            for (size_t j = 0; temp_k > i; j++) {
                temp_k = pp[temp_k];
                s++;
                k = temp_k;
            }
        }
        if (k >= i) {
            t -= s;
            qq[t] = i;
            k = pp[i];
            s = 1;
            if (!(k <= i)) {
                size_t temp_k2 = k;
                for (size_t j = 0; temp_k2 > i; j++) {
                    qq[t + s] = temp_k2;
                    temp_k2 = pp[temp_k2];
                    s++;
                    k = temp_k2;
                }
            }
            if (t == 0) {
                break;
            }
        }
    }
}
