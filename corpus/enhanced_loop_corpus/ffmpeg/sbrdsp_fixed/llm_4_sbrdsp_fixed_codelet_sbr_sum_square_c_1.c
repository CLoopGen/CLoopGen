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
    accu0 += (int64_t)x[i + 0][0] * x[i + 0][0];
    accu1 += (int64_t)x[i + 0][1] * x[i + 0][1];
    accu2 += (int64_t)x[i + 1][0] * x[i + 1][0];
    accu3 += (int64_t)x[i + 1][1] * x[i + 1][1];

    uint64_t combined_accu = accu0 | accu1 | accu2 | accu3;
    uint64_t threshold = (18446744073709551615UL) - (-2147483647LL - 1) * (int64_t)(-2147483647LL - 1);

    if (combined_accu > threshold || i + 2 >= n) {
        accu0 >>= nz;
        accu1 >>= nz;
        accu2 >>= nz;
        accu3 >>= nz;

        uint64_t dynamic_threshold = ((18446744073709551615UL) - accu) >> 2;
        while ((accu0 | accu1 | accu2 | accu3) > dynamic_threshold) {
            accu0 >>= 1;
            accu1 >>= 1;
            accu2 >>= 1;
            accu3 >>= 1;
            accu >>= 1;
            nz++;
            dynamic_threshold = ((18446744073709551615UL) - accu) >> 2;
        }
        accu += accu0 + accu1 + accu2 + accu3;
        accu0 = accu1 = accu2 = accu3 = 0;
    }
}
}
