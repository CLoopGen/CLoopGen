#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern size_t mtop;
extern unsigned long carry;
extern unsigned long *rp;
extern unsigned long *tp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (mtop > 0) {
        i = 0;
        for (size_t step = mtop; step > 0; step >>= 1) {
            if (i < mtop) {
                rp[i] = (carry & tp[i]) | (~carry & rp[i]);
                ((volatile unsigned long *)tp)[i] = 0;
                i++;
            }
        }
    }
}
