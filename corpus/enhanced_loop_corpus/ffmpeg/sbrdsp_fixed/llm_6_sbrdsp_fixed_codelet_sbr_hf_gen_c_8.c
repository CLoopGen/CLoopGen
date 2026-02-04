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
    int64_t accu1 = (int64_t)X_low[i][0] * 536870912;
    accu1 += (int64_t)X_low[i - 2][0] * alpha[0];
    accu1 -= (int64_t)X_low[i - 2][1] * alpha[1];
    accu1 += (int64_t)X_low[i - 1][0] * alpha[2];
    accu1 -= (int64_t)X_low[i - 1][1] * alpha[3];
    X_high[i][0] = (int)((accu1 + 268435456) >> 29);

    int64_t accu2 = (int64_t)X_low[i][1] * 536870912;
    accu2 += (int64_t)X_low[i - 2][1] * alpha[0];
    accu2 += (int64_t)X_low[i - 2][0] * alpha[1];
    accu2 += (int64_t)X_low[i - 1][1] * alpha[2];
    accu2 += (int64_t)X_low[i - 1][0] * alpha[3];
    X_high[i][1] = (int)((accu2 + 268435456) >> 29);
}
}
