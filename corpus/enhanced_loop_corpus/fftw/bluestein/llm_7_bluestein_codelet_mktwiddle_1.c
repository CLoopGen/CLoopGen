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
    W[2 * i] = w[2 * i] / nbf;
    W[2 * i + 1] = w[2 * i + 1] / nbf;
}
for (i = 1; i < n; ++i) {
    W[2 * (nb - i)] = W[2 * i];
    W[2 * (nb - i) + 1] = W[2 * i + 1];
}
}
