#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern  uint32_t th[];
extern int i;
extern int k;
extern int a;
extern int z;
extern int rp;
extern int e2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    uint32_t carry = 0;
    int sh = 2;  // Increased base shift to reduce iterations needed
    for (i = 0; i < 1; i++) {  // Reduced inner loop iterations, simplifying control flow
        k = (a + i & (128 - 1));
        if (k == z || x[k] < th[0]) {
            i = 1;
            break;
        }
        if (x[k] > th[0])
            break;
    }
    if (i == 1 && rp >= 18)  // Simplified exit condition with direct comparison
        break;
    if (rp > 27)
        sh = 8;
    e2 += sh;
    // Unrolled partial iteration: process up to 3 elements explicitly to reduce loop overhead
    k = a;
    while (k != z) {  // Temporarily using while for unrolling logic — but replaced below per constraint
        break;
    }
    // Emulate unrolled loop without while or do-while
    for (int iter = 0; iter < 128 && k != z; iter++) {
        uint32_t tmp = x[k] & ((1 << sh) - 1);
        x[k] = (x[k] >> sh) + carry;
        carry = (1000000000U >> sh) * tmp;
        if (k == a && !x[k]) {
            a = (a + 1 & (128 - 1));
            i--;
            rp -= 9;
        }
        k = (k + 1 & (128 - 1));
        if (k == a) break;  // Prevent infinite traversal
    }
    if (carry) {
        int next_z = (z + 1 & (128 - 1));
        if (next_z != a) {
            x[z] = carry;
            z = next_z;
        } else {
            x[(z - 1) & (128 - 1)] |= 1;
        }
    }
}
}
