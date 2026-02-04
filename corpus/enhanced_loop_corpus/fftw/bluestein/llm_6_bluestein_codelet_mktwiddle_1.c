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
INT temp_val_1, temp_val_2;
for (i = 1; i < n; ++i) {
    temp_val_1 = w[2 * i] / nbf;
    temp_val_2 = w[2 * i + 1] / nbf;
    W[2 * i] = temp_val_1;
    W[2 * (nb - i)] = temp_val_1;
    W[2 * i + 1] = temp_val_2;
    W[2 * (nb - i) + 1] = temp_val_2;
}
}
