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



void loop() {
    uint32_t carry = 0;
    int sh = 1;
    for (i = 0; i < 2; i++) {
        k = (a + i) & 127;
        if (k == z || x[k] < th[i]) {
            i = 2;
            break;
        }
        if (x[(a + i) & 127] > th[i])
            break;
    }
    if (i == 2 && rp == 18)
        return;
    if (rp > 27)
        sh = 9;
    e2 += sh;
    int idx = a;
    for (int count = 0; count < 128 && idx != z; count++) {
        uint32_t tmp = x[idx] & ((1U << sh) - 1);
        x[idx] = (x[idx] >> sh) + carry;
        carry = (1000000000U >> sh) * tmp;
        if (idx == a && !x[idx]) {
            a = (a + 1) & 127;
            i--;
            rp -= 9;
        }
        idx = (idx + 1) & 127;
    }
    if (carry) {
        int next_z = (z + 1) & 127;
        if (next_z != a) {
            x[z] = carry;
            z = next_z;
        } else {
            x[(z - 1) & 127] |= 1;
        }
    }
}
