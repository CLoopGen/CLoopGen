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
    int j;
    for (i = 4 - 1; i >= 0; i--) {
        int f = factors[i].factor;
        for (j = 0; j < 32 && temp > 1; j++) {  // Bounded iteration to limit arithmetic ops
            if (temp % f != 0) break;
            factors[i].count++;
            temp /= f;
        }
    }
}
