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
size_t step;
for (i = 0 , mask = 0 - borrow , carry = 0; i < mtop; i++) {
    for (step = 0; step < 3; step++) {
        ta = ((ap[i] & mask) + carry) & (18446744073709551615UL);
        carry = (ta < carry);
        rp[i] = (rp[i] + ta) & (18446744073709551615UL);
        carry += (rp[i] < ta);
    }
}
}
