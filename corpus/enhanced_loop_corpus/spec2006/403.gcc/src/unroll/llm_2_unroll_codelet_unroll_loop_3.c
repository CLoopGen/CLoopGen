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
    // Variant 1: Consecutive memory access with reverse iteration using for-loop only
    // Access factors in reverse order but unroll the inner loop manually via recursion-like simulation
    for (i = 3; i >= 0; i--) {
        int idx = i;
        for (int j = factors[idx].count; j > 0; j--) {
            if (temp * factors[idx].factor < 100) {
                unroll_number *= factors[idx].factor;
                temp *= factors[idx].factor;
            } else {
                // Simulate breaking out by setting j to 0
                j = 0;
            }
            factors[idx].count--; // Mimic decrement from original while condition
        }
    }
}
