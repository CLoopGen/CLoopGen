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
for (i = 0; i < n; i += 2) {
    int64_t val00 = x[i + 0][0];
    int64_t val01 = x[i + 0][1];
    int64_t val10 = x[i + 1][0];
    int64_t val11 = x[i + 1][1];

    accu0 += val00 * val00;
    accu1 += val01 * val01;
    accu2 += val10 * val10;
    accu3 += val11 * val11;

    uint64_t max_val_sq = (uint64_t)(-2147483647LL - 1) * (uint64_t)(-2147483647LL - 1);
    uint64_t overflow_bound = 18446744073709551615UL - max_val_sq;

    if ((accu0 | accu1 | accu2 | accu3) > overflow_bound) {
        accu0 >>= nz;
        accu1 >>= nz;
        accu2 >>= nz;
        accu3 >>= nz;

        uint64_t sum_accu = accu0 + accu1 + accu2 + accu3;
        uint64_t shift_limit = ((18446744073709551615UL) - accu) >> 2;

        if ((accu0 | accu1 | accu2 | accu3) > shift_limit && accu != 18446744073709551615UL) {
            do {
                accu0 >>= 1;
                accu1 >>= 1;
                accu2 >>= 1;
                accu3 >>= 1;
                accu >>= 1;
                nz++;
                shift_limit = ((18446744073709551615UL) - accu) >> 2;
            } while ((accu0 | accu1 | accu2 | accu3) > shift_limit && nz < 64);
        }

        accu += accu0 + accu1 + accu2 + accu3;
        accu0 = accu1 = accu2 = accu3 = 0;
    }
    else if (i + 2 >= n) {
        accu0 >>= nz;
        accu1 >>= nz;
        accu2 >>= nz;
        accu3 >>= nz;
        accu += accu0 + accu1 + accu2 + accu3;
        accu0 = accu1 = accu2 = accu3 = 0;
    }
}
}
