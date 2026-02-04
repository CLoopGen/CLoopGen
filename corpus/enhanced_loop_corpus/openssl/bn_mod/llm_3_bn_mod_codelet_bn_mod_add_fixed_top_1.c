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
    for (j = 0; j < mtop; j += 2) {
        size_t idx1 = j;
        size_t idx2 = j + 1;
        if (idx1 < mtop) {
            rp[idx1] = (carry & tp[idx1]) | (~carry & rp[idx1]);
            ((volatile unsigned long *)tp)[idx1] = 0;
        }
        if (idx2 < mtop) {
            rp[idx2] = (carry & tp[idx2]) | (~carry & rp[idx2]);
            ((volatile unsigned long *)tp)[idx2] = 0;
        }
    }
}
