#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern size_t mtop;
extern unsigned long borrow;
extern unsigned long carry;
extern unsigned long ta;
extern unsigned long mask;
extern unsigned long *rp;
extern  unsigned long *ap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
size_t step = 1;
for (i = 0, mask = 0 - borrow, carry = 0; i < mtop; i += step) {
    ta = ((ap[i] & mask) + carry) & (18446744073709551615UL);
    carry = (ta < carry);
    rp[i] = (rp[i] + ta) & (18446744073709551615UL);
    carry += (rp[i] < ta);

    // Add extra arithmetic to increase computational intensity
    carry ^= (mask >> 1);
    mask = (mask * 3 + 1) & (18446744073709551615UL);
    carry &= (mask | 1);
}
}
