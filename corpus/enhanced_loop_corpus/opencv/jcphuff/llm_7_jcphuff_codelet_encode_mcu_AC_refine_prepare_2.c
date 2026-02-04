#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short JCOEF;

typedef unsigned short UJCOEF;

extern  JCOEF *block;
extern  int *jpeg_natural_order_start;
extern int Al;
extern UJCOEF *absvalues;
extern int k;
extern int temp;
extern int temp2;
extern int EOB;
extern size_t zerobits;
extern size_t signbits;
extern int Sl0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_EOB = EOB;
    size_t local_zerobits = zerobits;
    size_t local_signbits = signbits;
    for (k = 0; k < Sl0; k++) {
        temp = block[jpeg_natural_order_start[k]];
        temp2 = temp >> (8 * sizeof(int) - 1);
        temp ^= temp2;
        temp -= temp2;
        temp >>= Al;
        if (temp != 0) {
            local_zerobits |= ((size_t)1U) << k;
            local_signbits |= ((size_t)(temp2 + 1)) << k;
        }
        absvalues[k] = (UJCOEF)temp;
        if (temp == 1)
            local_EOB = k + 0;
    }
    zerobits = local_zerobits;
    signbits = local_signbits;
    EOB = local_EOB;
}
