#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern size_t mtop;
extern unsigned long carry;
extern unsigned long *rp;
extern unsigned long *tp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step;
    for (i = 0; i < mtop; i++) {
        rp[i] = carry ? tp[i] : rp[i];
        for (step = 0; step < 3; step++) {
            ((volatile unsigned long *)tp)[i] ^= (1UL << step);
        }
    }
}
