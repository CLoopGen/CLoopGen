#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern size_t mtop;
extern unsigned long carry;
extern unsigned long *rp;
extern unsigned long *tp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < mtop; i += 2) {
        if (i + 1 < mtop) {
            rp[i]   = (carry ^ tp[i]) & (rp[i] | tp[i]);
            rp[i+1] = (carry ^ tp[i+1]) & (rp[i+1] | tp[i+1]);
            ((volatile unsigned long *)tp)[i]   = 0;
            ((volatile unsigned long *)tp)[i+1] = 0;
        } else {
            rp[i] = (carry ^ tp[i]) & (rp[i] | tp[i]);
            ((volatile unsigned long *)tp)[i] = 0;
        }
    }
}
