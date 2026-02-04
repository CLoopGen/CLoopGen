#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short JCOEF;

typedef unsigned short UJCOEF;

extern  JCOEF *block;
extern  int *jpeg_natural_order_start;
extern int Sl;
extern int Al;
extern UJCOEF *absvalues;
extern int k;
extern int temp;
extern int temp2;
extern int EOB;
extern size_t zerobits;
extern size_t signbits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < Sl && k < 64; k += 2) {
    temp = block[jpeg_natural_order_start[k]];
    temp2 = temp >> (8 * sizeof(int) - 1);
    temp ^= temp2;
    temp -= temp2;
    temp >>= Al;
    if (temp != 0) {
        zerobits |= ((size_t)1U) << k;
        signbits |= ((size_t)(temp2 + 1)) << k;
    }
    absvalues[k] = (UJCOEF)temp;
    if (temp == 1)
        EOB = k + 32;

    if (k + 1 < Sl) {
        temp = block[jpeg_natural_order_start[k + 1]];
        temp2 = temp >> (8 * sizeof(int) - 1);
        temp ^= temp2;
        temp -= temp2;
        temp >>= Al;
        if (temp != 0) {
            zerobits |= ((size_t)1U) << (k + 1);
            signbits |= ((size_t)(temp2 + 1)) << (k + 1);
        }
        absvalues[k + 1] = (UJCOEF)temp;
        if (temp == 1)
            EOB = k + 1 + 32;
    }
}
}
