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
    for (i = 3; i >= 0; i--) {
        int local_count = factors[i].count;
        unsigned long local_temp = temp;
        int local_unroll = unroll_number;

        for (int j = 0; j < local_count; j++) {
            if (local_temp * factors[i].factor < 100) {
                local_unroll *= factors[i].factor;
                local_temp *= factors[i].factor;
            } else {
                break;
            }
        }

        temp = local_temp;
        unroll_number = local_unroll;
    }
}
