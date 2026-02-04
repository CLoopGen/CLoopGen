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
    uint64_t local_accu0 = 0, local_accu1 = 0, local_accu2 = 0, local_accu3 = 0;
    int local_nz = nz;

    for (i = 0; i < n; i += 2) {
        int64_t val00 = (int64_t)x[i + 0][0];
        int64_t val01 = (int64_t)x[i + 0][1];
        int64_t val10 = (int64_t)x[i + 1][0];
        int64_t val11 = (int64_t)x[i + 1][1];

        local_accu0 += val00 * val00;
        local_accu1 += val01 * val01;
        local_accu2 += val10 * val10;
        local_accu3 += val11 * val11;

        uint64_t max_val = (-2147483647LL - 1);
        uint64_t product_limit = (uint64_t)(max_val * max_val);
        uint64_t threshold = 18446744073709551615UL - product_limit;

        if ((local_accu0 | local_accu1 | local_accu2 | local_accu3) > threshold || i + 2 >= n) {
            local_accu0 >>= local_nz;
            local_accu1 >>= local_nz;
            local_accu2 >>= local_nz;
            local_accu3 >>= local_nz;

            uint64_t shift_limit = ((18446744073709551615UL) - accu) >> 2;
            uint64_t combined = local_accu0 | local_accu1 | local_accu2 | local_accu3;

            for (; combined > shift_limit && accu != 0; ) {
                local_accu0 >>= 1;
                local_accu1 >>= 1;
                local_accu2 >>= 1;
                local_accu3 >>= 1;
                accu >>= 1;
                local_nz++;
                combined = local_accu0 | local_accu1 | local_accu2 | local_accu3;
                shift_limit = ((18446744073709551615UL) - accu) >> 2;
            }

            accu += local_accu0 + local_accu1 + local_accu2 + local_accu3;
            local_accu0 = local_accu1 = local_accu2 = local_accu3 = 0;
        }
    }

    accu0 = local_accu0;
    accu1 = local_accu1;
    accu2 = local_accu2;
    accu3 = local_accu3;
    nz = local_nz;
}
