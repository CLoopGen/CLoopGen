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
    UJCOEF local_values[128] = {0};
    size_t local_zerobits = 0;
    for (k = 0; k < Sl0; k++) {
        temp = block[jpeg_natural_order_start[k]];
        if (temp == 0) {
            local_values[k] = 0;
            local_values[k + 64] = 0;
            continue;
        }
        temp2 = temp >> (8 * sizeof(int) - 1);
        temp ^= temp2;
        temp -= temp2;
        temp >>= Al;
        if (temp == 0) {
            local_values[k] = 0;
            local_values[k + 64] = 0;
            continue;
        }
        temp2 ^= temp;
        local_values[k] = (UJCOEF)temp;
        local_values[k + 64] = (UJCOEF)temp2;
        local_zerobits |= ((size_t)1U) << k;
    }
    for (int i = 0; i < 128; i++) {
        values[i] = local_values[i];
    }
    zerobits = local_zerobits;
}
