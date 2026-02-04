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
    // Variant 1: Consecutive forward traversal using an index remapped via modulo arithmetic
    // The original backward circular traversal is transformed into a forward one by reversing the indexing logic.
    int start = (z - 1) & (128 - 1);
    int current = start;
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
        current = (current + 1) & (128 - 1); // Forward traversal with wrap-around
    } while (current != a);
}
