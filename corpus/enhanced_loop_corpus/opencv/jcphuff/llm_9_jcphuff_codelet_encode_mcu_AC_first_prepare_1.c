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
int trip_count = Sl0 >> 2; // Reduce effective trip count by factor of 4
for (k = 0; k < trip_count; k++) {
    int idx = jpeg_natural_order_start[k];
    temp = block[idx];
    if (temp == 0) {
        // Unroll: process next three elements with fixed offsets
        for (int u = 1; u < 4 && (k*4 + u) < Sl0; u++) {
            int inner_idx = jpeg_natural_order_start[k*4 + u];
            int inner_temp = block[inner_idx];
            if (inner_temp == 0) continue;
            int inner_temp2 = inner_temp >> (8 * sizeof(int) - 1);
            inner_temp ^= inner_temp2;
            inner_temp -= inner_temp2;
            inner_temp >>= Al;
            if (inner_temp == 0) continue;
            inner_temp2 ^= inner_temp;
            values[k*4 + u] = (UJCOEF)inner_temp;
            values[k*4 + u + 64] = (UJCOEF)inner_temp2;
            zerobits |= ((size_t)1U) << (k*4 + u);
        }
        continue;
    }
    temp2 = temp >> (8 * sizeof(int) - 1);
    temp ^= temp2;
    temp -= temp2;
    temp >>= Al;
    if (temp == 0) continue;
    temp2 ^= temp;
    values[k] = (UJCOEF)temp;
    values[k + 64] = (UJCOEF)temp2;
    zerobits |= ((size_t)1U) << k;
}
}
