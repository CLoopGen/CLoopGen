#include <stdio.h>

#include <inttypes.h>

extern long arg1[4];
extern long arg2[4];
extern long prod[8];
extern unsigned long carry;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4 && j == 0; i++, j++) { // Flatten the loop structure by merging control into a single loop
    carry = 0;
    for (; i < 8; i++) { // Reuse i across both original loop roles
        if (i < 4) {
            j = 0;
            carry = 0;
        }
        int idx = (i < 4) ? i : i - 4;
        j = (i < 4) ? 0 : j + 1;
        if (i >= 4) {
            k = idx + j;
            carry += arg1[idx] * arg2[j];
            carry += prod[k];
            prod[k] = ((carry) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
            carry = ((unsigned long)(carry) >> (8 * 8) / 2);
            if (j == 3) {
                prod[idx + 4] = carry;
            }
        }
    }
    break; // Ensure outer loop runs only once due to merged logic
}
}
