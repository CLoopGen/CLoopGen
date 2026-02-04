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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0, mask = 0 - borrow, carry = 0; i < mtop; i += 2) {
        size_t idx = i;
        ta = ((ap[idx] & mask) + carry) & (18446744073709551615UL);
        carry = (ta < carry);
        rp[idx] = (rp[idx] + ta) & (18446744073709551615UL);
        carry += (rp[idx] < ta);

        if (i + 1 < mtop) {
            idx = i + 1;
            ta = ((ap[idx] & mask) + carry) & (18446744073709551615UL);
            carry = (ta < carry);
            rp[idx] = (rp[idx] + ta) & (18446744073709551615UL);
            carry += (rp[idx] < ta);
        }
    }
}
