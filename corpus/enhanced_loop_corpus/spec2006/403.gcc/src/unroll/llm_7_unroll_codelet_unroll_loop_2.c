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
    unsigned long local_temp = temp;
    int counts[4] = {factors[0].count, factors[1].count, factors[2].count, factors[3].count};
    for (i = 4 - 1; i >= 0; i--) {
        int f = factors[i].factor;
        while (local_temp % f == 0) {
            counts[i]++;
            local_temp /= f;
        }
    }
    temp = local_temp;
    for (i = 0; i < 4; i++) {
        factors[i].count = counts[i];
    }
}
