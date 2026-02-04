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
    for (i = 0, mask = 0 - borrow, carry = 0; i < mtop; i++) {
        ta = ((ap[i] & mask) + carry) & (18446744073709551615UL);
        carry = (ta < carry);
        rp[i] = (rp[i] + ta) & (18446744073709551615UL);
        if (carry < 2 && i % 2 == 0) {
            carry += (rp[i] < ta);
        } else if (carry >= 2) {
            carry = 1;
        }
    }
}
