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
    for (i = 0; i < 4; i++) {
        int factor_val = factors[i].factor;
        int local_count = factors[i].count;
        for (int j = 0; j < local_count && temp * factor_val < 100; j++) {
            unroll_number *= factor_val;
            temp *= factor_val;
        }
    }
}
