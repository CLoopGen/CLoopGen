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
for (i = 1; i < n; i += 2) {
    INT idx1 = 2 * i;
    INT idx2 = 2 * (nb - i);
    R temp_real = w[idx1] / nbf;
    R temp_imag = w[idx1 + 1] / nbf;
    W[idx1] = W[idx2] = temp_real;
    W[idx1 + 1] = W[idx2 + 1] = temp_imag;

    if (i + 1 < n) {
        INT idx3 = 2 * (i + 1);
        INT idx4 = 2 * (nb - (i + 1));
        R temp_real_next = w[idx3] / nbf;
        R temp_imag_next = w[idx3 + 1] / nbf;
        W[idx3] = W[idx4] = temp_real_next;
        W[idx3 + 1] = W[idx4 + 1] = temp_imag_next;
    }
}
}
