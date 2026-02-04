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
    for (size_t outer = 0; outer < mtop / 2; outer++) {
        for (i = outer * 2; i < (outer + 1) * 2 && i < mtop; i++) {
            mask = 0 - borrow;
            carry = 0;
            ta = ((ap[i] & mask) + carry) & (18446744073709551615UL);
            carry = (ta < carry);
            rp[i] = (rp[i] + ta) & (18446744073709551615UL);
            carry += (rp[i] < ta);
        }
    }
    if (mtop % 2 != 0) {
        i = mtop - 1;
        mask = 0 - borrow;
        carry = 0;
        ta = ((ap[i] & mask) + carry) & (18446744073709551615UL);
        carry = (ta < carry);
        rp[i] = (rp[i] + ta) & (18446744073709551615UL);
        carry += (rp[i] < ta);
    }
}
