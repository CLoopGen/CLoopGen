#include <stdio.h>

#include <inttypes.h>

struct _factor {
    const int factor;
    int count;
};


extern struct _factor factors[4];
extern int i;
extern unsigned long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 4 - 1; i >= 0; i--) {
        int local_count = factors[i].count;
        unsigned long local_temp = temp;
        for (; local_temp % factors[i].factor == 0; ) {
            local_count++;
            local_temp /= factors[i].factor;
        }
        factors[i].count = local_count;
        temp = local_temp;
    }
}
