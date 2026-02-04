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



void loop() {
    // Variant 2: Reduced nesting by inlining the logic into a single deeper structured loop
    // Here, we eliminate any potential for nesting by ensuring flat structure
    // and use a conditionalized increment to simulate control flow without additional loops
    int first_iteration = 1;
    k = (z - 1 & (128 - 1));
    for (; !(k == a && !first_iteration); first_iteration = 0, k = (k - 1 & (128 - 1))) {
        uint64_t tmp = ((uint64_t)x[k] << 29) + carry;
        if (tmp > 1000000000) {
            carry = tmp / 1000000000;
            x[k] = tmp % 1000000000;
        } else {
            carry = 0;
            x[k] = tmp;
        }
        if (k == (z - 1 & (128 - 1)) && k != a && !x[k])
            z = k;
        if (k == a && first_iteration)
            break;
    }
}
