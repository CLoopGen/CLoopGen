#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short JCOEF;

typedef unsigned short UJCOEF;

extern  JCOEF *block;
extern  int *jpeg_natural_order_start;
extern int Al;
extern UJCOEF *values;
extern int k;
extern int temp;
extern int temp2;
extern size_t zerobits;
extern int Sl0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < Sl0; k++) {
    temp = block[jpeg_natural_order_start[k]];
    temp2 = temp >> (8 * sizeof(int) - 1);
    temp ^= temp2;
    temp -= temp2;
    temp >>= Al;
    if (temp != 0 && (block[jpeg_natural_order_start[k]] != 0)) {
        temp2 ^= temp;
        values[k] = (UJCOEF)temp;
        values[k + 64] = (UJCOEF)temp2;
        zerobits |= ((size_t)1U) << k;
    }
}
}
