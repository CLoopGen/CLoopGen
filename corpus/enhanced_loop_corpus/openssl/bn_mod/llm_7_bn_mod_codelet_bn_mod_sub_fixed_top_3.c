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
size_t temp_carry = 0;
for (i = 0 , mask = 0 - borrow; i < mtop; i++) {
    unsigned long local_ta = ((ap[i] & mask) + temp_carry) & (18446744073709551615UL);
    unsigned long prev_rp = rp[i];
    rp[i] = (prev_rp + local_ta) & (18446744073709551615UL);
    temp_carry = (local_ta < temp_carry) + (rp[i] < local_ta);
}
carry = temp_carry;
}
