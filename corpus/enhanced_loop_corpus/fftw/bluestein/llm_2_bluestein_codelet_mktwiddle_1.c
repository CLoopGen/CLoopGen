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
for (i = 1; i < n; ++i) {
    INT idx1 = 2 * i;
    INT idx2 = 2 * (nb - i);
    W[idx1] = w[idx1] / nbf;
    W[idx2] = w[idx1] / nbf;
    W[idx1 + 1] = w[idx1 + 1] / nbf;
    W[idx2 + 1] = w[idx1 + 1] / nbf;
}
}
