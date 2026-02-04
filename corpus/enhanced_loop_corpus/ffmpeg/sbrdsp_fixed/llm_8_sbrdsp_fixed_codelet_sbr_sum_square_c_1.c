#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*x)[2];
extern int n;
extern uint64_t accu;
extern uint64_t accu0;
extern uint64_t accu1;
extern uint64_t accu2;
extern uint64_t accu3;
extern int i;
extern int nz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 4) {
    accu0 += (int64_t)x[i + 0][0] * x[i + 0][0];
    accu1 += (int64_t)x[i + 0][1] * x[i + 0][1];
    accu2 += (int64_t)x[i + 1][0] * x[i + 1][0];
    accu3 += (int64_t)x[i + 1][1] * x[i + 1][1];
    if (i + 2 < n) {
        accu0 += (int64_t)x[i + 2][0] * x[i + 2][0];
        accu1 += (int64_t)x[i + 2][1] * x[i + 2][1];
    }
    if (i + 3 < n) {
        accu2 += (int64_t)x[i + 3][0] * x[i + 3][0];
        accu3 += (int64_t)x[i + 3][1] * x[i + 3][1];
    }
    if ((accu0 | accu1 | accu2 | accu3) > (18446744073709551615UL) - (-2147483647 - 1) * (int64_t)(-2147483647 - 1) || i + 4 >= n) {
        accu0 >>= nz;
        accu1 >>= nz;
        accu2 >>= nz;
        accu3 >>= nz;
        for (; (accu0 | accu1 | accu2 | accu3) > ((18446744073709551615UL) - accu) >> 2; ) {
            accu0 >>= 1;
            accu1 >>= 1;
            accu2 >>= 1;
            accu3 >>= 1;
            accu >>= 1;
            nz++;
        }
        accu += accu0 + accu1 + accu2 + accu3;
        accu0 = accu1 = accu2 = accu3 = 0;
    }
}
}
