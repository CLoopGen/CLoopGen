#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int k;
extern int a;
extern int z;
extern uint32_t carry;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 3 (mod 128) to create non-unit stride pattern
    // This changes the access pattern from sequential to strided, still ensuring all relevant elements are eventually visited.
    // We maintain progress toward termination by tracking full cycle via a counter to avoid infinite loops.
    int start = (z - 1) & (128 - 1);
    int current = start;
    int stride = 3; // Stride step
    int count = 0;
    const int max_iterations = 128; // Prevent infinite looping in case of bad stride alignment

    do {
        uint64_t tmp = ((uint64_t)x[current] << 29) + carry;
        if (tmp > 1000000000) {
            carry = tmp / 1000000000;
            x[current] = tmp % 1000000000;
        } else {
            carry = 0;
            x[current] = tmp;
        }
        if (current == start && current != a && !x[current])
            z = current;
        current = (current - stride) & (127); // Apply strided backward jump with mask for mod 128
        count++;
    } while (current != a && count < max_iterations);
}
