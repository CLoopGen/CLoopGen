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
INT j;
for (i = 1; i < n; ++i) {
    if (i != nb - i) {
        W[2 * i] = w[2 * i] / nbf;
        W[2 * i + 1] = w[2 * i + 1] / nbf;
        W[2 * (nb - i)] = w[2 * i] / nbf;
        W[2 * (nb - i) + 1] = w[2 * i + 1] / nbf;
    } else {
        W[2 * i] = w[2 * i] / nbf;
        W[2 * i + 1] = w[2 * i + 1] / nbf;
    }
}
}
