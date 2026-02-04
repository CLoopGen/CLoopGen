#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern size_t mtop;
extern unsigned long carry;
extern unsigned long *rp;
extern unsigned long *tp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < mtop; j++) {
        size_t idx = j;
        rp[idx] = (carry & tp[idx]) | (~carry & rp[idx]);
        ((volatile unsigned long *)tp)[idx] = 0;
    }
}
