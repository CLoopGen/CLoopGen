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
for (i = 0 , mask = 0 - borrow , carry = 0; i < mtop; i += 2) {
    size_t idx1 = i;
    size_t idx2 = i + 1;
    if (idx1 < mtop) {
        ta = ((ap[idx1] & mask) + carry) & (18446744073709551615UL);
        carry = (ta < carry);
        rp[idx1] = (rp[idx1] + ta) & (18446744073709551615UL);
        carry += (rp[idx1] < ta);
    }
    if (idx2 < mtop) {
        ta = ((ap[idx2] & mask) + carry) & (18446744073709551615UL);
        carry = (ta < carry);
        rp[idx2] = (rp[idx2] + ta) & (18446744073709551615UL);
        carry += (rp[idx2] < ta);
    }
}
}
