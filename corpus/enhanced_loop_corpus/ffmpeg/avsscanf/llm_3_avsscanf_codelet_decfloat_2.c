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
    int indices[2];
    for (i = 0; i < 2; i++) {
        indices[i] = (a + i) & 127;
    }
    for (i = 0; i < 2; i++) {
        k = indices[i];
        if (k == z || x[k] < th[i]) {
            i = 2;
            break;
        }
        if (x[indices[i]] > th[i])
            break;
    }
    if (i == 2 && rp == 18)
        return;
    if (rp > 27)
        sh = 9;
    e2 += sh;
    int access_pattern[128];
    int len = 0;
    for (int temp = a; temp != z; temp = (temp + 1) & 127) {
        access_pattern[len++] = temp;
    }
    for (int j = 0; j < len; j++) {
        int k = access_pattern[j];
        uint32_t tmp = x[k] & ((1U << sh) - 1);
        x[k] = (x[k] >> sh) + carry;
        carry = (1000000000U >> sh) * tmp;
        if (k == a && !x[k]) {
            a = (a + 1) & 127;
            i--;
            rp -= 9;
        }
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
