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
    // Variant 2: Strided memory access pattern using indirect indexing
    // Instead of direct i indexing, use a strided and offset access pattern
    // Here we simulate a non-unit stride by accessing every element through a modified index
    int stride = 2;
    int base_offset = 3;
    // Use a single loop with transformed indices to cover all valid factor entries
    for (int step = 0; step < 4; step++) {
        int i = base_offset - step; // Reverse access: 3,2,1,0
        int idx = i & 3;            // Apply modulo-based indirect addressing (simulates irregular access)
        int local_count = factors[idx].count;

        // Unroll the count down manually without while
        for (int k = 0; k < local_count; k++) {
            if (temp * factors[idx].factor < 100) {
                unroll_number *= factors[idx].factor;
                temp *= factors[idx].factor;
                factors[idx].count--;
            } else {
                // Break early by adjusting k to exit loop
                k = local_count;
            }
        }
    }
}
