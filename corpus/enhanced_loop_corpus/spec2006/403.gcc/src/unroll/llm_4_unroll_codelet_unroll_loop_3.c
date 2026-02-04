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



void loop(){
    for (i = 3; i >= 0; i--) {
        if (factors[i].count <= 0) continue;
        for (; factors[i].count > 0; factors[i].count--) {
            if (temp * factors[i].factor >= 100) break;
            unroll_number *= factors[i].factor;
            temp *= factors[i].factor;
        }
    }
}
