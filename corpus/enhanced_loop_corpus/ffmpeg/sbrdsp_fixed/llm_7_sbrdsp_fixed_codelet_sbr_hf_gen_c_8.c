#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*X_high)[2];
extern  int (*X_low)[2];
extern int start;
extern int end;
extern int alpha[4];
extern int i;
extern int64_t accu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = start; i < end; i++) {
    int idx0 = i - 2;
    int idx1 = i - 1;

    // Introduce temporary accumulators to break false dependencies and reorder operations
    int64_t temp_lo0 = (int64_t)X_low[i][0] * 536870912;
    int64_t temp_lo1 = (int64_t)X_low[i][1] * 536870912;

    int64_t term0a = (int64_t)X_low[idx0][0] * alpha[0];
    int64_t term0b = (int64_t)X_low[idx0][1] * alpha[1];
    int64_t term1a = (int64_t)X_low[idx1][0] * alpha[2];
    int64_t term1b = (int64_t)X_low[idx1][1] * alpha[3];

    // Reorder computation to reduce apparent data flow dependency chains
    int64_t accu_a = temp_lo0 + term0a - term0b + term1a - term1b;
    X_high[i][0] = (int)((accu_a + 268435456) >> 29);

    int64_t accu_b = temp_lo1 + term0b + (int64_t)X_low[idx0][0] * alpha[1] +
                     term1b + (int64_t)X_low[idx1][0] * alpha[3];
    X_high[i][1] = (int)((accu_b + 268435456) >> 29);
}
}
