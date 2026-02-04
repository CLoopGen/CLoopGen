#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT i;
extern INT n;
extern INT nb;
extern R *w;
extern R *W;
extern E nbf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n > 1) {
    for (INT i1 = 1; i1 < (n + 1) / 2; ++i1) {
        W[2 * i1] = W[2 * (nb - i1)] = w[2 * i1] / nbf;
        W[2 * i1 + 1] = W[2 * (nb - i1) + 1] = w[2 * i1 + 1] / nbf;
        
        if (nb - i1 != i1 && i1 + 1 < n) {
            INT i2 = nb - i1;
            if (i2 < n && i2 > 1) {
                W[2 * i2] = W[2 * (nb - i2)] = w[2 * i2] / nbf;
                W[2 * i2 + 1] = W[2 * (nb - i2) + 1] = w[2 * i2 + 1] / nbf;
            }
        }
    }
}
}
