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



void loop() {
    for (i = 0; i < n; i += 2) {
        int64_t temp0 = (int64_t)x[i + 0][0];
        int64_t temp1 = (int64_t)x[i + 0][1];
        int64_t temp2 = (int64_t)x[i + 1][0];
        int64_t temp3 = (int64_t)x[i + 1][1];

        accu0 += temp0 * temp0;
        accu1 += temp1 * temp1;
        accu2 += temp2 * temp2;
        accu3 += temp3 * temp3;

        uint64_t threshold = (18446744073709551615UL) - (-2147483647LL - 1) * (int64_t)(-2147483647LL - 1);
        if ((accu0 | accu1 | accu2 | accu3) > threshold || i + 2 >= n) {
            accu0 >>= nz;
            accu1 >>= nz;
            accu2 >>= nz;
            accu3 >>= nz;

            uint64_t combined = (accu0 | accu1 | accu2 | accu3);
            uint64_t limit = (((18446744073709551615UL) - accu) >> 2);

            for (; combined > limit && accu > 0; ) {
                accu0 >>= 1;
                accu1 >>= 1;
                accu2 >>= 1;
                accu3 >>= 1;
                accu >>= 1;
                nz++;
                combined = (accu0 | accu1 | accu2 | accu3);
                limit = (((18446744073709551615UL) - accu) >> 2);
            }

            accu += accu0 + accu1 + accu2 + accu3;
            accu0 = accu1 = accu2 = accu3 = 0;
        }
    }
}
