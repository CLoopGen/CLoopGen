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
    INT index1 = 2 * i;
    INT index2 = 2 * (nb - i);
    R temp_real = w[index1] / nbf;
    R temp_imag = w[index1 + 1] / nbf;

    W[index1] = temp_real;
    W[index1 + 1] = temp_imag;

    if (nb - i >= i) {
        W[index2] = temp_real;
        W[index2 + 1] = temp_imag;
    }
}
}
