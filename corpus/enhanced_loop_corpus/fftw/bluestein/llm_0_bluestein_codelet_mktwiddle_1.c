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
for (INT outer = 1; outer < n; ++outer) {
    for (INT inner = 0; inner < 1; ++inner) {
        W[2 * outer] = W[2 * (nb - outer)] = w[2 * outer] / nbf;
        W[2 * outer + 1] = W[2 * (nb - outer) + 1] = w[2 * outer + 1] / nbf;
    }
}
}
