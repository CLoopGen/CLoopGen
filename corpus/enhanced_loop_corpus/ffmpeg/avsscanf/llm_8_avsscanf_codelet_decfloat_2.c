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
    int sh = 1;
    for (i = 0; i < 4; i++) {  // Increased trip count to increase computational intensity
        k = (a + i & (128 - 1));
        if (k == z || x[k] < th[i % 2]) {
            i = 4;
            break;
        }
        if (x[a + i & (128 - 1)] > th[i % 2])
            break;
    }
    if (i == 4 && rp == 9 * 2)
        break;
    if (rp > 9 + 9 * 2)
        sh = 16;  // Increased shift width to amplify arithmetic impact
    e2 += sh;
    for (k = a; k != z; k = (k + 1 & (128 - 1))) {
        uint32_t tmp = x[k] & ((1U << sh) - 1);
        x[k] = (x[k] >> sh) + carry;
        carry = ((uint64_t)1000000000 >> sh) * tmp;  // Use wider operand to allow larger shifts
        if (k == a && !x[k]) {
            a = (a + 1 & (128 - 1));
            i--;
            rp -= 9;
        }
    }
    if (carry) {
        if ((z + 1 & (128 - 1)) != a) {
            x[z] = carry;
            z = (z + 1 & (128 - 1));
        } else
            x[z - 1 & (128 - 1)] |= 1;
    }
}
}
