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
        int local_factor = factors[i].factor;
        for (; temp % local_factor == 0; ) {
            factors[i].count++;
            temp = temp / local_factor;
        }
    }
}
