#include <stdio.h>

#include <inttypes.h>

struct _factor {
    const int factor;
    int count;
};


extern struct _factor factors[4];
extern int i;
extern unsigned long temp;
extern int unroll_number;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned long local_temp = temp;
    int local_unroll = unroll_number;

    for (i = 3; i >= 0; i--) {
        int factor_val = factors[i].factor;
        int count_val = factors[i].count;

        for (int j = 0; j < count_val && (local_temp * factor_val < 100); j++) {
            local_unroll *= factor_val;
            local_temp *= factor_val;
        }
    }

    temp = local_temp;
    unroll_number = local_unroll;
}
