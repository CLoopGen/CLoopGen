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
    // Variant 2: Indirect memory access using an index array (simulated via alternating pattern)
    // Simulating indirect access by using a precomputed access pattern: even indices forward, odd backward
    size_t *indices = (size_t*)__builtin_alloca(mtop * sizeof(size_t));
    for (size_t j = 0; j < mtop; j++) {
        indices[j] = (j % 2 == 0) ? j : mtop - 1 - j;  // Example non-consecutive, indirect-like pattern
    }

    for (i = 0, mask = 0 - borrow, carry = 0; i < mtop; i++) {
        size_t idx = indices[i];
        ta = ((ap[idx] & mask) + carry) & (18446744073709551615UL);
        carry = (ta < carry);
        rp[idx] = (rp[idx] + ta) & (18446744073709551615UL);
        carry += (rp[idx] < ta);
    }
}
