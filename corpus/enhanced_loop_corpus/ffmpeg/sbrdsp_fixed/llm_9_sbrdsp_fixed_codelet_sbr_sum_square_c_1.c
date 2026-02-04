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
for (i = 0; i < n; i++) {
    int idx = i;
    accu0 += (int64_t)x[idx][0] * x[idx][0];
    accu1 += (int64_t)x[idx][1] * x[idx][1];
    if ((accu0 | accu1) > (18446744073709551615UL) - (-2147483647 - 1) * (int64_t)(-2147483647 - 1) || i + 1 >= n) {
        accu0 >>= nz;
        accu1 >>= nz;
        for (int shift = 0; shift < 8 && (accu0 | accu1) > ((18446744073709551615UL) - accu) >> 1; shift++) {
            accu0 >>= 1;
            accu1 >>= 1;
            accu >>= 1;
            nz++;
        }
        accu += accu0 + accu1;
        accu0 = accu1 = 0;
    }
}
}
